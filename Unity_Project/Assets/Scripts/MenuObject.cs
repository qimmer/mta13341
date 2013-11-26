using UnityEngine;
using System.Collections;

/**
 *@author   Jon Fridrik Jonatansson
 *@version  1.0
 *@since    25.11.13
 */

public class MenuObject : MonoBehaviour {

    public float rotAngle = 4.0F; //Angle of rotation [(-1 * rotAngle) - (1 * rotAngle)]
    public float posZ = 6.0F; // distance the models move towards player
    private bool rayOn = false;  

    //Initial position, rotation and scale
    private Vector3 originalPos = new Vector3();
    private Quaternion originalRotation = new Quaternion();
    private Vector3 focusPos = new Vector3();
    private float movespeed = 0.0F;

    public void rayHit(bool ray)
    {
        rayOn = ray;
    }

    void Start()
    {
        originalPos = transform.localPosition;
        focusPos = new Vector3(originalPos.x, originalPos.y, originalPos.z - posZ);
        originalRotation = transform.localRotation;
    }

    void Update()
    {        
        if (rayOn == true)
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
        if (gameObject.name == "CityEast")
        {
            Application.LoadLevel(2);
        }
        if (gameObject.name == "CityWest")
        {
            Application.LoadLevel(3);
        }
    }
}
