using UnityEngine;
using System.Collections;


public class Fire_Projectile : MonoBehaviour {

    public Rigidbody projectile;
    public float speed = 20.0F;

	// Update is called once per frame
	void Update () 
    {
	    if (Input.GetButtonDown("Fire1"))
        {
            Rigidbody instantiatedProjectile = Instantiate(projectile,
                                                           transform.position,
                                                           transform.rotation)
                                                           as Rigidbody;

            instantiatedProjectile.velocity = transform.TransformDirection(new Vector3(0, 0, speed));
        }
	}
}
