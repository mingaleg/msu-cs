%include "io.inc"

section .data
    inpd db '%d', 0
    inps db '%s', 0
    outd  db '%d', 10, 0

section .bss
    strs resb 5500
    n resd 1

section .text

global CMAIN
CMAIN:
    EXTERN scanf
    EXTERN printf
    EXTERN strcmp
    pusha
    mov ebp, esp
    and esp, -16
    sub esp, 16

    mov dword[esp], inpd
    mov dword[esp+4], n
    call scanf

    cmp dword[n], 0
    jne .nonzero
        mov dword[esp], outd
        mov dword[esp+4], 0
        call printf
        jmp .return_cmain
    .nonzero:

    mov esi, dword[n]
    mov ebx, strs
    .read:
        cmp esi, 0
        je .endread
        mov dword[esp], inps
        mov dword[esp+4], ebx
        call scanf
        add ebx, 11
        dec esi
    jmp .read
    .endread:

    mov esi, dword[n]
    dec esi
    imul esi, 11
    add esi, strs

    .exec:
        cmp esi, strs
        jle .endexec
        mov ebx, esi
        .inside:
            sub ebx, 11
            cmp ebx, strs
            jl .endinside
            mov dword[esp], ebx
            mov dword[esp+4], esi
            call strcmp
            test eax, eax
            jnz .next
                mov byte[ebx], 0
            .next:
        jmp .inside
        .endinside:
        sub esi, 11
    jmp .exec
    .endexec:

    mov eax, 0
    mov edx, dword[n]
    mov ecx, edx
    dec edx
    imul edx, 11
    add edx, strs

    .sum:
        test ecx, ecx
        jz .endsum
        cmp byte[edx], 0
        jz .skip
            inc eax
        .skip:
        dec ecx
        sub edx, 11
    jmp .sum
    .endsum:

    mov dword[esp], outd
    mov dword[esp+4], eax
    call printf

.return_cmain:
    mov esp, ebp
    popa

    mov eax, 0
    ret
