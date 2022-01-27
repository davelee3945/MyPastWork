using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour{
    public float moveSpeed;

    public Rigidbody2D rb;

    Vector2 movement;

    public bool canMove = true;

    private void FixedUpdate(){
        rb.velocity = movement * moveSpeed;
        
    }

    void OnMovement(InputValue value){
        if (canMove == false){
            return;
        }

        //Debug.Log("Player moving");
        movement = value.Get<Vector2>();
        
    }

    public void StopMovement(){
        Debug.Log("Stop player!");
        movement = Vector2.zero;
        canMove = false;
    }

    public void StartMovement(){
        Debug.Log("Start player!");
        movement = Vector2.zero;
        canMove = true;
    }

}
