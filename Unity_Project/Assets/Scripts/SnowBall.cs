using UnityEngine;
using System.Collections;

public class SnowBall : MonoBehaviour {

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
		if (collision.gameObject.GetComponent (typeof(Enemy)) || collision.gameObject.GetComponent (typeof(Player)))
		{
			ParticleSystem particleObject = Instantiate(HitParticles, collision.transform.position, new Quaternion()) as ParticleSystem;
			particleObject.Play();
			Destroy(particleObject.gameObject, 2);
			Destroy (gameObject);
		}
    }

}
