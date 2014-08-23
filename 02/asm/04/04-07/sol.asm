%include 'io.inc'

section .bss
    n   resd 1
    arr resd 500000
    ta  resd 1
    tb  resd 1
    i   resd 1
    j   resd 1
    arr_end resd 1

section .text
global CMAIN
CMAIN:
    GET_DEC 4, n

    mov ecx, DWORD[n]
    mov eax, arr
    L0:
        GET_DEC 4, [eax]
        add eax, 4
    loop L0

    mov DWORD[i], 0
    Li:
        mov eax, DWORD[n]
        cmp DWORD[i], eax
        jge sLi
        mov eax, DWORD[i]
        inc eax
        mov DWORD[j], eax
        Lj:
            mov eax, DWORD[n]
            cmp DWORD[j], eax
            jge sLj

            mov eax, DWORD[i]
            shl eax, 2
            add eax, arr
            mov ebx, DWORD[j]
            shl ebx, 2
            add ebx, arr

            mov ecx, DWORD[eax]
            mov edx, DWORD[ebx]
            cmp ecx, edx
            jle NOSWAP
                mov DWORD[eax], edx
                mov DWORD[ebx], ecx
            NOSWAP:

            inc DWORD[j]
            jmp Lj
        sLj:
        inc DWORD[i]
        jmp Li
    sLi:

    mov eax, arr
    mov ecx, DWORD[n]
    L1:
        PRINT_DEC 4, [eax]
        add eax, 4
        PRINT_CHAR " "
    loop L1

    NEWLINE

    mov eax, 0
    ret
