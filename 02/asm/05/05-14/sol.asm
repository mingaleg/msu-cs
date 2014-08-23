%include 'io.inc'

section .bss
    K  resd 1
    N  resd 1
    A  resd 1
    x0 resd 1
    x1 resd 1
    x2 resd 1

section .text
global CMAIN

sharp:
; ebp+8  x1
; ebp+12 x2
; ebp+16 k
    push ebp
    mov ebp, esp

    mov eax, dword[ebp+12]
    test eax, eax
    jnz .nontrivia

    mov ecx, dword[ebp+8]
    imul ecx, dword[ebp+16]
    mov eax, ecx
    jmp .sharpreturn

    .nontrivia:
    mov ecx, 1

    .sharploop:
        cmp ecx, dword[ebp+12]
        jg .endsharploop
        imul ecx, dword[ebp+16]
        jmp .sharploop
    .endsharploop:

    imul ecx, dword[ebp+8]
    add ecx, dword[ebp+12]

    mov eax, ecx

    .sharpreturn:
    leave
    ret

CMAIN:
    GET_DEC 4, K
    GET_DEC 4, N
    GET_DEC 4, A

    mov eax, dword[A]
    cdq
    mov ecx, 2011
    idiv ecx
    mov dword[x0], edx

    push dword[K]
    push dword[x0]
    push dword[x0]
    call sharp
    pop edx
    pop edx
    pop edx

    cdq
    mov ecx, 2011
    idiv ecx
    mov dword[x1], edx

    mov ebx, 2
    .mainloop:
        cmp ebx, dword[N]
        jg .endmainloop

        push dword[K]
        push dword[x0]
        push dword[x1]
        call sharp
        pop edx
        pop edx
        pop edx

        cdq
        mov ecx, 2011
        idiv ecx
        mov dword[x2], edx

        mov edx, dword[x1]
        mov dword[x0], edx
        mov edx, dword[x2]
        mov dword[x1], edx

        inc ebx
        jmp .mainloop
    .endmainloop:

    PRINT_DEC 4, x1
    NEWLINE

    xor eax, eax
    ret
