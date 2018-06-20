using UnityEngine;
using UnityEngine.Networking;
using System.Net.Sockets;
using System;

public class Client : MonoBehaviour
{
    public bool isAtStartup = true;
    TcpClient client = null;

    void Update()
    {
        if (isAtStartup)
        {
            if (Input.GetKeyDown(KeyCode.C))
            {
                SetupClient();
            }
        }
    }
    void OnGUI()
    {
        if (isAtStartup)
        {
            GUI.Label(new Rect(2, 50, 150, 100), "Press C for client");
        }
    }

    // Create a client and connect to the server port
    public void SetupClient()
    {
        client = new TcpClient();
        client.Connect("192.168.1.4", 5656);

        isAtStartup = false;
    }

    public void SendData(string msg)
    {
        Byte[] data = System.Text.Encoding.ASCII.GetBytes(msg);
        NetworkStream stream = client.GetStream();
        stream.Write(data, 0, data.Length);
    }

    public string RcvData()
    {
        NetworkStream stream = client.GetStream();
        Byte[] data = new Byte[256];
        String responseData = String.Empty;
        Int32 bytes = stream.Read(data, 0, data.Length);
        responseData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
        return responseData;
    }
}