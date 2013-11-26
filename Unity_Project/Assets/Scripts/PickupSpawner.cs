using UnityEngine;
using System.Collections;

public class PickupSpawner : MonoBehaviour {

	public GameObject PickupPrefab;

	float _nextSpawnTime;
	GameObject _lastPickup = null;

	// Use this for initialization
	void Start () {
		_nextSpawnTime = Time.time + Random.value * 10;
	}
	
	// Update is called once per frame
	void Update () {

		if (Time.time > _nextSpawnTime)
		{
			// Set the time to spawn the next pickup
			_nextSpawnTime = Time.time + Random.Range(6.0f, 18.0f);

			// Spawn a new pickup
			GameObject inst = Instantiate(
				PickupPrefab, 
			    new Vector3(
					Random.Range(-11, 11),
				    1,
				    Random.Range(-2, -7)
				),
			    new Quaternion()
			) as GameObject;

			// Scale it
			float scale = Random.value * 6 + 10.5f;
			inst.transform.localScale = new Vector3( scale, scale, scale );

			_lastPickup = inst;
		}

	}
}
