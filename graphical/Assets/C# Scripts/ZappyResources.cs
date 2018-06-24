using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class ZappyResources : MonoBehaviour {

    public int CurrentX { set; get; }
    public int CurrentY { set; get; }

    public void SetPosition(int x, int y)
    {
        CurrentX = x;
        CurrentY = y;
    }
}
