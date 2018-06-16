using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character : MonoBehaviour
{
    public string TeamName { set; get; }
    public int CurrentX { set; get; }
    public int CurrentY { set; get; }
    public int Level { set; get; }

    public Movement move;

    private void Start()
    {
        move = gameObject.AddComponent<Movement>();
    }

    public void SetPosition(int x, int y)
    {
        CurrentX = x;
        CurrentY = y;
    }

    public void MoveTo(int x, int y)
    {
        move.target = new Vector3(x, 0, y);
        move.speed = 0.5F;
        SetPosition(x, y);
    }

}
