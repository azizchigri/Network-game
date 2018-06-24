using UnityEngine;
using UnityEngine.Networking;
using System.Net.Sockets;
using System;

public class Client : MonoBehaviour
{
    TcpClient client;
    CommandHandler Handler;
    int port;
    string ipAddress;
    public bool isAtStartup = true;

    private void Start()
    {
        Handler = gameObject.AddComponent<CommandHandler>();
        Handler.transform.SetParent(transform);
        Handler.name = "CommandHandler";
        SetupClient();
    }

    public void SetPort()
    {
        try
        {
            port = int.Parse(Parameters.port);
        } catch (Exception e)
        {
            Debug.Log(e);
            Quit();
        }
        
    }

    public void SetIp()
    {
        ipAddress = Parameters.ip;
    }

    void Quit()
    {
        Debug.Log("Quit program");
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }

    void Update()
    {
        if (Input.GetKey(KeyCode.Escape) || (!isAtStartup && client == null))
            Quit();
        if (!isAtStartup && client != null && client.Connected)
        {
            Handler.CallCommand(RcvData());
        }
    }

    // Create a client and connect to the server port
    public void SetupClient()
    {
        SetPort();
        SetIp();
        client = new TcpClient();
        try
        {
            client.Connect(ipAddress, port);
            SendData("Graphical\n");
        } catch (SocketException e) {
            Debug.Log(e);
            Quit();
        }
        
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