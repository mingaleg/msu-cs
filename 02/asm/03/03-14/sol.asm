%include 'io.inc'

section .bss
    n       resd 1
    m       resd 1
    k       resd 1
    d       resd 1
    x       resd 1
    y       resd 1
    
    box     resd 1
    time    resd 1
    free    resd 1
    ans     resd 1

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, n
    GET_UDEC 4, m
    GET_UDEC 4, k
    GET_UDEC 4, d
    GET_UDEC 4, x
    GET_UDEC 4, y

    mov eax, DWORD[n]
    mul DWORD[m]
    mul DWORD[k]
    mov edx, 0
    div DWORD[d]
    mov DWORD[box], eax

    mov eax, edx
    %rep 31
        rol eax, 1
        or edx, eax
    %endrep
    mov eax, DWORD[box]
    sub eax, edx
    mov DWORD[box], eax

    mov eax, DWORD[x]
    mov ebx, 60
    mul ebx
    add eax, DWORD[y]
    mov ebx, 6*60
    sub eax, ebx
    sar eax, 31
    mov ebx, 1
    add ebx, eax
    mov DWORD[free], ebx

    mov eax, DWORD[box]
    dec eax
    mov edx, 0
    mov ebx, 3
    div ebx
    inc eax
    mul DWORD[free]

    mov ebx, DWORD[box]
    sub ebx, eax

    PRINT_UDEC 4, ebx
    NEWLINE

    mov eax, 0
    ret
