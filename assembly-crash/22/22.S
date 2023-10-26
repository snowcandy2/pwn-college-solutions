.intel_syntax noprefix
xor rcx, rcx
mov rsi, rdi
cmp rsi, 0
je end
start:
mov bl, [rsi]
cmp bl, 0
je end
cmp bl, 0x5a
ja skip
mov rdi, [rsi]
mov rax, 0x403000
call rax
mov [rsi], al
add rcx, 1
skip:
add rsi, 1
jmp start
end:
mov rax, rcx
ret
