using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class playerController : MonoBehaviour {

    public float speed;
    public Text text;

    private int score = 0;

    private Rigidbody rb;

	// Use this for initialization
	void Start () {
        score = 0;
        rb = GetComponent<Rigidbody>();
        text.text = "Score: " + score;
	}
	
	// Update is called once per frame
	void Update () {
        float hor = Input.GetAxis("Horizontal");
        float ver = Input.GetAxis("Vertical");

        Vector3 direction = new Vector3(hor, 0.0f, ver);

        //gameObject.transform.position += direction * speed;

        rb.AddForce(direction * speed);
	}

    private void OnTriggerEnter(Collider other) {
        Destroy(other.gameObject);
        score++;
        Debug.Log("Score = " + score);
        text.text = "Score: " + score;
    }
}
