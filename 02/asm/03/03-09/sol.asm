%include 'io.inc'

section .bss
    n resd 1

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, n

    mov ebx, DWORD[n]
    sar ebx, 31
    mov eax, DWORD[n]
    xor eax, ebx
    sub eax, ebx

    PRINT_UDEC 4, eax
    NEWLINE

    mov eax, 0
    ret
