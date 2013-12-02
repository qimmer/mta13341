using UnityEngine;
using System.Collections;

public class animation : MonoBehaviour {

	// Use this for initialization
	void Start () {
		animation["throw"].layer = 1;
		animation["walk"].speed = 2.5f;
		animation["throw"].speed = 8f;
	}
	
	// Update is called once per frame
	void Update () {
		
		if (Input.GetAxis("Vertical") != 0 || Input.GetAxis("Horizontal") != 0)
		{
			animation.CrossFade("walk");
		}
		
		else 
		{
			animation.CrossFade("idle");
		}
		
			
			
		if(Input.GetButtonDown ("Fire1"))
			animation.CrossFade("throw");	
		}
	}



