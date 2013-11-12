using UnityEngine;
using System.Collections;

public class Player_Movement : MonoBehaviour {

    public float movementSpeed = 3.0F;
 
    void Update () {

        CharacterController controller = GetComponent<CharacterController>();
        Vector3 forward = transform.TransformDirection(Vector3.forward);
        Vector3 left = transform.TransformDirection(Vector3.left);

        float currSpeed = movementSpeed * Input.GetAxis("Vertical");
        float currSpeed2 = movementSpeed * Input.GetAxis("Horizontal");
        controller.SimpleMove(forward * currSpeed);
        controller.SimpleMove((-1 * left) * currSpeed2);

        

       
	}
}
