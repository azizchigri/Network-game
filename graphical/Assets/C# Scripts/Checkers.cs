using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Checkers : MonoBehaviour {

    public Board board;

	// Use this for initialization
	void Start () {
        GameObject boardObject = new GameObject("Board");
        boardObject.transform.parent = transform;
        board = boardObject.AddComponent<Board>();
        board.tilePrefab = (GameObject) Resources.Load("Prefabs/Tile");
	}
	
}
