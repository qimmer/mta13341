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

        if (isMainMenu == false)
        {
            CharacterController controller = GetComponent<CharacterController>();
            Vector3 forward = transform.TransformDirection(Vector3.forward);
            Vector3 left = transform.TransformDirection(Vector3.left);

            float currSpeedVer = movementSpeed * Input.GetAxis("Vertical");
            float currSpeedHor = movementSpeed * Input.GetAxis("Horizontal");
            controller.SimpleMove(forward * currSpeedVer);
            controller.SimpleMove((-1 * left) * currSpeedHor);
        }
        else
        {
            CharacterController controller = GetComponent<CharacterController>();
            Vector3 left = transform.TransformDirection(Vector3.left);
            float currSpeedHor = movementSpeed * Input.GetAxis("Horizontal");
            controller.SimpleMove((-1 * left) * currSpeedHor);
        }
	}
}
