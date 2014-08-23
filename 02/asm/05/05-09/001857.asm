%include 'io.inc'

section .bss
    n   resd 1
    cur resd 1
    all resd 1

section .text
global CMAIN

poor:
    push ebp
    mov ebp, esp
    push ebx
    push edi

    mov edi, 1
    mov ebx, 0

    .cycle1:
        cmp edi, dword[ebp+8]
        je .endcycle1

        xor edx, edx
        div edi
        test edx, edx
        mov eax, DWORD[ebp+8]
        jnz .skipadd
            add ebx, edi
        .skipadd:

        inc edi

        jmp .cycle1
    .endcycle1:

    cmp ebx, eax
    jl .ispoor
    mov eax, 0
    jmp .return
    .ispoor:
    mov eax, 1

    .return:
    pop edi
    pop ebx
    leave
    ret


CMAIN:
    GET_DEC 4, n
    mov DWORD[cur], 0
    mov DWORD[all], 0

    .mainloop:
        mov ecx, DWORD[all]
        cmp ecx, DWORD[n]
        je .endmainloop

        inc DWORD[cur]
        push DWORD[cur]
        call poor
        pop edx
        test eax, eax
        jz .rich
            inc DWORD[all]
        .rich:

        jmp .mainloop
    .endmainloop:

    PRINT_DEC 4, cur
    ;NEWLINE

    xor eax, eax
    ret
