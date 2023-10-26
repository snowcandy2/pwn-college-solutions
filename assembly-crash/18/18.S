.intel_syntax noprefix
xor rax, rax
cmp dword ptr [rdi], 0x7f454c46
je op1
cmp dword ptr [rdi], 0x00005a4d
je op2
mov eax, dword ptr[rdi+4]
imul eax, dword ptr[rdi+8]
imul eax, dword ptr[rdi+12]
jmp end1
op2:
mov eax, dword ptr[rdi+4]
sub eax, dword ptr[rdi+8]
sub eax, dword ptr[rdi+12]
jmp end1
op1:
mov eax, dword ptr[rdi+4]
add eax, dword ptr[rdi+8]
add eax, dword ptr[rdi+12]
end1:
nop
