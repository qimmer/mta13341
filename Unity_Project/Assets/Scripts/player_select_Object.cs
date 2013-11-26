using UnityEngine;
using System.Collections;

public class player_select_Object : MonoBehaviour {

    void OnCollisionEnter(Collision collision)
    {
        if (gameObject.name == "1_Player_East")
        {
			PlayerPrefs.SetInt("NumPlayers", 1);
            Application.LoadLevel(2);
        }
        if (gameObject.name == "1_Player_West")
        {
			PlayerPrefs.SetInt("NumPlayers", 1);
            Application.LoadLevel(3);
        }
        if (gameObject.name == "2_Player_East") 
        {
			PlayerPrefs.SetInt("NumPlayers", 2);
            Application.LoadLevel(2);
        }
        if (gameObject.name == "2_Player_West")
        {
			PlayerPrefs.SetInt("NumPlayers", 2);
            Application.LoadLevel(3);
        }
    }
}
