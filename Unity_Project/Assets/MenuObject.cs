using UnityEngine;
using System.Collections;

public class MenuObject : MonoBehaviour {
    
    bool mouseOn = false;

    void Update()
    {
        if (mouseOn == true)
        {

            float scaleX = Mathf.Cos(Time.time) * 0.1F + 1.7F;
            float scaleY = Mathf.Sin(Time.time) * 0.1F + 1.7F;
            float rotateX = Mathf.Cos(Time.time);
            float rotateY = Mathf.Sin(Time.time);
            transform.localScale = new Vector3(scaleX, scaleY, 0.3895768F);
            //transform.localRotation = Quaternion.Euler(rotateX, rotateY, 0);
            transform.localRotation = Quaternion.Euler(new Vector3(rotateX, rotateY, 0.3895768F));
        }
    }

    void OnMouseEnter()
    {
        mouseOn = true;
    }

    void OnMouseExit()
    {
        transform.localScale = new Vector3(1.7F, 1.7F, 0.3895768F);
        transform.localRotation = Quaternion.Euler(new Vector3(0, 0, 0));
        mouseOn = false;
    }

    void OnMouseDown()
    {
        Application.LoadLevel(1);
    }
}
