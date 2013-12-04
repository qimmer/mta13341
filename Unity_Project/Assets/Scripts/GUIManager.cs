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

    int time;

	// Use this for initialization
	void Start () 
    {
        currLives = gameController.lives;
	}
	
	// Update is called once per frame
	void Update () 
    {
        time = (int)Time.time;
        timeText.text = "Tid: " + (gameController.gameTime - time);
        scoreText.text = "Score: " + currentScore;

        if (gameController.lives != currLives)
        {
            switch (gameController.lives)
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
