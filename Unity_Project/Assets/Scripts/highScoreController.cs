using UnityEngine;
using System.Collections;

public class highScoreController : MonoBehaviour {

    int highScore0;
    int highScore1;
    int highScore2;

    public TextMesh text1;
    public TextMesh text2;
    public TextMesh text3;

	// Update is called once per frame
	void Awake() 
    {
        highScore0 = PlayerPrefs.GetInt("HighScore0");
        highScore1 = PlayerPrefs.GetInt("HighScore1");
        highScore2 = PlayerPrefs.GetInt("HighScore2");

        text1.text = highScore0.ToString();
        text2.text = highScore1.ToString();
        text3.text = highScore2.ToString();
	}
}
