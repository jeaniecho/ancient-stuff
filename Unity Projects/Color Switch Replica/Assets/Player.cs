using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour {

	public float jumpForce = 10f;

	public Rigidbody2D rb;
	public SpriteRenderer sr;

	public string currentColor;

	public Color colorGreen;
	public Color colorRed;
	public Color colorYellow;
	public Color colorBlue;


	void Start()
	{
		rb.gravityScale = 0;
		SetRandomColor ();
	}

	// Update is called once per frame
	void Update () 
	{

		if(Input.GetButtonDown("Jump") || Input.GetMouseButtonDown(0))
		{
			rb.gravityScale = 3;
			rb.velocity = Vector2.up * jumpForce;
		}
	}

	void OnTriggerEnter2D(Collider2D col)
	{
		if(col.tag == "ColorChanger")
		{
			SetRandomColor ();
			Destroy (col.gameObject);
			return;
		}

		if(col.tag != currentColor)
		{
			Debug.Log ("GAME OVER");
			SceneManager.LoadScene (SceneManager.GetActiveScene ().buildIndex);
		}

		/* 
		if(col.name == "Toggle")
		{
			Debug.Log ("Congratulations!");
			SceneManager.LoadScene ("Complete");
		}
		*/
	}

	void SetRandomColor()
	{
		int index = Random.Range (0, 4);

		switch(index)
		{
		case 0:
			currentColor = "Green";
			sr.color = colorGreen;
			break;

		case 1:
			currentColor = "Red";
			sr.color = colorRed;
			break;

		case 2:
			currentColor = "Yellow";
			sr.color = colorYellow;
			break;

		case 3:
			currentColor = "Blue";
			sr.color = colorBlue;
			break;
		}
	}
}
