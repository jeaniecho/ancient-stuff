using UnityEngine;
using UnityEngine.SceneManagement;

public class moving : MonoBehaviour {

	void OnTriggerEnter2D(Collider2D col)
	{
		if(col.name == "Player")
		{
			Debug.Log ("Congratulations!");
			SceneManager.LoadScene ("Complete");
		}
	}
}
