using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Board : MonoBehaviour {

    private int x = 8;
    private int y = 8;
    public GameObject tilePrefab;
    public Dictionary<int, Tile> tiles = new Dictionary<int, Tile>();

    // Use this for initialization
    void Start () {
        int id = 0;
		for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                GameObject tileObject = (GameObject)Instantiate(tilePrefab);
                Tile tile = tileObject.AddComponent<Tile>();
                tileObject.name = "Tile " + id;
                tileObject.transform.position = new Vector3(i, 0, j);
                if ((i % 2 == 0 && j % 2 != 0) || (j % 2 == 0 && i % 2 != 0))
                    tile.color = new Color(0, 0, 0);
                else
                    tile.color = new Color(1, 1, 1);
                MeshRenderer tileObjectRenderer = tileObject.GetComponent<MeshRenderer>();
                Material tileObjectMaterial = new Material(Shader.Find("Standard"));
                tileObjectMaterial.color = tile.color;
                tileObjectRenderer.material = tileObjectMaterial;
                id++;
            }
        }
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
