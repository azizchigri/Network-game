using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character : MonoBehaviour
{
    public string TeamName { set; get; }
    public int CurrentX { set; get; }
    public int CurrentY { set; get; }

    public int CurrentZ { set; get; }
    public int Level { set; get; }

    public int Id = 0;

    public int[] resources = { 0, 0, 0, 0, 0, 0, 0 };

    public enum Orientation { N = 1, E = 2, S = 3, W = 4}

    public Orientation rotation;

    public Movement move;

    private void Start()
    {
        move = gameObject.AddComponent<Movement>();
        CurrentZ = 0;
    }

    public void SetPosition(int x, int y)
    {
        CurrentX = x;
        CurrentY = y;
    }

    public void SetPosition(Vector3 pos)
    {
        pos.y = CurrentZ;
        gameObject.transform.position = pos;
    }

    public void MoveTo(int x, int y)
    {
        move.target = new Vector3(x, 0, y);
        move.speed = 50F;
        SetPosition(x, y);
    }

    public void MoveTo(Vector3 to)
    {
        move.target = to;
        to.y = CurrentZ;
        move.speed = 50F;
        SetPosition((int)to.x, (int)to.z);
    }

    public void ChangeOrientation(Orientation orientation)
    {
        rotation = orientation;
        if (orientation == Orientation.N)
            gameObject.transform.rotation = Quaternion.Euler(0, 0, 0);
        if (orientation == Orientation.E)
            gameObject.transform.rotation = Quaternion.Euler(0, 90, 0);
        if (orientation == Orientation.S)
            gameObject.transform.rotation = Quaternion.Euler(0, 180, 0);
        if (orientation == Orientation.W)
            gameObject.transform.rotation = Quaternion.Euler(0, 270, 0);
    }

}
