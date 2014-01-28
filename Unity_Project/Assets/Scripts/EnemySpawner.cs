using UnityEngine;
using System.Collections;

public class EnemySpawner : MonoBehaviour {

	public GameObject EnemyPrefab;
	public GameObject EnemyArea;
	public int maxEnemies = 3;
    public int addMaxEnemyInterval = 15;
    private int mCurrAddMaxEnemy;
	public float NewEnemyStartInterval = 5.0f;
	public float IntervalFactor = 0.002f;

	public static int numberOfEnemies = 0;
	private float mLastSpawnTime;

	// Use this for initialization
	void Start () {
        numberOfEnemies = 0;
        mLastSpawnTime = Time.time;
        mCurrAddMaxEnemy = addMaxEnemyInterval;
	}
	
	// Update is called once per frame
	void Update () {
        if ((int) GameController.Singleton.LevelTime == mCurrAddMaxEnemy && GameController.Singleton.LevelTime != null)
        {
            maxEnemies++;
            mCurrAddMaxEnemy += addMaxEnemyInterval; 
        }

        if ((Time.time > mLastSpawnTime + (NewEnemyStartInterval) && numberOfEnemies <= maxEnemies) || numberOfEnemies == 0 )
		{
			numberOfEnemies++;

			GameObject enemyObject = Instantiate(EnemyPrefab, new Vector3(), new Quaternion()) as GameObject;
			enemyObject.transform.parent = transform;

			Enemy enemy = enemyObject.GetComponent(typeof(Enemy)) as Enemy;
			enemy.Bounding_Area = EnemyArea;

			mLastSpawnTime = Time.time;
		}
	}
}
