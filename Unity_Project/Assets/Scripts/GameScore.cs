using UnityEngine;
using System.Collections;


public class GameScore : MonoBehaviour {

    public float xMax = 10.5F;
    public float xMin = -10.5F;
    public float zMax = 15.6F;
    public float zMin = 5.6F;

    private Quaternion originalRotation = new Quaternion();
    private Vector3 originalLocation = new Vector3();

    public static int currentScore = 0;
    public static int numberOfEnemies = 3;
    public static int maxEnemies = 3;
    float time;
    public int score;
    public GUIText scoreText;
    public Transform target;

	// Use this for initialization
	void Start () 
    {
        time = Time.time;
	}
	
	// Update is called once per frame
	void Update () 
    {
        score = currentScore;
        scoreText.text = "Score: " + score;
        addEnemy();

	}

    void addEnemy()
    {   
        if (numberOfEnemies < maxEnemies)
        {     
            Vector3 randCoor = new Vector3(Random.Range(xMin, xMax), originalLocation.y, Random.Range(zMin, zMax));

            Instantiate(target, randCoor, originalRotation);

            numberOfEnemies++;
        }
    }   
}
