using UnityEngine;
using System.Collections;

public class rayCast : MonoBehaviour {


	void Update () {
        Vector3 forward = transform.TransformDirection(Vector3.forward);
        RaycastHit myhit = new RaycastHit();

        //Draws the ray in the editor
        Debug.DrawRay(transform.position, forward * 10, Color.green);

        if (Physics.Raycast(transform.position, forward, out myhit, 10))
        {

            if (myhit.collider.name == "CityWest" || myhit.collider.name == "CityEast")
            {
                MenuObject mo = gameObject.GetComponent<MenuObject>();
            }
        }
	}
}
