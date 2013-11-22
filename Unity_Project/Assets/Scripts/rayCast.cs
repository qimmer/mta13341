using UnityEngine;
using System.Collections;

public class rayCast : MonoBehaviour {

    MenuObject mo;

	void Update () {
        Vector3 forward = transform.TransformDirection(Vector3.forward);
        RaycastHit myhit = new RaycastHit();

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
        }
        else
        {
            mo.rayHit(false);
        }
	}
}
