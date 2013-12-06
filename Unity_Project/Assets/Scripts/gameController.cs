using UnityEngine;
using System.Collections;

public class GameController : MonoBehaviour {

	/*
     * Keeps track of the Rules for the game.
     * e.g. player health, time and sets highscore.
     */

    public static int lives = 3;
    public static float gameTime = 60;
    private string gameMode;
    private float levelStart;
    private int[] currHighscore;

    public static GameController Singleton
    {
        get
        {
            return GameObject.Find("GameController").GetComponent(typeof(GameController)) as GameController;
        }
    }
    
    public float LevelTime
    {
        get 
        {
            if (gameMode.Equals("EasyMode"))
            {
                return Time.time - levelStart;
            }
            else
            {
                return Time.time;
            }
        }
    }

    public float ThrowInterval
    {
        get
        {
            return 0.5f / (LevelTime / 10.0f + 1.0f);
        }
    }

    public float SnowBallSpeed
    {
        get
        {
            return 20.0f * (LevelTime / 10.0f + 1.0f);
        }
    }

    public float EnemyMoveSpeed
    {
        get
        {
            return 0.4f * (LevelTime / 10.0f + 1.0f);
        }
    }

    // Use this for initialization
	void Start () {
        gameMode = PlayerPrefs.GetString("SelectedGameMode");
        currHighscore = new int[3];
        levelStart = Time.time;

        for (int i = 0; i < currHighscore.Length; i++)
        {
            currHighscore[i] = PlayerPrefs.GetInt(gameMode + "HighScore" + i); //returns 0 if empty
        }
	}
	
	// Update is called once per frame
    void Update()
    {
        if (lives <= 0 || LevelTime >= gameTime)
        {
            if (GUIManager.currentScore > currHighscore[2])
            {
                selectionSort(GUIManager.currentScore);

                for (int i = 0; i < currHighscore.Length; i++)
                {
                    PlayerPrefs.SetInt(gameMode + "HighScore" + i, currHighscore[i]);
                } 
            }
            GUIManager.currentScore = 0;
            Application.LoadLevel(0);
        }
    }

    void selectionSort(int currScore)
    {
        int[] tmpArr = new int[currHighscore.Length +1];


        for (int z = 0; z < currHighscore.Length; z++)
        {
            tmpArr[z] = currHighscore[z];
        }
        tmpArr[currHighscore.Length] = currScore;

        int tmp;
        for (int i = 0; i < tmpArr.Length-1; i++)
        {
            for (int j = i+1; j < tmpArr.Length; j++)
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
