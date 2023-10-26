.intel_syntax noprefix
cmp rdi, 0
je end
xor rax, rax
start:
mov bx, [rdi]
cmp bx, 0
je trueend
add rax, 1
add rdi, 1
jmp start
end:
mov rax, 0
trueend:
nop

