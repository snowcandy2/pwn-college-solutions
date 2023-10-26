.intel_syntax noprefix
mov rbp, rsp
mov rax, 0     
sub rsi, 1  

sub rsp, 0xf
mov r9, 1      
loop1:
cmp rax, rsi   
jg endloop1
xor rcx, rcx
mov cl, [rdi + rax]  
mov rdx, rbp   
sub rdx, rcx
mov r9b, [rdx]   
add r9b, 1
mov [rdx], r9b
add rax, 1     
jmp loop1

endloop1:
mov rax, 0     
mov rbx, 0     
mov rcx, 1     
loop2:
cmp rcx, 0xff
jg endloop2

mov r11, rbp
sub r11, rcx
mov r8b, [r11]
cmp r8b, bl
jbe skip

mov bl, r8b
mov rax, rcx

skip:

add rcx, 1
sub r11, 1
jmp loop2
endloop2:

mov rsp, rbp
ret
