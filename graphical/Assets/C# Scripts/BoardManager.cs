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
    public List<string> TeamName;
    public List<Color> TeamColor;
    private string[] PlayerPrefab = { "Prefabs/Character 0",
        "Prefabs/Character 1", "Prefabs/Character 2",
        "Prefabs/Character 3", "Prefabs/Character 4" };

    private void Start()
    {
        gameObject.transform.position = Vector3.zero;
        Instance = this;
        Players = new List<GameObject>();
        MyMap = gameObject.AddComponent<DrawMap>();
        TeamName = new List<string>();
        TeamColor = new List<Color>();
    }

    private void Update()
    {
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

    public void InitBackground(int x, int y, int z)
    {
        CreateMap();
        Landscape = Instantiate((GameObject)Resources.Load("Prefabs/Terrain"), new Vector3(x, z, y + y / 2), Quaternion.identity);
        Landscape.transform.SetParent(transform);
        MyMap.maxX = MapSizeX;
        MyMap.maxY = MapSizeY;
        MyMap.gridScale = MapScale;
        float landScale = 2 * MapSizeX * MapSizeY;
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

    public Vector3 GetTileCenter(int x, int y)
    {
        Vector3 origin = Vector3.zero;
        origin.x += (MapScale * x) + MapScale / 2 + MyMap.gridOffset.x;
        origin.z += (MapScale * y) + MapScale / 2 + MyMap.gridOffset.z;
        return origin;
    }

    private int ManageTeam(string teamName)
    {
        int i = 0;
        foreach (string team in TeamName)
        {
            if (team == teamName)
                break;
            i++;
        }
        if (!TeamName.Contains(teamName))
            TeamName.Add(teamName);
        return i;
    }

    public Character SpawnCharacter(int x, int y, int id, string teamName)
    {
        int index = ManageTeam(teamName);
        GameObject go = Instantiate((GameObject)Resources.Load(PlayerPrefab[(index > 4 ? 4 : index)]),
            GetTileCenter(x, y), Quaternion.identity) as GameObject;
        go.transform.SetParent(transform);
        Character player = go.AddComponent<Character>();
        if (TeamColor.Count <= index)
            TeamColor.Add(Random.ColorHSV());
        if (index >= 4)
        {
            MeshRenderer ObjectRenderer = go.GetComponent<MeshRenderer>();
            Material ObjectMaterial = new Material(Shader.Find("Standard"))
            {
                color = TeamColor[index]
            };
            ObjectRenderer.material = ObjectMaterial;
            player.CurrentZ = 25;
        }
        player.SetPosition(GetTileCenter(x, y));
        player.Id = id;
        player.TeamName = teamName;
        Players.Add(go);
        return player;
    }
}
