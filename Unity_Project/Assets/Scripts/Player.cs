using UnityEngine;
using System;
using System.Collections;

public class Player : MonoBehaviour {

	public float SnowBallSpeed = 10.0f;
	public float MinFireInterval = 0.6f;
	public float SpeedEpsilon = 0.01f;
	public int HitPenalty = 1000;

	public int PlayerIndex = 0;
	public Rigidbody SnowBallPrefab;

	private float mLastFire;
	private Vector3 mLastPosition;

	// Use this for initialization
	void Start () {
		animation["throw"].layer = 1;
		animation["walk"].speed = 7f;
		animation["throw"].speed = 8f;
		mLastFire = Time.time;
	}
	
	// Update is called once per frame
	void Update () {
		if (TrackingManager.Singleton == null)
			return;

		if (PlayerIndex >= TrackingManager.Singleton.NumberOfPlayers)
				gameObject.SetActive( false );
		else
			gameObject.SetActive( true);

		// Update position
		mLastPosition = transform.position;
		transform.position = TrackingManager.Singleton.getPlayerPosition (PlayerIndex);

		float speed = (transform.position - mLastPosition).magnitude;

		// Update aniamtion
		if (TrackingManager.Singleton.isPlayerThrowing(PlayerIndex) )
			animation.CrossFade("throw");

		if( speed > SpeedEpsilon )
			animation.CrossFade("walk");
		else
			animation.CrossFade("idle");

		// Throw a bullet if necessary
		if (TrackingManager.Singleton.isPlayerThrowing(PlayerIndex) && (mLastFire + MinFireInterval) < Time.time)
		{
			mLastFire = Time.time;

			Rigidbody snowBallObject = Instantiate(SnowBallPrefab,
			                                       transform.FindChild("bulletSpawn").position,
			                                       new Quaternion ())
				as Rigidbody;
			
			snowBallObject.rigidbody.velocity = new Vector3 (0, 0, SnowBallSpeed);

		}
	}

	// Handle all collisions
	void OnCollisionEnter(Collision collision)
	{
		if (gameObject.name == "1_Player_East")
		{
			PlayerPrefs.SetInt("NumPlayers", 1);
			Application.LoadLevel(2);
		}
		if (gameObject.name == "1_Player_West")
		{
			PlayerPrefs.SetInt("NumPlayers", 1);
			Application.LoadLevel(3);
		}
		if (gameObject.name == "2_Player_East") 
		{
			PlayerPrefs.SetInt("NumPlayers", 2);
			Application.LoadLevel(2);
		}
		if (gameObject.name == "2_Player_West")
		{
			PlayerPrefs.SetInt("NumPlayers", 2);
			Application.LoadLevel(3);
		}

		  
		if (collision.gameObject.GetComponent(typeof(SnowBall)) != null )
		{
			GUIManager.currentScore = GUIManager.currentScore - HitPenalty;
            gameController.lives--;
		}
	}
}
