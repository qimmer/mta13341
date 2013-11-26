using UnityEngine;
using System.Collections;

public class Target : MonoBehaviour {

    public float xMax = 10.5F;
    public float xMin = -10.5F;
    public float zMax = 15.6F;
    public float zMin = 5.6F;
    private float speed = 0.2F;

    public int pointsWorth = 500;

    public bool moving = false;
    public bool throwing = false;
    private bool thrown = false;
    private Quaternion originalRotation = new Quaternion();
    private Vector3 originalLocation = new Vector3();
    private Vector3 whereTo = new Vector3();
    private bool atCoor = false;

    public EnemyFire_Projectile enemy_fire;

    void Start()
    {
        originalRotation = transform.localRotation;
        originalLocation = transform.position;
        whereTo = getRandomCoord();
    }


	// Update is called once per frame  
    void Update () 
    {
        Vector3 enemySight = transform.TransformDirection(Vector3.back);
        RaycastHit enemyHit = new RaycastHit();

        //Draw rays on enemy
        Debug.DrawRay(transform.position, enemySight * 20, Color.red);

        if (throwing)
        {
            if (Physics.Raycast(transform.position, enemySight, out enemyHit, 20) && enemyHit.collider.name.Contains("Player") && !(enemyHit.collider.name == "Target") && !thrown)
            {
                enemy_fire.shoot();
                thrown = true;
            }
            else if (!(Physics.Raycast(transform.position, enemySight, out enemyHit, 20)))
            {
                thrown = false;
            }
        }

        if (moving)
        {
            if (transform.position.y != 1.342062F)
            {
                transform.position = new Vector3(transform.position.x, 1.342062F, transform.position.z);
            }

            if (isCloseToCoor(transform.position, whereTo))
            {
                whereTo = getRandomCoord();
            }
            else
            {
                transform.position = Vector3.MoveTowards(transform.position, whereTo, speed);
                
            }
            
            transform.localRotation = originalRotation;
        }
	}

    Vector3 getRandomCoord()
    {
        //  Random.seed = 9;       
        Vector3 randCoor = new Vector3(Random.Range(xMin ,xMax), originalLocation.y, Random.Range(zMin ,zMax));
        atCoor = false;
        speed = Random.Range(0.1F, 0.3F);

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

    void OnCollisionEnter(Collision collision)
    {   
        if (collision.gameObject.name == "PrefabBullet(Clone)")
        {
            GameScore.currentScore += pointsWorth;
            Destroy(gameObject);
        }
    }
}
