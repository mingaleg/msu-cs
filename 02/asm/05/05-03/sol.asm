%include 'io.inc'

reverse:
    GET_DEC 4, eax
    test eax, eax
    jz .skip

    push eax
    call reverse
    pop eax
    PRINT_DEC 4, eax
    PRINT_STRING " "

    .skip:
    ret

section .text
global CMAIN
CMAIN:
    call reverse
    xor eax, eax
    ret
