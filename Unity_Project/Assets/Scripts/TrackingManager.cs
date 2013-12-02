using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class TrackingManager : MonoBehaviour {

    // Editor Properties
	public GameObject OutOfBoundsText;
    public int NumberOfPlayers = 0;
	public GameObject Bounding_Box;
	public float Margin = 0.1f;

	// Intermediate tracking values
    bool[] mPlayerThrowing;
	LinkedList<float>[] mPlayerXs;
	Vector3[] mPlayerPositions;
	float[] mLastFire;
	
	// Internal stuff
    private int mLastNumPlayers = 0;
	private static int sRefCount = 0;
	private static TrackingManager sSingleton = null;

	public static TrackingManager Singleton
	{
		get
		{
			return sSingleton;
		}
	}

	// Exposed final values
	public Vector3 getPlayerPosition(int playerIndex)
	{
		if (playerIndex >= NumberOfPlayers || playerIndex < 0)
		{
			print("Player Index out of bounds!");
			return new Vector3 (0, 0, 0);
		}

		return mPlayerPositions [playerIndex];
	}

	public bool isPlayerThrowing(int playerIndex)
	{
		if (playerIndex >= NumberOfPlayers || playerIndex < 0)
		{
			print("Player Index out of bounds!");
			return false;
		}

		return mPlayerThrowing [playerIndex];
	}

	// Use this for initialization
	void Start () {
		if (sRefCount == 0)
		{
			TrackingWrapper.Initialize ();
			sSingleton = this;
		}

		sRefCount++;

		if( NumberOfPlayers == 0 )
			NumberOfPlayers = PlayerPrefs.GetInt ("NumPlayers", 1);

		mPlayerThrowing = new bool[NumberOfPlayers];
		mPlayerXs = new LinkedList<float>[NumberOfPlayers];
		mPlayerPositions = new Vector3[NumberOfPlayers];
		mLastFire = new float[NumberOfPlayers];
	}

    void OnDestroy()
    {
		sRefCount--;

		if (sRefCount == 0)
		{
			sSingleton = null;
			TrackingWrapper.Shutdown ();
		}
    }

	// Update is called once per frame
	void Update () {
		if (sRefCount <= 0)
			return;

		if (NumberOfPlayers != mLastNumPlayers)
		{
			TrackingWrapper.SetNumPlayers (0, (uint)NumberOfPlayers);
			mPlayerThrowing = new bool[NumberOfPlayers];
			mPlayerXs = new LinkedList<float>[NumberOfPlayers];
			mPlayerPositions = new Vector3[NumberOfPlayers];
			mLastFire = new float[NumberOfPlayers];

			for (uint i = 0; i < NumberOfPlayers; ++i) {
					mLastFire [i] = Time.time;
				mPlayerXs[i] = new LinkedList<float>();
			}
		}

		TrackingWrapper.Update(0);

		mLastNumPlayers = NumberOfPlayers;

		for (uint i = 0; i < (uint)NumberOfPlayers; ++i)
		{
			mPlayerThrowing [i] = false;

			// Check that the player is within the error-margin
			if (Mathf.Abs (TrackingWrapper.GetPlayerPoitionX (0, i)) < 1.0f - Margin &&
			    Mathf.Abs (TrackingWrapper.GetPlayerPoitionZ (0, i)) < 1.0f - Margin && 
			    Mathf.Abs (TrackingWrapper.GetPlayerPoitionZ (0, i)) > Margin )
			{
				OutOfBoundsText.guiText.enabled = false;

				mPlayerXs[i].AddFirst(new LinkedListNode<float>(TrackingWrapper.GetPlayerPoitionX (0, i)));

				// Make sure we can average X-values
				if( mPlayerXs[i].Count > 2 )
				{
					// Calculate smoothed/averaged X coordinate (-1.0 to 1.0)
					float average = 0.0f;
					foreach( float node in mPlayerXs[i] )
					{
						average += node;
					}
					average /= mPlayerXs[i].Count;

					mPlayerXs[i].RemoveLast();

					mPlayerThrowing [i] = TrackingWrapper.IsPlayerThrowing (0, i) != 0;
		
					// Calculate the world position
					Bounds bounds = Bounding_Box.renderer.bounds;

					mPlayerPositions[i] = new Vector3(average * (bounds.extents.x + Margin) + bounds.center.x,
					                               	  bounds.center.y - bounds.extents.y,
					                                  (-TrackingWrapper.GetPlayerPoitionZ(0, i) * 2 + 1) * (bounds.extents.z + Margin) + bounds.center.z);
				}
			}
			else // Display out-of-bounds message!
			{
				OutOfBoundsText.guiText.enabled = true;
			}
		}
	}
}
