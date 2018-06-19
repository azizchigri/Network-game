using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character : MonoBehaviour
{
    public string TeamName { set; get; }
    public int CurrentX { set; get; }
    public int CurrentY { set; get; }
    public int Level { set; get; }

    public int Id = 0;

    public int[] resources = { 0, 0, 0, 0, 0, 0, 0 };

    public enum Orientation { N = 1, E = 2, S = 3, W = 4}

    public Orientation rotation;

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

    public void ChangeOrientation(Orientation orientation)
    {
        rotation = orientation;
        if (orientation == Orientation.N)
            gameObject.transform.rotation = Quaternion.identity;
        if (orientation == Orientation.E)
            gameObject.transform.rotation = Quaternion.identity;
        if (orientation == Orientation.S)
            gameObject.transform.rotation = Quaternion.identity;
        if (orientation == Orientation.W)
            gameObject.transform.rotation = Quaternion.identity;
    }

}
