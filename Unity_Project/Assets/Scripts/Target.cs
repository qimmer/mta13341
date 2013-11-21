using UnityEngine;
using System.Collections;

public class Target : MonoBehaviour {

    public int pointsWorth = 500;
    public bool moving = false;
	
	// Update is called once per frame
	void Update () 
    {
        if (moving)
        {
            //dostuff
        }
	}

    void OnCollisionEnter(Collision collision)
    {
        GameScore.currentScore += pointsWorth;
        Destroy(gameObject);  
    }
}
