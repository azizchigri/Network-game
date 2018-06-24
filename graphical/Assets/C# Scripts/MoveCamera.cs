using UnityEngine;
using System.Collections;

public class MoveCamera : MonoBehaviour
{

    private static readonly float PanSpeed = 40f;
    private static readonly float ZoomSpeedTouch = 50f;
    private static readonly float ZoomSpeedMouse = 1f;

    private static readonly float[] BoundsX = new float[] { -20f, 10f };
    private static readonly float[] BoundsZ = new float[] { -36f, -8f };
    private static readonly float[] ZoomBounds = new float[] { 20f, 160f };

    private Camera cam;

    private Vector3 lastPanPosition;
    private int panFingerId; // Touch mode only

    private bool wasZoomingLastFrame; // Touch mode only
    private Vector2[] lastZoomPositions; // Touch mode only

    void Awake()
    {
        cam = GetComponent<Camera>();
    }

    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.Translate(new Vector3(ZoomSpeedTouch * Time.deltaTime, 0, 0));
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.Translate(new Vector3(-ZoomSpeedTouch * Time.deltaTime, 0, 0));
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.Translate(new Vector3(0, -ZoomSpeedTouch * Time.deltaTime, 0));
        }
        if (Input.GetKey(KeyCode.UpArrow))
        {
            transform.Translate(new Vector3(0, ZoomSpeedTouch * Time.deltaTime, 0));
        }
        if (Input.GetAxis("Mouse ScrollWheel") != 0f)
        {
            // Check for scrolling to zoom the camera
            float scroll = Input.GetAxis("Mouse ScrollWheel");
            ZoomCamera(scroll, ZoomSpeedMouse);
        }
    }
    void ZoomCamera(float offset, float speed)
    {
        if (offset == 0)
        {
            return;
        }

        cam.fieldOfView = Mathf.Clamp(cam.fieldOfView - (offset * speed), ZoomBounds[0], ZoomBounds[1]);
    }
}
