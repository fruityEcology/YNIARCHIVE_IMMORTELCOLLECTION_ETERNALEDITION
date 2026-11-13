using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class PlayerController : MonoBehaviour {

    public float moveForce = 3, boostMultiplier = 2;               // force of movement and boosting's 
    Rigidbody2D myBody;                                          // Player's body 

    private float dist;
    private Vector3 v3Offset;
    private Plane plane;
    public GameObject Player;                                // Player
    public Vector3 Offset;                                   //
    private Vector2 movement;                                // (movement)
    public float energy;                                    //(energy)
    private Vector2 randVec;                             
    private Vector3 vecScale;                             
    public Vector2 mousePosition;                         // (mousePosition)
    public Camera cam;                                      //(Camera) 
    private float camSize;                                  //(Size of Camera)
    private int energyCoini;                               // (Coin of energy)
    public float createenergy;
  
    public float fruityCoini;
    public float inspire;                                 // (energy) 
    public GameObject element;                          //(Creative energy 1 version)  
    public GameObject elementenergy;                        //(Creative energy 2 version)                   
    bool one_click = false;                            // (check of time's click)
    float timer_for_double_click = 0;                  // time for click (double)
    float delay = 0.3f;
    private float quotient;
    private float delta;                           // delta (movement speed of character , whats create by energy mass)                                                  
    public GameObject MainCamera;



    void Start()
    {
        Offset = transform.position - Player.transform.position;            // Player moving 
        vecScale.Set(1, 1, 1);
        Mathf.Pow(energy, Mathf.Log(2, 0.1f));                              //   (//)
        camSize = 120;                                                      // size of Camera
        energy = 111;                                                       // Start energy (might to be == 10 or 1 somethy) 
        myBody = this.GetComponent<Rigidbody2D>();
        createenergy = -7;                                                // Energy expended on creation from Player                    
        inspire = -7;                                                      // Energy from  Player                                       
        energyCoini = 7;                                                   // energy coin's from element's (need to be = 1) 
        fruityCoini = 42;
        delta =  1;                                                        // Start speed (need to be = 1) 
    }
    

    void LateUpdate()
    {                                                                      // Player moving    
        
            transform.position = Player.transform.position + Offset;
        
        
    }          
    
    void Update()
    {
        mousePosition = Input.mousePosition;

        if (Input.GetKeyDown(KeyCode.Mouse0))
        {
            RaycastHit _hit;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (Physics.Raycast(ray, out _hit))
                Instantiate(element, new Vector3(_hit.point.x, _hit.point.y, _hit.point.z), transform.rotation);
        }

        if (energy < 11) {
            Player.transform.position = Vector3.zero;
            energy = 111;
        }

        if (delta > 0) ;                                                                                                                      // if player creating

        {
            energy -= 0.217f; //dissipation of Player's energy
            if (Input.GetMouseButton(0))
            {
                mousePosition = Input.mousePosition;                                                                                          // mouse controlls :
                mousePosition = Camera.main.ScreenToWorldPoint(mousePosition);                                                                  //1.Mouse touches with Camera 
                mousePosition -= (Vector2)transform.position;                                                                                    // 2. Transform Player's position by Vector
                quotient = Mathf.Sqrt(mousePosition.x * mousePosition.x + mousePosition.y * mousePosition.y) / delta;                             //3.Coordinating
                mousePosition /= quotient;                                                                                                         // 4.Coefficient

                transform.Translate(mousePosition * Time.deltaTime);                                                                                // 5.Position by time 
            }
            Mathf.Pow(energy, Mathf.Log(2, 0.1f));                                                                                                   // moving by energy math 
            Input.GetAxis("Horizontal");                   
            Input.GetAxis("Vertical");                                                                                                                //moving in each direction

            vecScale.Set((energy / 200 + 0.95f), (energy / 200 + 0.95f), 1);
            transform.localScale = vecScale;
            
                                                                                                                                    
            
            if (energy < 71)                                                                                                                            //Ballancing 
            {
                energyCoini = 10;
            }
            else
            {
                energyCoini = 7;
            }

            if (Input.GetMouseButtonDown(0))                                                                                                                  
            {
                if (!one_click)
                {
                    one_click = true;
                    timer_for_double_click = Time.time;
                }
                else
                {
                    one_click = false;
                    Spawn();
                }
            }

            if (one_click)
            {
                if ((Time.time - timer_for_double_click) > delay)
                {
                    one_click = false;
                }                                    
            }
            transform.position = Player.transform.position + Offset;

        }

    }

    public void Spawn()                                                                                                                                            //Spawn of energy's by player
    {
        if (energy > 71)
        {
            RaycastHit _hit;                                                    
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);      
            if (Physics.Raycast(ray, out _hit))                                                                                                                       // for camera       
                Instantiate(element, new Vector3(_hit.point.x, _hit.point.y, _hit.point.z), transform.rotation);                                                      // and instantiation 
            {
                if (energy > 7.1)                                
                    if (energy < 701)                      
                                                                                                                                                                                  
                if (delta < 5)                            
                    if (delta > 3)                      
                    {                                  
                        delta += 1;                    
                    }                                
            }
        }
    }                                     
    
    void FixedUpdate()                                                  
    {

        if (energy < 700)                                   
            if (energy > 690)
            {
                delta = 1;
            }
        if (energy < 690)
            if (energy > 680)
            {
                delta = 1.5f;
            }
        if (energy < 680)
            if (energy > 670)
            {
                delta = 2;
            }
        if (energy < 670)
            if (energy > 660)
            {
                delta = 2.5f;
            }
        if (energy < 660)
            if (energy > 650)
            {
                delta = 3;
            }
        if (energy < 650)
            if (energy > 640)
            {
                delta = 3.5f;
            }
        if (energy < 640)
            if (energy > 630)
            {
                delta = 4;
            }
        if(energy < 630)
            if (energy > 620)
        {
            delta = 4.5f;
        }
        if (energy < 620)
            if (energy > 610)
            {
                delta = 5;
            }
        if (energy < 600)
            if (energy > 590)                 
            {
                delta = 5.5f;
            }
        if (energy < 590)
            if (energy > 580)
            {
                delta = 6;
            }
        if (energy < 580)
            if (energy > 570)
            {
                delta = 6.5f;
            }
        if (energy < 570)
            if (energy > 560)
            {
                delta = 7;
            }
        if (energy < 560)
            if (energy > 550)
            {
                delta = 7.5f;
            }
        if(energy < 550)
            if (energy > 540)
        {
            delta = 8;
        }
        if (energy < 540)
            if (energy > 530)
            {
                delta = 8.5f;
            }
        if (energy < 530)
            if (energy > 520)
            {
                delta = 9;
            }
        if (energy < 520)
            if (energy > 510)
            {
                delta = 9.5f;
            }
        if (energy < 510)
            if (energy > 500)
            {
                delta = 10;
            }
        if (energy < 500)
            if (energy > 490)
            {
                delta = 10.5f;
            }
        if (energy < 490)
            if (energy > 480)
            {
                delta = 11;
            }
        if(energy < 480)
            if (energy > 470)
        {
            delta = 11.5f;
        }
        if (energy < 460)
            if (energy > 450)
            {
                delta = 12;
            }
        if (energy < 450)
            if (energy > 440)
            {
                delta = 12.5f;
            }
        if (energy < 440)
            if (energy > 430)
            {
                delta = 13;
            }
        if (energy < 430)
            if (energy > 420)
            {
                delta = 13.5f;
            }
        if (energy < 420)
            if (energy > 410)
            {
                delta = 14;
            }
        if (energy < 410)
            if (energy > 400)
            {
                delta = 14.5f;
            }
        if (energy < 400)
            if (energy > 390)
            {
                delta = 15;
            }
        if (energy < 390)
            if (energy > 380)
            {
                delta = 15.5f;
            }
        if (energy < 380)
            if (energy > 370)
            {
                delta = 16;
            }
        if (energy < 370)
            if (energy > 360)
            {
                delta = 16.5f;
            }
        if (energy < 360)
            if (energy > 350)
            {
                delta = 17;
            }
        if (energy < 350)
            if (energy > 340)
            {
                delta = 17.5f;
            }
        if (energy < 340)
            if (energy > 330)
            {
                delta = 18;
            }
        if (energy < 330)
            if (energy > 320)
            {
                delta = 18.5f;
            }
        if (energy < 320)
            if (energy > 310)
            {
                delta = 19;
            }
        if (energy < 310)
            if (energy > 300)
            {
                delta = 19.5f;
            }
        if (energy < 300)
            if (energy > 290)
            {
                delta = 20;
            }
        if (energy < 290)
            if (energy > 280)
            {
                delta = 20.5f;
            }
        if (energy < 280)
            if (energy > 270)
            {
                delta = 21;
            }
        if (energy < 270)
            if (energy > 260)
            {
                delta = 21.5f;
            }
        if (energy < 260)
            if (energy > 250)
            {
                delta = 22;
            }
        if (energy < 250)
            if (energy > 240)                 
            {
                delta = 22.5f;
            }
        if (energy < 240)
            if (energy > 230)
            {
                delta = 23;
            }
        if (energy < 230)
            if (energy > 220)
            {
                delta = 23.5f;  
            }
        if (energy < 220)
            if (energy > 210)
            {
                delta = 24;
            }
        if (energy < 210)
            if (energy > 200)
            {
                delta = 24.5f;
            }
        if (energy < 200)
            if (energy > 190)
            {
                delta = 25;
            }
        if (energy < 190)
            if (energy > 180)
            {
                delta = 25.5f;
            }
        if (energy < 180)
            if (energy > 170)
            {
                delta = 26;
            }
        if (energy < 170)
            if (energy > 160)
            {
                delta = 26.5f;
            }
        if (energy < 160)
            if (energy > 150)
            {
                delta = 27;
            }
        if (energy < 150)
            if (energy > 140)
            {
                delta = 27.5f;
            }
        if (energy < 140)
            if (energy > 130)
            {
                delta = 28;
            }
        if (energy < 130)
            if (energy > 120)
            {
                delta = 28.5f;
            }
        if (energy < 120)
            if (energy > 110)
            {
                delta = 29;
            }
        if (energy < 110)
            if (energy > 100)
            {
                delta = 29.5f;
            }
        if (energy < 100)
            if (energy > 90)
            {
                delta = 30;
            }
        if (energy < 90)
            if (energy > 80)
            {
                delta = 30.5f;
            }
        if (energy < 80)
            if (energy > 70)
            {
                delta = 31;
            }
        if (energy < 70)
            if (energy > 60)
            {
                delta = 31.5f;
            }
        if (energy < 60)
            if (energy > 50)
            {
                delta = 32;
            }
        if (energy < 50)
            if (energy > 40)
            {
                delta = 32.5f;
            }
        if (energy < 40)
            if (energy > 30)
            {
                delta = 33;
            }
        if (energy < 30)
            if (energy > 20)
            {
                delta = 33.5f;
            }
      

        if (energy < 20)
            if (energy > 7)
            {
                delta = 34;
            }
        if (energy < 7) { delta = 35;}
        
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (energy < 701)                                // Balancing
            if (energy > -0.1)                          // 
            {
                if (col.gameObject.tag == "eat")
                {
                    {
                        {
                            energy += energyCoini;
                            Destroy(col.gameObject);
                            camSize += 0.002f * energyCoini;
                            if (delta > 1)
                                if (delta < 5)
                                {
                                    delta -= 1;
                                }
                        }
                    }
                }     

                if (col.gameObject.tag == "fruityeat")
                {
                    {
                        {
                            energy += fruityCoini;
                            Destroy(col.gameObject);
                            camSize += 0.002f * energyCoini;
                            if (delta > 1)
                                if (delta < 5)
                                {
                                    delta -= 1;
                                }
                        }
                    }
                }
                //
                if (col.gameObject.tag == "frufii")            
                {
                    {
                        {
                            energy -= createenergy;
                            Destroy(col.gameObject);
                            camSize -= 0.002f * energyCoini;
                            if (delta < 5)
                                if (delta > 1)
                                {
                                    delta -= 1;
                                }
                        }
                    }
                }                                         
            }
    }


    void OnMouseDown()
    {
        if (energy > 10)
        {
            RaycastHit _hit;
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (Physics.Raycast(ray, out _hit))
                Instantiate(elementenergy, new Vector3(_hit.point.x, _hit.point.y, _hit.point.z), transform.rotation);
            energy += inspire;
            plane.SetNormalAndPosition(Camera.main.transform.forward, transform.position);
            plane.SetNormalAndPosition(Camera.main.transform.forward, transform.position);
            //Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            float dist;
            plane.Raycast(ray, out dist);
            v3Offset = transform.position - ray.GetPoint(dist);
        }
    }
    }