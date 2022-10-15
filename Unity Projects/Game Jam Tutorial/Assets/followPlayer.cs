using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class followPlayer : MonoBehaviour {

    public GameObject player;

    Vector3 distance;

	// Use this for initialization
	void Start () {
        distance = gameObject.transform.position - player.transform.position;
	}
	
	// Update is called once per frame
	void Update () {
        gameObject.transform.position = player.transform.position + distance;
	}
}
