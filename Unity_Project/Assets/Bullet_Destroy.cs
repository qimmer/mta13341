using UnityEngine;
using System.Collections;

public class Bullet_Destroy : MonoBehaviour {

    public int lifespan = 5;

	// Update is called once per frame
	void Update () 
    {
        Destroy(gameObject, lifespan);
    }

    void OnCollisionEnter(Collision collision)
    {
        Destroy(gameObject);
    }

}
