using UnityEngine;
using System.Collections;
using System;

public class TrackingManager : MonoBehaviour {

    static int _refCount = 0;

	public float RunSpeed = 0.1f;
	public GameObject projectile;
	public float speed = 20.0F;
    public int NumberOfPlayers = 1;
    bool[] playerThrowing;
    Vector3[] playerPositions;
	float[] _lastFire;

	public GameObject[] players;

    private int _lastNumPlayers = 0;

	// Use this for initialization
	void Start () {
        if (_refCount == 0)
            TrackingWrapper.Initialize();

        _refCount++;


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
            TrackingWrapper.SetNumPlayers(0, (uint)NumberOfPlayers);
            playerThrowing = new bool[NumberOfPlayers];
            playerPositions = new Vector3[NumberOfPlayers];
			_lastFire = new float[NumberOfPlayers];

			for( uint i = 0; i < NumberOfPlayers; ++i )
			{
				_lastFire[i] = Time.time;
			}
        }
        _lastNumPlayers = NumberOfPlayers;

        for (uint i = 0; i < (uint)NumberOfPlayers; ++i)
        {
            playerPositions[i] = new Vector3(
                TrackingWrapper.GetPlayerPoitionX(0, i)*12.0f,
                1.5f,
                -TrackingWrapper.GetPlayerPoitionZ(0, i)*27.0f + 19.0f
                );

			playerThrowing[i] = TrackingWrapper.IsPlayerThrowing(0, i) != 0;


			/*if( (playerPositions[i] - players[i].transform.position)
			   .magnitude > 1.0f )*/
			{
				Vector3 direction = (playerPositions[i] - players[i].transform.position);
				direction /= 4.0f;

				players[i].transform.Translate(direction);
			}

			if( playerThrowing[i] && (_lastFire[i]+0.3f) < Time.time )
			{
				_lastFire[i] = Time.time;

				Vector3 offset = new Vector3(0, 4, 0);

				GameObject instantiatedProjectile = Instantiate(projectile,
				                                                players[i].transform.position + offset,
				                                               new Quaternion())
					as GameObject;
				
				instantiatedProjectile.rigidbody.velocity = transform.TransformDirection(new Vector3(0, 0, speed));
			}
        }
	}



}
