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
			if( _lastPickup != null )
				Destroy(_lastPickup);

			_nextSpawnTime = Time.time + Random.Range(3.0f, 10.0f);

			GameObject inst = Instantiate(PickupPrefab, new Vector3(Random.Range(-9, 9),
			                                      1,
			                                      Random.Range(1.5f, -7)),
			                              new Quaternion()) as GameObject;
			float scale = Random.value * 6 + 13.5f;
			inst.transform.localScale = new Vector3( scale, scale, scale );

			_lastPickup = inst;
		}

	}
}
