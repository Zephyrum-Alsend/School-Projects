; Homework 2.3.1
; Lucas Crockett
; 

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
bigEnd BYTE 12h, 34h, 56h, 78h
littleEnd DWORD ?

.code
main proc
	mov esi, 3
	mov edi, [littleEnd]
	mov [edi], BYTE PTR bigEnd[esi]
	dec esi
	mov eax, littleEnd

	invoke ExitProcess,0
main endp
end main