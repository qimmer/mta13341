using UnityEngine;
using System.Collections;

public class Pickup : MonoBehaviour {

	public GameObject[] Prefabs;

	// Use this for initialization
	void Start () {
		// Add a random pickup prefab to this pickup handle object
		GameObject pickup = Instantiate( Prefabs[Random.Range (0, Prefabs.Length - 1)]) as GameObject;

		pickup.transform.parent = this.transform;
		pickup.transform.localPosition = new Vector3 (0, 0, 0);
	}
	
	// Update is called once per frame
	void Update () {
		// Rotate the pickup
		Quaternion q = new Quaternion();
		q.eulerAngles = new Vector3 (0, Time.time*60, Mathf.Sin (Time.time*2) * 10);

		transform.localRotation = q;

		// Check if the pickup is near one of the players
		GameObject player1 = GameObject.Find ("Player1");
		GameObject player2 = GameObject.Find ("Player2");

		if( player1 != null )
		{
			if( (player1.transform.position - this.transform.position).magnitude < 2 )
			{
				GUIManager.currentScore += 100;
				Destroy(this.gameObject);
			}

		}

		if( player2 != null )
		{
			if( (player2.transform.position - this.transform.position).magnitude < 2 )
			{
				GUIManager.currentScore += 100;
				Destroy(this.gameObject);
			}
			
		}

	}

}
