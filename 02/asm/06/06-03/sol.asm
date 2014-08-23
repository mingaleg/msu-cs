%include 'io.inc'

section .data
    inp db '%s%s', 0
    out1 db '%s', 10, 0
    out2 db '%s[%s]%s', 10, 0

section .bss
    s1 resb 101
    s2 resb 101
    spref resb 101
    smid resb 101
    ssuff resb 101
    spos resd 1

section .text
global CMAIN

CMAIN:
    EXTERN scanf
    EXTERN printf
    EXTERN strstr
    EXTERN strcpy
    EXTERN strlen

    push ebp
    mov ebp, esp
    and esp, -16
    sub esp, 16

    mov dword[esp], inp
    mov dword[esp+4], s1
    mov dword[esp+8], s2
    call scanf

    mov esi, 2
    .lo:
        test esi, esi
        jz .nolo

        mov dword[esp], s1
        mov dword[esp+4], s2
        call strstr
        mov dword[spos], eax
        test eax, eax
        jz .nofirst

        mov dword[esp], spref
        mov dword[esp+4], s1
        call strcpy
        mov eax, spref
        add eax, dword[spos]
        sub eax, s1
        mov byte[eax], 0

        mov dword[esp], smid
        mov dword[esp+4], s2
        call strcpy

        mov dword[esp], s2
        call strlen
        add eax, dword[spos]
        mov dword[esp], ssuff
        mov dword[esp+4], eax
        call strcpy

        mov dword[esp], out2
        mov dword[esp+4], spref
        mov dword[esp+8], smid
        mov dword[esp+12], ssuff
        call printf

        jmp .return_cmain
        
        .nofirst:
        mov dword[esp], smid
        mov dword[esp+4], s1
        call strcpy
        mov dword[esp], s1
        mov dword[esp+4], s2
        call strcpy
        mov dword[esp], s2
        mov dword[esp+4], smid
        call strcpy

        dec esi
    jmp .lo
    .nolo:

    mov dword[esp], out1
    mov dword[esp+4], s1
    call printf

    .return_cmain:
    xor eax, eax
    leave
    ret
