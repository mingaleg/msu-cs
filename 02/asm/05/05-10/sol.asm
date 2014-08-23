%include 'io.inc'

section .bss
    p1 resd 1
    q1 resd 1
    p2 resd 1
    q2 resd 1
    N  resd 1

section .text
global CMAIN

gcd:
    push ebp
    mov ebp, esp

    mov eax, dword[esp+8]
    mov ecx, dword[esp+12]

    test ecx, ecx
    jz .gcdreturn

    cdq
    idiv ecx
    push edx
    push ecx
    call gcd
    pop ecx
    pop edx

    .gcdreturn:
    leave
    ret

sum:
; +8  p1
; +12 q1
; +16 p2
; +20 q2
    push ebp
    mov ebp, esp

    mov eax, dword[ebp+12]
    imul eax, dword[ebp+16]
    mov ecx, dword[ebp+20]
    imul ecx, dword[ebp+8]
    add eax, ecx
    mov dword[ebp+8], eax

    mov eax, dword[ebp+12]
    imul eax, dword[ebp+20]
    mov dword[ebp+12], eax

    push dword[ebp+8]
    push dword[ebp+12]
    call gcd
    pop edx
    pop edx

    mov ecx, eax
    mov eax, dword[ebp+8]
    mov edx, 0
    idiv ecx
    mov dword[ebp+8], eax
    mov eax, dword[ebp+12]
    mov edx, 0
    idiv ecx
    mov dword[ebp+12], eax

    leave
    ret

CMAIN:
    GET_DEC 4, N

    GET_DEC 4, p1
    GET_DEC 4, q1

    mov ebx, dword[N]
    dec ebx

    .mainloop:
        test ebx, ebx
        jz .endmainloop

        GET_DEC 4, p2
        GET_DEC 4, q2

        push DWORD[q2]
        push DWORD[p2]
        push DWORD[q1]
        push DWORD[p1]
        call sum
        pop DWORD[p1]
        pop DWORD[q1]
        pop edx
        pop edx

        dec ebx
        jmp .mainloop
    .endmainloop:

    PRINT_DEC 4, p1
    PRINT_STRING " "
    PRINT_DEC 4, q1
    NEWLINE

    xor eax, eax
    ret
