using UnityEngine;
using System.Collections;

public class Player_Movement : MonoBehaviour {

    public TrackingManager Tracker = null;
    public float movementSpeed = 3.0F;
    bool isMainMenu = false;

    void Start()
    {
        if (Application.loadedLevelName == "Menu")
        {
            isMainMenu = true;
        }
    }
 
    void Update () {

        
	}
}
