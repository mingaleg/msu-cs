%include "io.inc"

section .data
    fin db 'input.bin', 0
    fout db 'output.bin', 0
    inm db 'rb', 0
    outm db 'wb', 0

section .bss
    a resd 2100000
    fi resd 1
    fo resd 1
    ans resd 1

section .text

global CMAIN
CMAIN:
    EXTERN fopen
    EXTERN fread
    EXTERN fwrite
    pusha
    mov ebp, esp
    and esp, -16
    sub esp, 16

    mov dword[esp], fin
    mov dword[esp + 4], inm
    call fopen
    mov dword[fi], eax

    mov dword[esp], fout
    mov dword[esp + 4], outm
    call fopen
    mov dword[fo], eax

    mov ebx, 0
    mov eax, dword[fi]
    mov dword[esp], a
    mov dword[esp + 4], 4
    mov dword[esp + 8], 1
    mov dword[esp + 12], eax
    .reading:
        call fread
        test eax, eax
        jz .endreading
        add dword[esp], 4
        inc ebx
    jmp .reading
    .endreading:

    mov eax, 1
    mov ecx, 0
    .toup:
        mov edx, dword[a + ecx * 4]
        push ecx
        imul ecx, 2
        inc ecx
        cmp ecx, ebx
        jge .upok
        cmp edx, dword[a + ecx * 4]
        jle .uptr
        mov eax, 0
    .uptr:
        inc ecx
        cmp ecx, ebx
        jge .upok
        cmp edx, dword[a + ecx * 4]
        jle .upok
        mov eax, 0
    .upok:
        pop ecx
        inc ecx
        cmp ecx, ebx
    jne .toup
    cmp eax, 1
    je .writeup

    mov eax, 1
    mov ecx, 0
    .todn:
        mov edx, dword[a + ecx * 4]
        push ecx
        imul ecx, 2
        inc ecx
        cmp ecx, ebx
        jge .dnok
        cmp edx, dword[a + ecx * 4]
        jge .dntr
        mov eax, 0
    .dntr:
        inc ecx
        cmp ecx, ebx
        jge .dnok
        cmp edx, dword[a + ecx * 4]
        jge .dnok
        mov eax, 0
    .dnok:
        pop ecx
        inc ecx
        cmp ecx, ebx
    jne .todn
    cmp eax, 1
    je .writedn

    mov dword[ans], 0
    mov dword[esp], ans
    mov dword[esp + 4], 4
    mov dword[esp + 8], 1
    mov eax, dword[fo]
    mov dword[esp + 12], eax
    call fwrite
    jmp .return_cmain

.writeup:
    mov dword[ans], 1
    mov dword[esp], ans
    mov dword[esp + 4], 4
    mov dword[esp + 8], 1
    mov eax, dword[fo]
    mov dword[esp + 12], eax
    call fwrite
    jmp .return_cmain

.writedn:
    mov dword[ans], -1
    mov dword[esp], ans
    mov dword[esp + 4], 4
    mov dword[esp + 8], 1
    mov eax, dword[fo]
    mov dword[esp + 12], eax
    call fwrite
    jmp .return_cmain
    
.return_cmain:
    mov esp, ebp
    popa

    mov eax, 0
    ret
