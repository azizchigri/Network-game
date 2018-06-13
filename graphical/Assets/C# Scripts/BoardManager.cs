using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardManager : MonoBehaviour {

    public static BoardManager Instance { set; get; }

    private const float TILE_SIZE = 1.0f;
    private const float TILE_OFFSET = 0.5f;

    private int MapSizeX = 8;
    private int MapSizeY = 8;

    public Character[,] Characters { set; get; }
    public List<GameObject> activeCharacters;

    private void Start()
    {
        Instance = this;
        activeCharacters = new List<GameObject>();
        Characters = new Character[MapSizeX, MapSizeY];
        SpawnCharacter(5, 5);
    }

    private void Update()
    {
        DrawBoard();
       // Characters[5, 5].MoveTo(50, 50);
    }

    private void DrawBoard()
    {
        Vector3 widthLine = Vector3.right * 8;
        Vector3 heigthLine = Vector3.forward * 8;

        for (int i = 0; i <= MapSizeX; i++)
        {
            Vector3 start = Vector3.forward * i;
            Debug.DrawLine(start, start + widthLine);
            for (int j = 0; j <= MapSizeY; j++)
            {
                start = Vector3.right * j;
                Debug.DrawLine(start, start + heigthLine);
            }
        }
    }

    private void SpawnCharacter(int x, int y)
    {
        GameObject go = Instantiate(Character.Prefab,
            GetTileCenter(x, y), Quaternion.identity) as GameObject;
        go.transform.SetParent(transform);
        Characters[x, y] = go.AddComponent<Character>();
        Characters[x, y].SetPosition(x, y);
        activeCharacters.Add(go);
    }

    private void MoveCharacter(int x, int y, int targetX, int targetY)
    {

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
