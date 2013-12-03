using UnityEngine;
using System.Collections;

public class gameController : MonoBehaviour {

	/*
     * Keeps track of the Rules for the game.
     * e.g. player health, time and sets highscore.
     */

    public static int lives = 3;
    public int gameTime = 60;
    private int currHighscore;

    // Use this for initialization
	void Start () {
        currHighscore = PlayerPrefs.GetInt("HighScore"); //returns 0 if empty
	}
	
	// Update is called once per frame
	void Update () {
        Debug.Log(Time.time);
        if (lives == 0 || Time.time >= gameTime)
        {
            if (GameScore.currentScore > currHighscore)
            {
                PlayerPrefs.SetInt("HighScore", GameScore.currentScore);
            }

            Debug.Log(PlayerPrefs.GetInt("HighScore"));
            Application.LoadLevel(0);
        }
	}


}
