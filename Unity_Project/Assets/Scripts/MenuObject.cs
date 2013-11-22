using UnityEngine;
using System.Collections;

public class MenuObject : MonoBehaviour {

    public float rotAngle = 4.0F;
    private bool mouseOn = false;
    private float posZ = 0.0F;
    private Vector3 originalPos = new Vector3();
    private Vector3 originalScale = new Vector3();
    private Quaternion originalRotation = new Quaternion();

    public void initScript()
    {
        Debug.Log("initScript()");
        Start();
    }


    void Start()
    {
        originalPos = transform.localPosition;
        originalScale = transform.localScale;
        originalRotation = transform.localRotation;
        Debug.Log("start()");
    }

    void Update()
    {
        if (mouseOn == true)
        {   
            if (this.posZ < 0.11F)
            {
                posZ = posZ + 0.002F;
                transform.localPosition = new Vector3(transform.localPosition.x, transform.localPosition.y, transform.localPosition.z - posZ);
            }

            float scaleX = originalScale.x + (Mathf.Cos(Time.time) * 0.1F + 5.7F);
            float scaleY = originalScale.y + (Mathf.Sin(Time.time) * 0.1F + 5.7F);
            float rotateX = originalRotation.x + (Mathf.Cos(Time.time) * rotAngle - 2);
            float rotateY = originalRotation.y + (Mathf.Sin(Time.time) * rotAngle);
            float rotateZ = originalRotation.z + (Mathf.Cos(Time.time) * rotAngle);
            transform.localScale = new Vector3(scaleX, scaleY, transform.localScale.z);
            transform.localPosition = new Vector3(transform.localPosition.x, transform.localPosition.y, transform.localPosition.z);
            transform.localRotation = Quaternion.Euler(new Vector3(rotateX, rotateY, transform.localRotation.z));
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        Debug.Log(gameObject.name);
        
        if (gameObject.name == "CityEast")
        {
            Application.LoadLevel(2);
        }
        if (gameObject.name == "CityWest")
        {
            Application.LoadLevel(1);
        }
    }

    
    void OnMouseEnter()
    {
        mouseOn = true;
    }

    void OnMouseExit()
    {
        transform.localPosition = originalPos;
        transform.localScale = originalScale;
        transform.localRotation = originalRotation;
        mouseOn = false;
        posZ = 0.0F;
    }    
}
