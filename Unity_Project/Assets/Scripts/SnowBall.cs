using UnityEngine;
using System.Collections;

public class SnowBall : MonoBehaviour {

	public enum Launcher
	{
		Enemy,
		Player
	}

	public Launcher BallLauncher;
    public float Lifespan = 5;
	public ParticleSystem HitParticles;

	private float mSpawnTime;

	void Start()
	{
		mSpawnTime = Time.time;
	}
	// Update is called once per frame
	void Update () 
    {


		if( Time.time > mSpawnTime + Lifespan )
        	Destroy(gameObject);
    }

    void OnCollisionEnter(Collision collision)
    {
		// The type to receive the ball
		System.Type type = typeof(Enemy);

		switch (BallLauncher) {
		case Launcher.Player:
			type = typeof(Enemy);
			break;
		case Launcher.Enemy:
			type = typeof(Player);
			break;
		}

		if (collision.gameObject.GetComponent(type) != null)
		{
			ParticleSystem particleObject = Instantiate(HitParticles, collision.transform.position, new Quaternion()) as ParticleSystem;
			particleObject.Play();
			Destroy(particleObject.gameObject, 2);
			Destroy (gameObject);
		}
    }

}
