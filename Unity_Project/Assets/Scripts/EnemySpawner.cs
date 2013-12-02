using UnityEngine;
using System.Collections;

public class EnemySpawner : MonoBehaviour {

	public GameObject EnemyPrefab;
	public GameObject EnemyArea;
	public int maxEnemies = 3;
	public float NewEnemyStartInterval = 5.0f;
	public float IntervalFactor = 0.002f;

	private int numberOfEnemies = 0;
	private float mLastSpawnTime;

	// Use this for initialization
	void Start () {
		mLastSpawnTime = Time.time;
	}
	
	// Update is called once per frame
	void Update () {
		if (Time.time > mLastSpawnTime + (NewEnemyStartInterval) && numberOfEnemies < maxEnemies)
		{
			numberOfEnemies++;

			GameObject enemyObject = Instantiate(EnemyPrefab, new Vector3(), new Quaternion()) as GameObject;
			enemyObject.transform.parent = transform;

			Enemy enemy = enemyObject.GetComponent(typeof(Enemy)) as Enemy;
			enemy.Bounding_Area = EnemyArea;
			enemy.MoveSpeed = 0.03f + (float)numberOfEnemies * 0.01f;
			enemy.SnowBallSpeed = 10;


			mLastSpawnTime = Time.time;
		}
	}
}
