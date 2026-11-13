using UnityEngine;

public class elementals: MonoBehaviour
{
    public GameObject eat;
    public float Speed;

    void Start()
    {
        InvokeRepeating("Generate", 0, Speed);
    }
    void Generate()
    {
        if (Input.GetMouseButton(0))
        {
            int x = Random.Range(0, Camera.main.pixelWidth);
            int y = Random.Range(0, Camera.main.pixelHeight);

            Vector3 Target = Camera.main.ScreenToWorldPoint(new Vector3(x, y, 0));
            Target.z = 0;

            Instantiate(eat, Target, Quaternion.identity);
        }
    }
}
