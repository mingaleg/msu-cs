%include 'io.inc'

section .data
    ; 00, 01, 10, 11
    r000 dw 1111b
    r001 dw 0000b
    r010 dw 1010b
    r011 dw 0101b
    r100 dw 1100b
    r101 dw 0011b
    r110 dw 1001b
    r111 dw 0110b

    a0000 dw 00b
    a0001 dw 11b
    a0010 dw 10b
    a0011 dw 11b
    a0100 dw 01b
    a0101 dw 11b
    a0110 dw 10b
    a0111 dw 11b
    a1000 dw 00b
    a1001 dw 00b
    a1010 dw 00b
    a1011 dw 00b
    a1100 dw 00b
    a1101 dw 00b
    a1110 dw 00b
    a1111 dw 00b

section .bss
    a11 resd 1
    a12 resd 1
    b1  resd 1
    a21 resd 1
    a22 resd 1
    b2  resd 1

    ia11 resd 1
    ia12 resd 1
    ib1  resd 1
    ia21 resd 1
    ia22 resd 1
    ib2  resd 1

    s1  resd 1
    s2  resd 1
    s   resd 1

    ccx  resd 1
    ccy  resd 1

    x resd 1
    y resd 1

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, ia11
    GET_UDEC 4, ia12
    GET_UDEC 4, ia21
    GET_UDEC 4, ia22
    GET_UDEC 4, ib1
    GET_UDEC 4, ib2
    
    mov eax, 0
    mov DWORD[x], eax
    mov DWORD[y], eax

    %rep 32

    mov eax, DWORD[ia11]
    and eax, 1
    mov DWORD[a11], eax
    mov eax, DWORD[ia12]
    and eax, 1
    mov DWORD[a12], eax
    mov eax, DWORD[ia21]
    and eax, 1
    mov DWORD[a21], eax
    mov eax, DWORD[ia22]
    and eax, 1
    mov DWORD[a22], eax
    mov eax, DWORD[ib1]
    and eax, 1
    mov DWORD[b1], eax
    mov eax, DWORD[ib2]
    and eax, 1
    mov DWORD[b2], eax


    ; First line
    mov eax, DWORD[b1]
    mov DWORD[s1], eax

    mov eax, DWORD[a12]
    shl eax, 1
    add eax, DWORD[s1]
    mov DWORD[s1], eax

    mov eax, DWORD[a11]
    shl eax, 2
    add eax, DWORD[s1]
    mov DWORD[s1], eax

    mov eax, DWORD[s1]
    movzx ebx, WORD[r000 + 2*eax]
    mov DWORD[s1], ebx


    ; Second line
    mov eax, DWORD[b2]
    mov DWORD[s2], eax

    mov eax, DWORD[a22]
    shl eax, 1
    add eax, DWORD[s2]
    mov DWORD[s2], eax

    mov eax, DWORD[a21]
    shl eax, 2
    add eax, DWORD[s2]
    mov DWORD[s2], eax

    mov eax, DWORD[s2]
    movzx ebx, WORD[r000 + 2*eax]
    mov DWORD[s2], ebx

    ;Common
    mov eax, DWORD[s1]
    and eax, DWORD[s2]
    mov DWORD[s], eax

    ;PRINT_HEX 4, s1
    ;NEWLINE
    ;PRINT_HEX 4, s2
    ;NEWLINE
    ;PRINT_HEX 4, s
    ;NEWLINE

    movzx ebx, WORD[a0000 + 2*eax]
    mov eax, ebx

    ;movzx ebx, WORD[a0000 + 2*eax]
    ;PRINT_HEX 4, ebx
    ;NEWLINE
    and eax, 1
    mov DWORD[ccy], eax
    shr ebx, 1
    mov DWORD[ccx], ebx

    mov eax, DWORD[x]
    or  eax, DWORD[ccx]
    ror eax, 1
    mov DWORD[x], eax
    mov eax, DWORD[y]
    or  eax, DWORD[ccy]
    ror eax, 1
    mov DWORD[y], eax

    mov eax, DWORD[ia11]
    ror eax, 1
    mov DWORD[ia11], eax
    mov eax, DWORD[ia12]
    ror eax, 1
    mov DWORD[ia12], eax
    mov eax, DWORD[ia21]
    ror eax, 1
    mov DWORD[ia21], eax
    mov eax, DWORD[ia22]
    ror eax, 1
    mov DWORD[ia22], eax
    mov eax, DWORD[ib1]
    ror eax, 1
    mov DWORD[ib1], eax
    mov eax, DWORD[ib2]
    ror eax, 1
    mov DWORD[ib2], eax

    %endrep

    PRINT_UDEC 4, x
    PRINT_CHAR " "
    PRINT_UDEC 4, y
    NEWLINE

    mov eax, 0
    ret