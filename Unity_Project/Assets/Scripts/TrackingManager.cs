using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class TrackingManager : MonoBehaviour {

    static int _refCount = 0;

	public float RunSpeed = 0.1f;
	public GameObject projectile, outOfBounds;
	public float speed = 20.0F;
    public int NumberOfPlayers = 1;
	public float OffsetZ = 0.0f;
	public float OffsetY = 0.0f;
	public float RangeX = 20.0f;
	public float RangeZ = 20.0f;

    bool[] playerThrowing;
	LinkedList<float>[] playerXs;
	float[] _lastFire;

	public GameObject[] players;

    private int _lastNumPlayers = 0;

	// Use this for initialization
	void Start () {
        if (_refCount == 0)
            TrackingWrapper.Initialize();

        _refCount++;

		if( NumberOfPlayers == 0 )
			NumberOfPlayers = PlayerPrefs.GetInt ("NumPlayers", 1);
	}

    void OnDestroy()
    {
        _refCount--;

        if (_refCount == 0)
            TrackingWrapper.Shutdown();
    }

	// Update is called once per frame
	void Update () {
        if (_refCount > 0)
            TrackingWrapper.Update(0);

		if (NumberOfPlayers != _lastNumPlayers)
		{
			if( NumberOfPlayers == 2 )
				players[1].SetActive(true);
			else
			{
				if( players.Length > 1 )
					players[1].SetActive(false);
			}

			TrackingWrapper.SetNumPlayers (0, (uint)NumberOfPlayers);
			playerThrowing = new bool[NumberOfPlayers];
			playerXs = new LinkedList<float>[NumberOfPlayers];
			_lastFire = new float[NumberOfPlayers];

			for (uint i = 0; i < NumberOfPlayers; ++i) {
					_lastFire [i] = Time.time;
				playerXs[i] = new LinkedList<float>();
			}
		}
		_lastNumPlayers = NumberOfPlayers;

		for (uint i = 0; i < (uint)NumberOfPlayers; ++i)
		{
			if (Mathf.Abs (TrackingWrapper.GetPlayerPoitionX (0, i)) < 0.8f &&
			    Mathf.Abs (TrackingWrapper.GetPlayerPoitionZ (0, i)) < 0.8f && 
			    Mathf.Abs (TrackingWrapper.GetPlayerPoitionZ (0, i)) > 0.1f )
			{
				outOfBounds.guiText.enabled = false;

				playerXs [i].AddFirst(new LinkedListNode<float>(TrackingWrapper.GetPlayerPoitionX (0, i)));

				if( playerXs[i].Count > 2 )
				{

					float average = 0.0f;
					foreach( float node in playerXs[i] )
					{
						average += node;
					}
					average /= playerXs[i].Count;

					playerXs[i].RemoveLast();

					playerThrowing [i] = TrackingWrapper.IsPlayerThrowing (0, i) != 0;
		
					Vector3 position = new Vector3(average * RangeX,
					                               1.3f + OffsetY,
					                               -TrackingWrapper.GetPlayerPoitionZ (0, i) * RangeZ + OffsetZ);


					players [i].transform.position = position;
								
					if (playerThrowing [i] && (_lastFire [i] + 0.3f) < Time.time)
					{
						_lastFire [i] = Time.time;

						Vector3 offset = new Vector3 (0, 4, 0);

						GameObject instantiatedProjectile = Instantiate (projectile,
						                                                 players [i].transform.FindChild("bulletSpawn").position,
	                                       new Quaternion ()) as GameObject;
			
						instantiatedProjectile.rigidbody.velocity = transform.TransformDirection (new Vector3 (0, 0, speed));

					}
				}
			}
			else // Display out-of-bounds message!
			{
				outOfBounds.guiText.enabled = true;
			}
		}
	}
}
