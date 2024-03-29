%include 'io.inc'

section .bss
    x1 resd 1
    y1 resd 1
    x2 resd 1
    y2 resd 1
    x3 resd 1
    y3 resd 1
    s  resd 1

section .data
    prec    dw '05'

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, x1
    GET_UDEC 4, y1
    GET_UDEC 4, x2
    GET_UDEC 4, y2
    GET_UDEC 4, x3
    GET_UDEC 4, y3

    mov eax, DWORD[x1]
    sub eax, DWORD[x3]
    mov DWORD[x1], eax
    mov eax, DWORD[y1]
    sub eax, DWORD[y3]
    mov DWORD[y1], eax
    mov eax, DWORD[x2]
    sub eax, DWORD[x3]
    mov DWORD[x2], eax
    mov eax, DWORD[y2]
    sub eax, DWORD[y3]
    mov DWORD[y2], eax

    mov eax, DWORD[x1]
    mul DWORD[y2]
    mov DWORD[s], eax
    mov eax, DWORD[y1]
    mul DWORD[x2]
    sub eax, DWORD[s]

    mov ebx, eax
    sar ebx, 31
    xor eax, ebx
    sub eax, ebx

    mov ebx, 2
    mov edx, 0
    div ebx

    PRINT_UDEC 4, eax
    PRINT_CHAR '.'
    PRINT_CHAR prec + edx
    NEWLINE

    mov eax, 0
    ret
