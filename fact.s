section .data
    len equ 255
    mul_sign db '*'
    one db '1'
    null db '0'

    overflow_msg db 'слишком большое число  '
    len_overflow_msg equ $ - overflow_msg

    correct_msg db 'Нужно ввести целое положительное число  '
    len_correct_msg equ $ - correct_msg
    
    
section .bss
    num resb len
    outp resb 1

section .text
global _start

_start:
call Read
    call Check
    xor edx,edx

    mov ecx, eax 
    call Get_digit

    cmp eax, 0 
    je Null

    mov ebx, 2 
    call Factorize

call Write

    mov eax, 1
    mov ebx, 0
    int 80h




Write:
    mov eax, 4
    mov ebx, 1
    mov ecx, one
    mov edx, 1
    int 80h
ret




Read:
    mov eax, 3 
    mov ebx, 0
    mov ecx, num
    mov edx, len
    int 80h

    dec eax ;
ret

Null:
    mov eax, 4
    mov ebx, 1
    mov ecx, null
    mov edx, 1
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h

Correct:
    mov eax, 4
    mov ebx, 1
    mov ecx, correct_msg
    mov edx, len_correct_msg
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h

Overflow:
    mov eax, 4
    mov ebx, 1
    mov ecx, overflow_msg
    mov edx, len_overflow_msg
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h

Check:
    push eax

    .check_digit:
        movzx edx, byte [num + eax - 1] 
        cmp edx, '0'
        jl Correct
        cmp edx, '9'
        jg Correct

        dec eax
        cmp eax, 0
        jne .check_digit

    pop eax
    ret


Get_digit:
    xor eax, eax
    mov ebp, 10

    .digit:
        xor ebx, ebx
        mov bl, byte [num + esi] ;
        mul ebp
        jo Overflow

        sub bl, '0'
        add eax, ebx
        inc esi
        cmp esi, ecx
        jl .digit

    ret


Factorize:
    cmp eax, 1
    je .return
    mov esi, eax
    xor edx, edx

    div ebx
    cmp edx, 0
    je .true

    mov eax, esi
    inc ebx
    jmp Factorize

    .true:
        call Print_factor
        mov ebx, 2
        jmp Factorize

    .return:
        ret

Print_factor:
    xor esi, esi
    push eax
    xor eax, eax
    mov eax, ebx
    xor ebx, ebx

    mov ebp, esp
    xor ecx, ecx

    .factor:
        mov ebx, 10
        div ebx 
        add edx, '0'
        push edx 
        xor edx, edx
        inc esi
        cmp eax, 0
        jne .factor

    .output:
        pop edx
        mov [outp], dl

        mov eax, 4
        mov ebx, 1
        mov ecx, outp
        mov edx, 1
        int 80h

        dec esi
        cmp esi, 0
        jne .output

        .sign:
            mov eax, 4
            mov ebx, 1
            mov ecx, mul_sign
            mov edx, 1
            int 80h
            
        mov esp, ebp
        pop eax

        ret

