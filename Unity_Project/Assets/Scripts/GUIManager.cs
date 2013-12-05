using UnityEngine;
using System.Collections;


public class GUIManager : MonoBehaviour {

    public static int currentScore = 0;
    
    public int score;
    public GUIText scoreText;
    public GUIText timeText;
    public GUITexture GUIlives;

    public Texture heart1;
    public Texture heart2;
    public Texture heart3;
    private int currLives;

	// Use this for initialization
	void Start () 
    {
        currLives = GameController.lives;
	}
	
	// Update is called once per frame
	void Update () 
    {
        if (GameController.Singleton != null)
        {
            timeText.text = "Tid: " + (int)GameController.Singleton.LevelTime;
            
        }
        scoreText.text = "Score: " + currentScore;

        if (GameController.lives != currLives)
        {
            switch (GameController.lives)   
            {
                case 0:            
                    GUIlives.texture = null;
                    break;
                case 1:
                    GUIlives.texture = heart1;
                    break;
                case 2:
                    GUIlives.texture = heart2;
                    break;
                case 3:
                    GUIlives.texture = heart3;
                    break;
            }
        }
	}

    
}
