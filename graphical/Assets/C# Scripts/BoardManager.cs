using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardManager : MonoBehaviour {

    public static BoardManager Instance { set; get; }


    private const float TILE_SIZE = 1.0f;
    private const float TILE_OFFSET = 0.5f;

    private DrawMap MyMap;
    private GameObject Landscape;
    public float MapScale = 100;
    public int MapSizeX = 10;
    public int MapSizeY = 10;

    public Character[,] Characters { set; get; }
    public List<GameObject> activeCharacters;

    private void Start()
    {
        gameObject.transform.position = Vector3.zero;
        Instance = this;
        activeCharacters = new List<GameObject>();
        Characters = new Character[MapSizeX, MapSizeY];
        SpawnCharacter(5, 5);
        MyMap = gameObject.AddComponent<DrawMap>();
        InitBackground(0, 0, -3);
    }

    private void Update()
    {
        UpdateBackground();
       // Characters[5, 5].MoveTo(50, 50);
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

    private void SpawnCharacter(int x, int y)
    {
      GameObject go = Instantiate((GameObject)Resources.Load("Prefabs/Character"),
            GetTileCenter(x, y), Quaternion.identity) as GameObject;
        go.transform.SetParent(transform);
        go.transform.localScale = new Vector3(5, 5, 5);
        Characters[x, y] = go.AddComponent<Character>();
        Characters[x, y].SetPosition(x, y);
        activeCharacters.Add(go);
    }

    private void DeleteCharacter(int x, int y)
    {
        Character c = Characters[x, y];
        activeCharacters.Remove(c.gameObject);
        Destroy(c.gameObject);
    }

    private Vector3 GetTileCenter(int x, int y)
    {
        Vector3 origin = Vector3.zero;
        origin.x += (TILE_SIZE * x) + TILE_OFFSET;
        origin.z += (TILE_SIZE * y) + TILE_OFFSET;
        return origin;
    }
}
