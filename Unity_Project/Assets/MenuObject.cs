using UnityEngine;
using System.Collections;

public class MenuObject : MonoBehaviour {
    
    bool mouseOn = false;

    void Update()
    {
        if (mouseOn == true)
        {

            float scaleX = Mathf.Cos(Time.time) * 0.1F + 1;
            float scaleY = Mathf.Sin(Time.time) * 0.1F + 1;
            renderer.material.SetTextureScale("_MainTex", new Vector2(scaleX, scaleY));
        }
    }

    void OnMouseEnter()
    {
        mouseOn = true;
    }

    void OnMouseExit()
    {
        renderer.material.SetTextureScale("_MainTex", new Vector2(1F, 1F));
        mouseOn = false;
    }

    void OnMouseDown()
    {
        Application.LoadLevel(1);
    }
}
