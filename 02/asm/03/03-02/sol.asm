%include 'io.inc'

section .bss
    a resd 1
    b resd 1
    c resd 1
    v resd 1
    sum resd 1

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, a
    GET_UDEC 4, b
    GET_UDEC 4, c
    GET_UDEC 4, v

    mov eax, DWORD[a]
    mul DWORD[b]
    div DWORD[v]
    mul DWORD[c]
    mov DWORD[sum], eax

    mov eax, DWORD[a]
    mul DWORD[b]
    div DWORD[v]
    mov eax, edx
    mul DWORD[c]
    div DWORD[v]

    add eax, DWORD[sum]

    PRINT_UDEC 4, eax
    NEWLINE

    mov eax, 0
    ret
