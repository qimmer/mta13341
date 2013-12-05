using UnityEngine;
using System.Collections;

public class highScoreController : MonoBehaviour {

    public TextMesh text0;
    public TextMesh text1;
    public TextMesh text2;

    public string input0;
    public string input1;
    public string input2;

	// Update is called once per frame
	void Awake() 
    {      
        text0.text = PlayerPrefs.GetInt(input0).ToString();
        text1.text = PlayerPrefs.GetInt(input1).ToString();
        text2.text = PlayerPrefs.GetInt(input2).ToString();
	}
}
