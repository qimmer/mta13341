using UnityEngine;
using System.Collections;

/**
 *@author   Jon Fridrik Jonatansson
 *@version  1.0
 *@since    25.11.13
 */

public class MenuObject : MonoBehaviour {

	public GameObject SelectingPlayer;

    public float rotAngle = 4.0F; //Angle of rotation [(-1 * rotAngle) - (1 * rotAngle)]
    public float posZ = 6.0F; // distance the models move towards player
	public int LevelToLoad = 1;

    //Initial position, rotation and scale
    private Vector3 originalPos = new Vector3();
    private Quaternion originalRotation = new Quaternion();
    private Vector3 focusPos = new Vector3();
    private float movespeed = 0.0F;


    void Start()
    {
        originalPos = transform.localPosition;
        focusPos = new Vector3(originalPos.x, originalPos.y, originalPos.z - posZ);
        originalRotation = transform.localRotation;
    }

    void Update()
    {        
		Vector3 forward = SelectingPlayer.transform.TransformDirection(Vector3.forward);
		RaycastHit myhit = new RaycastHit();
		
		//Draws the ray in the editor
		Debug.DrawRay(SelectingPlayer.transform.position, forward * 5, Color.green);

		bool isHit = Physics.Raycast (SelectingPlayer.transform.position, forward, out myhit, 10);

		if (isHit)
			isHit = isHit && myhit.collider == this.collider;

		if (isHit)
		{
            if (transform.localPosition.z >= focusPos.z)
            {
                transform.localPosition = new Vector3(transform.localPosition.x, transform.localPosition.y, transform.localPosition.z - (0.04F + movespeed)); // speed of transform
                movespeed = movespeed + 0.003F; //Acceloration of model
            }
            float rotateX = originalRotation.x + (Mathf.Cos(Time.time) * 2.7F);
            float rotateY = originalRotation.y + (Mathf.Sin(Time.time) * 2.7F);
            float rotateZ = originalRotation.z + (Mathf.Cos(Time.time) * 2.7F);

            transform.localRotation = Quaternion.Euler(new Vector3(rotateX, rotateY, rotateZ));
        }
        else
        {
            if (transform.localPosition.z < originalPos.z)
            {
                transform.localPosition = new Vector3(transform.localPosition.x, transform.localPosition.y, transform.localPosition.z + (0.1F));
                
                //continue wiggle while going back to original pos
                float rotateX = originalRotation.x + (Mathf.Cos(Time.time) * 2.7F);
                float rotateY = originalRotation.y + (Mathf.Sin(Time.time) * 2.7F);
                float rotateZ = originalRotation.z + (Mathf.Cos(Time.time) * 2.7F);
                transform.localRotation = Quaternion.Euler(new Vector3(rotateX, rotateY, rotateZ));
            }
            else
            {
                transform.localPosition = originalPos;
                transform.localRotation = originalRotation;
                movespeed = 0.0F;
            }
        }
    }

    void OnCollisionEnter(Collision collision)
    {      
		Application.LoadLevel(LevelToLoad);
    }
}
