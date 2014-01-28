using UnityEngine;
using System.Collections;

public class Enemy : MonoBehaviour {

	public GameObject Bounding_Area = null;
	public Rigidbody SnowBallPrefab;
	public int pointsWorth = 500;
	public bool moving = false;
	public bool throwing = false;

	private float currentSpeed;
    private float mLastThrow;
    private Vector3 originalLocation = new Vector3();
    private Vector3 whereTo = new Vector3();

    void Start()
    {
        GameController controller = GameObject.Find("GameController").GetComponent(typeof(GameController)) as GameController;

		mLastThrow = Time.time;
        originalLocation = getRandomCoord();
		transform.position = originalLocation;
		currentSpeed = controller.EnemyMoveSpeed;
        whereTo = getRandomCoord();
    }


	// Update is called once per frame  
    void Update () 
    {
        Vector3 enemySight = transform.TransformDirection(Vector3.back);
        RaycastHit enemyHit = new RaycastHit();

        //Draw rays on enemy
        Debug.DrawRay(transform.position, enemySight * 20, Color.red);

		if (throwing && Time.time > (mLastThrow + GameController.Singleton.ThrowInterval) )
        {
			int layerMask = 1 << 8;
			
			// This would cast rays only against colliders in layer 8.
			// But instead we want to collide against everything except layer 8. The ~ operator does this, it inverts a bitmask.
			layerMask = ~layerMask;

            if (Physics.Raycast(transform.position, enemySight, out enemyHit, 20, layerMask) )
            {
				if( enemyHit.collider.gameObject.GetComponent(typeof(Player)) != null )
				{
					mLastThrow = Time.time;
					shoot();
				}
			}
        }

        if (moving)
        {
            if (isCloseToCoor(transform.position, whereTo) || whereTo.magnitude < 0.01f )
            {
                whereTo = getRandomCoord();
            }
            else
            {
                transform.position = Vector3.MoveTowards(transform.position, whereTo, currentSpeed);
                
            }
            
        }
	}

    public Vector3 getRandomCoord()
    {
        GameController controller = GameObject.Find("GameController").GetComponent(typeof(GameController)) as GameController;


		if (Bounding_Area == null)
			return new Vector3 ();

		Bounds b = Bounding_Area.renderer.bounds;
        //  Random.seed = 9;       
		Vector3 randCoor = new Vector3(Random.Range(b.min.x,b.max.x), b.center.y - b.extents.y, Random.Range(b.min.z, b.max.z));
        currentSpeed = Random.Range(controller.EnemyMoveSpeed*0.7f, controller.EnemyMoveSpeed*1.3f);

        return randCoor;
    }

    bool isCloseToCoor(Vector3 vecCurr, Vector3 vecTarget)
    {
        float eps = 0.5F;

        float x = vecCurr.x - vecTarget.x;
        float z = vecCurr.z - vecTarget.z;

        if (x < 0)
        {
            x = x * -1;
        }
        if (z < 0)
        {
            z = z * -1;
        }

        if (x <= eps && z <= eps)
        {
            return true;
        }
        else
        {
            return false;   
        }
    }

	public void shoot()
	{
		Rigidbody snowBallObject = Instantiate(SnowBallPrefab,
		                                               transform.position + new Vector3(0,0,-2),
		                                               transform.rotation)
			as Rigidbody;
		
		snowBallObject.rigidbody.velocity = new Vector3 (0, 0, -GameController.Singleton.EnemySnowBallSpeed);
		(snowBallObject.GetComponent(typeof(SnowBall)) as SnowBall).BallLauncher = SnowBall.Launcher.Enemy;
	}
	
	void OnCollisionEnter(Collision collision)
	{   
		if (collision.gameObject.GetComponent(typeof(SnowBall)) != null )
        {
			if( (collision.gameObject.GetComponent(typeof(SnowBall)) as SnowBall).BallLauncher == SnowBall.Launcher.Player )
			{
	            GUIManager.currentScore += pointsWorth;
                EnemySpawner.numberOfEnemies--;
	            Destroy(gameObject);
			}
        }
    }
}
