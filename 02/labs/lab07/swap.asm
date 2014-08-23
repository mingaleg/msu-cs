global swap
swap:
    extern count_swap
    push ebx

    mov eax, dword[esp + 8]
    mov edx, dword[esp + 12]
    mov ecx, dword[eax]
    mov ebx, dword[edx]
    mov dword[eax], ebx
    mov dword[edx], ecx

    inc dword[count_swap]
    pop ebx
    ret
