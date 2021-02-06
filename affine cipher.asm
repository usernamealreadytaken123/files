SECTION .data
	msg db 'hello',0xa
	lenm equ $ - msg
keya dw 3
keyb dw 4
SECTION .bss
    array resb lenm
    
section .text
    global _start
    _start:
    mov ecx,lenm 
    mov esi,msg
    mov edi,array 
 .text:
    mov dl,[esi] 
    cmp dl,'z' 
    ja .save

    cmp dl,'a' 
    jb .capital 

    call cipher
    jmp .save

    .capital: 
        cmp dl,'Z' 
        ja .save

        cmp dl,'A'
        jb .save
        
        add dl,32 ;
        call cipher
        sub dl,32 ;
        jmp .save
	
    .save:
        call get_letter_text
        loop .text
        jmp .write
        
    .write:
        mov eax,4
        mov ebx,1
        mov ecx,array
        mov edx,lenm
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



	cipher:

sub dl,97
mov dh,dl
mov bx, [keya]
dec bx
while:
dec bx
add dl,dh
cmp bx,0  
ja while
       mov bl,[keyb]
 add dl,bl

mov al,dl
cbw

mov ax,ax
mov bl,26
div bl
mov dl,ah
add dl,97
        ret       
