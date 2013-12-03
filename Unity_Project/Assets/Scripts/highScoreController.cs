using UnityEngine;
using System.Collections;

public class highScoreController : MonoBehaviour {

    int highScore1;
    int highScore2;
    int highScore3;

    public TextMesh text1;
    public TextMesh text2;
    public TextMesh text3;

	// Update is called once per frame
	void Update () 
    {
        highScore1 = PlayerPrefs.GetInt("HighScore1");
        highScore2 = PlayerPrefs.GetInt("HighScore2");
        highScore3 = PlayerPrefs.GetInt("HighScore3");

        text1.text = highScore1.ToString();
        text2.text = highScore2.ToString();
        text3.text = highScore3.ToString();
	}
}
