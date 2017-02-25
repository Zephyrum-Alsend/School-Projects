;NamingConvention_lcrocket.asm
;Lucas Crockett
;Status: Working!

INCLUDE Irvine32.inc

Str_length PROTO

.data
string1 BYTE "Eat your beans!", 0
string2 BYTE "jelly ", 0
insertPos BYTE 9

.code
main proc
Call stringCop
main endp

stringCop proc
PUSHAD

movzx ecx, insertPos
mov al, string1
mov ebx, 1

L1:
	call WriteChar
	mov al, [string1+ebx]
	inc ebx
	loop L1

	INVOKE Str_length,
		ADDR string2
	mov ecx, eax
	mov al, string2
	mov ebx, 1
L2:
	call WriteChar
	mov al, [string2+ebx]
	inc ebx
	loop L2

	INVOKE Str_length,
		ADDR string1
	sub eax, DWORD PTR insertPos
	movzx ebx, insertPos
	mov ecx, eax
	mov al, [string1+ebx]
L3:
	call WriteChar
	inc ebx
	mov al, [string1+ebx]
	loop L3


POPAD
ret
stringCop endp

end main