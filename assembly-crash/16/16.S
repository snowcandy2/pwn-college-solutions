.intel_syntax noprefix
xor rax, rax
mov rax, qword ptr[rsp]
add rax, qword ptr[rsp+8]
add rax, qword ptr[rsp+16]
add rax, qword ptr[rsp+24]
mov rbx, 0x4
div rbx
push rax
