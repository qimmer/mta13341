using UnityEngine;
using System.Collections;

public class rayCast : MonoBehaviour {

<<<<<<< HEAD
    MenuObject mo;
=======
	// Use this for initialization
>>>>>>> 96a1b20057f38fef3789d50c5ea6d019e33eddb0

	void Update () {
        Vector3 forward = transform.TransformDirection(Vector3.forward);

<<<<<<< HEAD
        //Draws the ray in the editor
        Debug.DrawRay(transform.position, forward * 5, Color.green);

        if (Physics.Raycast(transform.position, forward, out myhit, 10))
        {
            if (myhit.collider.name == "CityWest" || myhit.collider.name == "CityEast")
            {
                //mo.rayHit(true);
                mo = myhit.collider.gameObject.GetComponent<MenuObject>();
                mo.rayHit(true);
            }
=======
        if (Physics.Raycast(transform.position, forward, 10))
        {
            Debug.Log("hit");
>>>>>>> 96a1b20057f38fef3789d50c5ea6d019e33eddb0
        }
        else
        {
            mo.rayHit(false);
        }
	}
}
