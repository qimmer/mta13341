using UnityEngine;
using System.Collections;

public class LightRotate : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		Quaternion q = transform.localRotation;
		q.eulerAngles = new Vector3(q.eulerAngles.x, Mathf.Sin(Time.time) * 20, q.eulerAngles.z);
		transform.localRotation = q;

		Light l = GetComponent<Light>();
		l.color = new Color((Mathf.Cos (Time.time * 2) + 1.0f)/2.0f,
		                                        (Mathf.Cos (Time.time * 1.7f) + 1.0f)/2.0f,
		                                        (Mathf.Cos (Time.time * 1.3f) + 1.0f)/2.0f);
	}
}
