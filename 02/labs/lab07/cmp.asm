global cmp_abs_up, cmp_down

cmp_abs_up:
    extern count_comp
    mov eax, dword[esp+4]
    cdq
    xor eax, edx
    sub eax, edx
    mov ecx, eax
    mov eax, dword[esp+8]
    cdq
    xor eax, edx
    sub eax, edx
    cmp eax, ecx
    mov eax, 0
    je .end
    mov eax, -1
    jg .end
    mov eax, 1
.end:
    inc dword[count_comp]
    ret

cmp_down:
    extern count_comp
    mov eax, dword[esp+4]
    cmp eax, dword[esp+8]
    mov eax, 0
    je .end
    mov eax, -1
    jg .end
    mov eax, 1
.end:
    inc dword[count_comp]
    ret
