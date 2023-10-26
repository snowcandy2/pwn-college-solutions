.intel_syntax noprefix
push rsi
xor rax, rax
start:
add rax, qword ptr [rdi]
add rdi, 8
sub rsi, 1
cmp rsi, 0
je end
jmp start
end:
pop rsi
div rsi
