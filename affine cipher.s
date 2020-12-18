SECTION .data
	msg db '{abcdefghijklmnopqrstuvwxyz}',0xa
	lenm equ $ - msg

newLine db 0xa
a dd 3
b dd 4
SECTION .bss
    array resb lenm
section .text
    global _start
    _start:
    mov ecx,(lenm - 1)

    mov esi,msg
    mov edi,array 

 .letter:
    mov dl,[esi] 
    cmp dl,'z' 
    ja .save_notletter 

    cmp dl,'a' 
    jb .capital 

    call encrypt
    jmp .save

    .capital: 
        cmp dl,'Z' 
        ja .save_notletter

        cmp dl,'A'
        jb .save_notletter
        
        add dl,20h ;A-Z -> a-z
        call encrypt
        sub dl,20h ;a-z -> A-Z
        jmp .save

    .save_notletter:
        call get_letter_text
        loop .letter
        jmp .output

    .save:
        call get_letter_text
        loop .letter
        jmp .output
        
    .output:
        mov eax,4
        mov ebx,1
        mov ecx,array
        mov edx,lenm
        int 80h

        mov eax, 4
        mov ebx, 1
        mov ecx, newLine
        mov edx, 1
        int 80h

        mov eax,1
        xor ebx,ebx
        int 80h
        ret


get_letter_text:
    mov [edi],dl
    xor dl,dl
    inc esi 
    inc edi 
    ret



	encrypt:

sub dl,97
mov dh,dl
mov bx, 3
dec bx
while:
dec bx
add dl,dh
cmp bx,0  
ja while
       
 add dl,4

mov al,dl
cbw

mov ax,ax
mov bl,26
div bl
mov dl,ah
add dl,97
        ret       
