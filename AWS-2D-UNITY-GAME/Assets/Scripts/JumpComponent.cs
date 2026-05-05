using System;
using TMPro;
using UnityEngine;
using UnityEngine.InputSystem;

[RequireComponent(typeof(Rigidbody2D))]
public class JumpComponent : MonoBehaviour
{
    public float jumpForce = 10f;
    public bool isGrounded = true;
    [SerializeField]
    private Animator animator;
    public TMP_Text jumpText;

    public event Action OnJump;

    private Rigidbody2D rb;

    void Awake() => rb = GetComponent<Rigidbody2D>();

    void Update()
    {
        if (Keyboard.current != null &&
            Keyboard.current.spaceKey.wasPressedThisFrame &&
            isGrounded)
        {
            rb.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
            isGrounded = false;
            animator.SetBool("isGrounded", isGrounded);
            OnJump?.Invoke(); // salto real
            if(jumpText.enabled) jumpText.enabled = false;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Ground")){
            isGrounded = true;
            animator.SetBool("isGrounded", isGrounded);
        } 
    }
}
