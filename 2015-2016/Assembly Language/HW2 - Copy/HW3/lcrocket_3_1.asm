; Homework 3.1
; Lucas Crockett
; 

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	str1 BYTE "cat", 0
	dStr BYTE 6 DUP (?)
	rStr BYTE 3 DUP (?)
	cStr BYTE 3 DUP (?)

.code
main proc
	mov esi, 0				;index
	mov edi, 2				;index for rStr
	mov ebx, 0				;clear register
	mov ecx, 3				;set loop counter to 3

L1:
	mov bl, str1[esi]		;copy character at position (esi) to bl
	mov dStr[esi], bl		;copy character to first half of dStr
	mov dStr[esi+3], bl		;copy character to second half of dStr
	mov rStr[edi], bl		;copy character to position (edi) of rStr
	sub bl, 20h				;convert character in bl to CAPITAL
	mov cStr[esi], bl		;copy character to position (esi) of cStr
	inc esi					;increment index
	dec edi					;decrement rStr index
	loop L1	

	invoke ExitProcess,0
main endp
end main