%include "io.inc"

section .data
    inp1 db '%d %d', 0
    out1 db '%d ', 0
    fin db 'input.txt', 0
    fout db 'output.txt', 0
    inm db 'r', 0
    outm db 'w', 0
section .bss
    next resd 100002
    prev resd 100002
    head resd 1
    if resd 1
    of resd 1
    n resd 1
    m resd 1
    a resd 1
    b resd 1

section .text

global CMAIN
CMAIN:
    EXTERN fopen
    EXTERN fscanf
    EXTERN fprintf

    pusha
    mov ebp, esp
    and esp, -16
    sub esp, 16

    mov dword[esp], fin
    mov dword[esp+4], inm
    call fopen
    mov dword[if], eax

    mov dword[esp], fout
    mov dword[esp+4], outm
    call fopen
    mov dword[of], eax

    mov eax, dword[if]
    mov dword[esp], eax
    mov dword[esp+4], inp1
    mov dword[esp+8], n
    mov dword[esp+12], m
    call fscanf

    mov ecx, dword[n]
    .preparelist:
        mov eax, ecx
        inc eax
        mov dword[next + ecx*4], eax
        sub eax, 2
        mov dword[prev + ecx*4], eax
        dec ecx
        cmp ecx, 0
    jne .preparelist

    mov dword[head], 1

    mov ecx, dword[m]
    .exec:
        mov dword[esp+8], a
        mov dword[esp+12], b
        mov dword[esp+16], ecx
        call fscanf
        mov ecx, dword[esp+16]

        mov eax, dword[a]
        mov edx, dword[b]

        cmp eax, dword[head]
        je .ok

        mov ebx, dword[prev + eax*4]
        mov esi, dword[next + edx*4]
        mov dword[next + ebx*4], esi
        mov dword[prev + esi*4], ebx

        mov dword[prev + eax*4], 0

        mov eax, dword[head]
        mov dword[next + edx*4], eax

        mov dword[prev + eax*4], edx

        mov eax, dword[a]
        mov dword[head], eax

        .ok:
        dec ecx
        cmp ecx, 0
    jne .exec

    mov eax, dword[of]
    mov dword[esp], eax
    mov dword[esp + 4], out1

    mov edx, dword[head]

    .answer:
        mov dword[esp+8], edx
        call fprintf

        mov edx, dword[esp + 8]
        mov edx, dword[next + edx * 4]

        mov eax, dword[n]
        inc eax
        cmp edx, eax
    jne .answer

    .return_cmain:
    mov esp, ebp
    popa
    mov eax, 0
    ret
