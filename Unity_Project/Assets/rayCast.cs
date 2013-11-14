using UnityEngine;
using System.Collections;

public class rayCast : MonoBehaviour {

	// Use this for initialization

	void Update () {
        Vector3 forward = transform.TransformDirection(Vector3.forward);

        if (Physics.Raycast(transform.position, forward, 10))
        {
            Debug.Log("hit");
        }
	}
}
