using UnityEngine;
using System.Collections;

public class GameScore : MonoBehaviour {

    public static int currentScore = 0;
    public int score;

	// Use this for initialization
	void Start () 
    {

	}
	
	// Update is called once per frame
	void Update () 
    {
        score = currentScore;
	}
}
