using UnityEngine;
using System.Collections;

public class player_select_Object : MonoBehaviour {

    void OnCollisionEnter(Collision collision)
    {
        if (gameObject.name == "1_Player_East")
        {
            Application.LoadLevel(3);
        }
        if (gameObject.name == "1_Player_West")
        {
            Application.LoadLevel(4);
        }
        if (gameObject.name == "2_Player_East") 
        {
            Application.LoadLevel(5);
        }
        if (gameObject.name == "2_Player_West")
        {
            Application.LoadLevel(6);
        }
    }
}
