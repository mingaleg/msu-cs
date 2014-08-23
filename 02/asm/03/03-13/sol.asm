%include 'io.inc'

section .bss
    x1  resw 1
    y1  resw 1
    x2  resw 1
    y2  resw 1
    ans resw 1

section .text
global CMAIN
CMAIN:
    GET_CHAR x1
    GET_CHAR y1
    GET_CHAR eax
    GET_CHAR x2
    GET_CHAR y2

    mov bx, WORD[x1]
    sub bx, WORD[x2]
    mov ax, bx
    sar bx, 31
    xor ax, bx
    sub ax, bx
    mov WORD[ans], ax

    mov bx, WORD[y1]
    sub bx, WORD[y2]
    mov ax, bx
    sar bx, 31
    xor ax, bx
    sub ax, bx
    add ax, WORD[ans]

    PRINT_UDEC 1, ax
    NEWLINE

    mov eax, 0
    ret
