using UnityEngine;
using System.Collections;
using System;

public class TrackingManager : MonoBehaviour {

    static int _refCount = 0;

    public int NumberOfPlayers = 1;
    public bool[] playerThrowing;
    public Vector3[] playerPositions;

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
        }
        _lastNumPlayers = NumberOfPlayers;

        for (uint i = 0; i < (uint)NumberOfPlayers; ++i)
        {
            playerPositions[i] = new Vector3(
                TrackingWrapper.GetPlayerPoitionX(0, i),
                0,
                TrackingWrapper.GetPlayerPoitionZ(0, i)
                );
        }
	}
}
