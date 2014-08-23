%include 'io.inc'

section .bss
    a resd 1
    b resd 1
    c resd 1
    sign resd 1

section .text
global CMAIN

sharp:
; ebp+8  x1
; ebp+12 x2
; ebp+16 k
    push ebp
    mov ebp, esp

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

    .gcdreturn:
    leave
    ret

CMAIN:
    GET_DEC 4, a
    GET_DEC 4, b
    GET_DEC 4, c

    mov dword[sign], 1
    mov eax, 0
    cmp dword[a], eax
    jge .skipa
    imul eax, -1
    imul sign, -1
    mov dword[a], eax
    .skipa:
    mov eax, 0
    cmp dword[b], eax
    jge .skipb
    imul eax, -1
    imul sign, -1
    mov dword[b], eax
    .skipb:
    mov eax, 0
    cmp dword[c], eax
    jge .skipc
    imul eax, -1
    imul sign, -1
    mov dword[c], eax
    .skipc:




    xor eax, eax
    ret
