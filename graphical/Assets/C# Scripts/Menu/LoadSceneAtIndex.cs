using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class LoadSceneAtIndex : MonoBehaviour {

    public InputField port;
    public InputField ip;

    private void Start()
    {
    }

    public void LoadByIndex(int sceneIndex)
    {
        if (port.text != "" && ip.text != "")
        {
            if (sceneIndex == 1) {
                Parameters.port = port.text;
                if (ip.text == "localhost")
                    ip.text = "127.0.0.1";
                Parameters.ip = ip.text;
            }
            SceneManager.LoadScene(sceneIndex);
        }
    }
}
