using UnityEngine;
using System.Collections;


public class GUIManager : MonoBehaviour {

    public static int currentScore = 0;
    
    public int score;
    public GUIText scoreText;
    public GUIText timeText;
    int time;

	// Use this for initialization
	void Start () 
    {
	}
	
	// Update is called once per frame
	void Update () 
    {
        time = (int)Time.time;
        timeText.text = "Tid: " + (gameController.gameTime - time);
        scoreText.text = "Score: " + currentScore;
	}

    
}
