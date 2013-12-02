using UnityEngine;
using System.Collections;

public class playerCollision : MonoBehaviour {

    public int penalty = 1000;
    
    void OnCollisionEnter(Collision collision)
    {
        GameScore.currentScore = GameScore.currentScore - penalty;
    }
}
