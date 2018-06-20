using UnityEngine;
using UnityEngine.Networking;
using System.Net.Sockets;
using System;

public class Client : MonoBehaviour
{
    public bool isAtStartup = true;
    TcpClient client;
    CommandHandler Handler;
    public int port = 6060;

    private void Start()
    {
        Handler = gameObject.AddComponent<CommandHandler>();
        Handler.transform.SetParent(transform);
        Handler.name = "CommandHandler";
    }

    void Update()
    {
        if (isAtStartup)
        {
            if (Input.GetKeyDown(KeyCode.C))
            {
                SetupClient();
            }
        } else if (client.Connected)
        {
            Handler.CallCommand(RcvData());
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
        client.Connect("192.168.1.4", port);
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
        String responseData = String.Empty;
        if (stream.DataAvailable) {
            Byte[] data = new Byte[256];
            Int32 bytes = stream.Read(data, 0, data.Length);
            responseData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
    }
        return responseData;
    }
}