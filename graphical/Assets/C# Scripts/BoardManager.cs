using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
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

    public Dictionary<int, GameObject> Players;
    public List<string> TeamName;
    public List<Color> TeamColor;
    private string[] PlayerPrefab = { "Prefabs/Character 0",
        "Prefabs/Character 1", "Prefabs/Character 2",
        "Prefabs/Character 3", "Prefabs/Character 4" };

    private Vector3 clickPosition = Vector3.zero;
    public Tile selectedTile = null;
    public Character selectedPlayer = null;

    private Canvas PanelCanvas;
    private GameObject CanvasObject;
    private RectTransform CharPanel;
    private RectTransform TilePanel;

    private void Start()
    {
        gameObject.transform.position = Vector3.zero;
        Instance = this;
        Players = new Dictionary<int, GameObject>();
        MyMap = gameObject.AddComponent<DrawMap>();
        TeamName = new List<string>();
        TeamColor = new List<Color>();
        CanvasObject = Instantiate((GameObject)Resources.Load("Prefabs/Panel"));
        CanvasObject.transform.SetParent(transform);
        Transform tmp = CanvasObject.transform.Find("TilePanel");
        TilePanel = tmp.GetComponent<RectTransform>();
        tmp = CanvasObject.transform.Find("CharacterPanel");
        CharPanel = tmp.GetComponent<RectTransform>();
    }

    private void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            RaycastHit hit;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (Physics.Raycast(ray, out hit, Mathf.Infinity))
            {
                clickPosition = hit.point;
                if (hit.collider.gameObject.name == "Terrain")
                    getTileOnClick();
                else {
                    foreach (KeyValuePair<int, GameObject> entry in Players)
                    {
                        if (hit.collider.gameObject == entry.Value)
                        {
                            DisplayPlayerInventory(entry.Value.GetComponent<Character>());
                        }
                    }
                }
            }
        }
    }

    public void DisplayPlayerInventory(Character player)
    {
        selectedPlayer = player;
        string[] prefabName = { "Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame" };
        CharPanel.gameObject.SetActive(true);
        int i = 0;
        foreach (string name in prefabName)
        {
            Transform tmp = CharPanel.transform.Find(name);
            Text text = tmp.GetComponent<Text>();
            text.text = name + ": " + selectedPlayer.resources[i];
            i++;
        }
        Transform tmp2 = CharPanel.transform.Find("Title");
        Text text2 = tmp2.GetComponent<Text>();
        text2.text = "PLAYER: " + selectedPlayer.Id;
        tmp2 = CharPanel.transform.Find("Level");
        text2 = tmp2.GetComponent<Text>();
        text2.text = "Level: " + selectedPlayer.Level;
        tmp2 = CharPanel.transform.Find("TeamName");
        text2 = tmp2.GetComponent<Text>();
        text2.text = "Team: " + selectedPlayer.TeamName;
    }

    private void getTileOnClick()
    {
        float x = 0, y = 0;
        int MapX, MapY;

        x = ((clickPosition.x - MyMap.gridOffset.x - MapScale / 2) / MapScale);
        y = ((clickPosition.z - MyMap.gridOffset.z - MapScale / 2) / MapScale);
        MapX = (int)Mathf.Round(x);
        MapY = (int)Mathf.Round(y);
        if (MapX >= 0 && MapY >= 0 && MapX < MapSizeX && MapY < MapSizeY)
            selectedTile = Map[MapX, MapY];
        DisplayTileInventory();
    }

    public void DisplayTileInventory()
    {
        if (selectedTile)
        {
            string[] prefabName = { "Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame" };
            TilePanel.gameObject.SetActive(true);
            int i = 0;
            foreach (string name in prefabName) {
                Transform tmp = TilePanel.transform.Find(name);
                Text text = tmp.GetComponent<Text>();
                text.text = name + ": " + selectedTile.resources[i];
                i++;
            }
            Transform tmp2 = TilePanel.transform.Find("Title");
            Text text2 = tmp2.GetComponent<Text>();
            text2.text = "TILE (" + selectedTile.CurrentX + "," + selectedTile.CurrentY + ")";
        }
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
        Landscape.name = "Terrain";
        MyMap.maxX = MapSizeX;
        MyMap.maxY = MapSizeY;
        MyMap.gridScale = MapScale;
        float landScale = 2 * MapSizeX * MapSizeY;
        Landscape.transform.localScale = new Vector3(landScale, 0.13f, landScale);
        var boxCollider2 = Landscape.AddComponent<BoxCollider>();
        boxCollider2.center = Vector3.zero;
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
        } else
        {
            BoxCollider coll = go.AddComponent<BoxCollider>();
            Vector3 newPos = Vector3.zero;
            newPos.y = 30;
            coll.center = newPos;
            newPos.x = 50;
            newPos.y = 100;
            newPos.z = 20;
            coll.size = newPos;
        }
        player.SetPosition(GetTileCenter(x, y));
        player.Id = id;
        player.TeamName = teamName;
        Players[id] = go;
        return player;
    }
}
