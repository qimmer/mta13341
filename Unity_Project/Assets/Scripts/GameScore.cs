using UnityEngine;
using System.Collections;


public class GameScore : MonoBehaviour {

    public float xMax = 10.5F;
    public float xMin = -10.5F;
    public float zMax = 15.6F;
    public float zMin = 5.6F;

    public int spawnTime = 15;
    int currSpawnTime;

    private Quaternion originalRotation = new Quaternion();
    private Vector3 originalLocation = new Vector3();

    public static int currentScore = 0;
    public static int numberOfEnemies = 3;
    public static int maxEnemies = 3;
    public int newEnemyInterval = 3;

    float time;
    public int score;
    public GUIText scoreText;
    public Transform target;

	// Use this for initialization
	void Start () 
    {
        currSpawnTime = spawnTime;
	}
	
	// Update is called once per frame
	void Update () 
    {
        time = Time.time;
        score = currentScore;
        scoreText.text = "Score: " + score;
        addMaxEnemies();
        addEnemy();

	}

    void addEnemy()
    {
        if (numberOfEnemies < maxEnemies && ((int) time % newEnemyInterval == 0))
        {     
            Vector3 randCoor = new Vector3(Random.Range(xMin, xMax), originalLocation.y, Random.Range(zMin, zMax));
            Instantiate(target, randCoor, originalRotation);
            numberOfEnemies++;
        }
    }

    void addMaxEnemies()
    {
        if ((int) time == currSpawnTime)
        {
            maxEnemies++;
            currSpawnTime = currSpawnTime + spawnTime;
        }
    }
}
