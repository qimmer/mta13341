﻿using UnityEngine;
using System.Collections;

public class EnemyFire_Projectile : MonoBehaviour {

    public Rigidbody projectile;
    public float speed = 20.0F;

    public void shoot()
    {
        Rigidbody instantiatedProjectile = Instantiate(projectile,
                                                           transform.position,
                                                           transform.rotation)
                                                           as Rigidbody;

        instantiatedProjectile.velocity = transform.TransformDirection(new Vector3(0, 0, speed));
    }
}
