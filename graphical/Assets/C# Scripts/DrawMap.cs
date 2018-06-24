using UnityEngine;
using System.Collections;

public class DrawMap : MonoBehaviour
{
    // universal grid scale
    public float gridScale = 1f;

    // extents of the grid
    private int minX = 0;
    private int minY = 0;
    public int maxX = 10;
    public int maxY = 10;

    // nudges the whole grid rel
    public Vector3 gridOffset = Vector3.zero;

    public Color gizmoLineColor = Color.black;

    private void Start()
    {
        gameObject.transform.position = Vector3.zero;
    }

    // draw the grid
    void OnDrawGizmos()
    {
        gridOffset.x = -maxX * gridScale/ 2;
        gridOffset.z = -maxY * gridScale / 2;
        // set colours
        Color brightColor = Color.Lerp(Color.black, gizmoLineColor, 0.75f);

        // draw the horizontal lines
        for (int x = minX; x < maxX + 1; x++)
        {
            if (x == 0)
                Gizmos.color = brightColor;

            Vector3 pos1 = new Vector3(x, 0, minY) * gridScale;
            Vector3 pos2 = new Vector3(x, 0, maxY) * gridScale;
            Gizmos.DrawLine((gridOffset + pos1), (gridOffset + pos2));
        }

        // draw the vertical lines
        for (int y = minY; y < maxY + 1; y++)
        {
            if (y == 0)
                Gizmos.color = brightColor;

            Vector3 pos1 = new Vector3(minX, 0, y) * gridScale;
            Vector3 pos2 = new Vector3(maxX, 0, y) * gridScale;
            Gizmos.DrawLine((gridOffset + pos1), (gridOffset + pos2));
        }
    }
}
