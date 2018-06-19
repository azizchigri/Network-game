using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardManager : MonoBehaviour {

    public static BoardManager Instance { set; get; }

    private const float TILE_SIZE = 1.0f;
    private const float TILE_OFFSET = 0.5f;

    public Tile[,] Map { set; get; }
    private DrawMap MyMap;
    private GameObject Landscape;
    public float MapScale = 100;
    public int MapSizeX = 10;
    public int MapSizeY = 10;

    public List<GameObject> Players;
    public string[] TeamName;

    private void Start()
    {
        gameObject.transform.position = Vector3.zero;
        Instance = this;
        Players = new List<GameObject>();
        SpawnCharacter(5, 5, 10);
        MyMap = gameObject.AddComponent<DrawMap>();
        // InitBackground(0, 0, -3);
        CreateMap();
    }

    private void Update()
    {
        //UpdateBackground();
       // Characters[5, 5].MoveTo(50, 50);
    }

    public void SetMapSizeX(int x)
    {
        MapSizeX = x;
        MyMap.maxX = MapSizeX;
    }

    public void SetMapSizeY(int y)
    {
        MapSizeY = y;
        MyMap.maxY = MapSizeY;
    }

    private void CreateMap()
    {
        Map = new Tile[MapSizeX, MapSizeY];
        GameObject MapObject = new GameObject();
        MapObject.transform.SetParent(transform);
        MapObject.name = "Map";
        int id = 1;
        for (int x = 0; x < MapSizeX; x++)
        {
            for (int y = 0; y < MapSizeY; y++)
            {
                GameObject go = new GameObject();
                go.transform.SetParent(MapObject.transform);
                Map[x, y] = go.AddComponent<Tile>();
                Map[x, y].CurrentX = x;
                Map[x, y].CurrentY = y;
                Map[x, y].gameObject.name = "Tile " + id;
                id++;
            }
        }
    }

    private void InitBackground(int x, int y, int z)
    {
        Landscape = Instantiate((GameObject)Resources.Load("Prefabs/Terrain"), new Vector3(x, z, y + y / 2), Quaternion.identity);
        Landscape.transform.SetParent(transform);
        MyMap.maxX = MapSizeX;
        MyMap.maxY = MapSizeY;
        MyMap.gridScale = MapScale;
        float landScale = MyMap.gridScale / 4f;
        Landscape.transform.localScale = new Vector3(landScale, 0.13f, landScale);
    }

    private void UpdateBackground()
    {
        if (MyMap.maxX == MapSizeX && MyMap.maxY == MapSizeY && MyMap.gridScale == MapScale)
            return;
        Destroy(Landscape);
        InitBackground(0, 0, -3);
    }

    private void DrawBoard()
    {
        Vector3 widthLine = Vector3.right * 8;
        Vector3 heigthLine = Vector3.forward * 8;

        for (int i = 0; i <= MapSizeY; i++)
        {
            Vector3 start = Vector3.forward * i;
            Debug.DrawLine(start, start + widthLine);
            for (int j = 0; j <= MapSizeX; j++)
            {
                start = Vector3.right * j;
                start = Vector3.right * j;
                Debug.DrawLine(start, start + heigthLine);
            }
        }
    }

    private Vector3 GetTileCenter(int x, int y)
    {
        Vector3 origin = Vector3.zero;
        origin.x += (TILE_SIZE * x) + TILE_OFFSET;
        origin.z += (TILE_SIZE * y) + TILE_OFFSET;
        return origin;
    }

    public Character SpawnCharacter(int x, int y, int id)
    {
      GameObject go = Instantiate((GameObject)Resources.Load("Prefabs/Character"),
            GetTileCenter(x, y), Quaternion.identity) as GameObject;
        go.transform.SetParent(transform);
        go.transform.localScale = new Vector3(5, 5, 5);
        Character player = go.AddComponent<Character>();
        player.SetPosition(x, y);
        player.Id = id;
        Players.Add(go);
        return player;
    }
}
