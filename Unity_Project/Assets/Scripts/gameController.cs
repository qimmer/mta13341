using UnityEngine;
using System.Collections;

public class gameController : MonoBehaviour {

	/*
     * Keeps track of the Rules for the game.
     * e.g. player health, time and sets highscore.
     */

    public static int lives = 3;
    public static int gameTime = 60;
    private int[] currHighscore;

    // Use this for initialization
	void Start () {
        currHighscore = new int[3];

        for (int i = 0; i < currHighscore.Length; i++)
        {
            currHighscore[i] = PlayerPrefs.GetInt("HighScore" + i); //returns 0 if empty
        }
	}
	
	// Update is called once per frame
	void Update () {
        
        if (lives == 0 || Time.time >= gameTime)
        {
            if (GameScore.currentScore > currHighscore[2])
            {
                sort(GameScore.currentScore);
                for (int i = 0; i < currHighscore.Length; i++)
                {
                    PlayerPrefs.SetInt("HighScore" + i, currHighscore[i]);
                }
                
            }
            Application.LoadLevel(0);
        }
	}

    void sort(int currScore)
    {
        int[] tmpArr = new int[4];

        for (int z = 0; z < currHighscore.Length; z++)
        {
            tmpArr[z] = currHighscore[z];
        }
        tmpArr[3] = currScore;

        int tmp;
        for (int i = 0; i < tmpArr.Length; i++)
        {
            for (int j = 0; j < tmpArr.Length; j++)
            {
                if (tmpArr[i] < tmpArr[j])
                {
                    //swap
                    tmp = tmpArr[j];
                    tmpArr[j] = tmpArr[i];
                    tmpArr[i] = tmp;
                }
            }
        }

        for (int x = 0; x < currHighscore.Length; x++)
        {
            currHighscore[x] = tmpArr[x];
        }
    }


}
