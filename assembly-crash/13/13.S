.intel_syntax noprefix
mov eax, dword ptr [rdi]
mov dword ptr [rsi], eax
mov eax, dword ptr [rdi + 8]
add dword ptr [rsi], eax
