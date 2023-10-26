.intel_syntax noprefix
cmp rdi, 4
jg reset
jmp start
reset:
mov rdi, 4
start:
imul rdi, 8
add rsi, rdi
mov rax, qword ptr [rsi]
jmp rax
