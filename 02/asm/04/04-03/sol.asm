%include 'io.inc'

section .bss
    n   resd 1
    arr resd 500000
    ml   resd 1
    mg   resd 1
    ansl resd 500000
    ansg resd 500000

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, n

    mov eax, DWORD[n]
    cmp eax, 3
    jge NONTRIVIA
    PRINT_STRING "0"
    NEWLINE
    PRINT_STRING "0"
    NEWLINE
    mov eax, 0
    ret

    NONTRIVIA:

    mov eax, arr
    mov ecx, DWORD[n]
    L0:
        GET_UDEC 4, [eax]
        add eax, 4
    loop L0

    mov ecx, DWORD[n]
    sub ecx, 2
    mov ebx, 0
    mov eax, 1
    mov DWORD[ml], 0
    mov DWORD[mg], 0
    L1:
        mov edx, DWORD[arr + 4*eax]
        cmp edx, DWORD[arr + 4*eax - 4]
        je SKIP
        jg R_X
            cmp edx, DWORD[arr + 4*eax + 4]
            jnl SKIP
            mov edx, DWORD[ml]
            mov DWORD[ansl + 4*edx], eax
            inc DWORD[ml]
            jmp SKIP
        R_X:
            cmp edx, DWORD[arr + 4*eax + 4]
            jng SKIP
            mov edx, DWORD[mg]
            mov DWORD[ansg + 4*edx], eax
            inc DWORD[mg]
        SKIP:
        inc eax
    loop L1

    PRINT_UDEC 4, ml
    NEWLINE
    mov ebx, DWORD[ml]
    test ebx, ebx
    jz SKIPL2
    mov ecx, ebx
    mov eax, 0
    L2:
        PRINT_UDEC 4, ansl+4*eax
        PRINT_CHAR ' '
        inc eax
    loop L2
    SKIPL2:
    NEWLINE

    PRINT_UDEC 4, mg
    NEWLINE
    mov ebx, DWORD[mg]
    test ebx, ebx
    jz SKIPL3
    mov ecx, ebx
    mov eax, 0
    L3:
        PRINT_UDEC 4, ansg+4*eax
        PRINT_CHAR ' '
        inc eax
    loop L3
    SKIPL3:
    NEWLINE

    mov eax, 0
    ret
