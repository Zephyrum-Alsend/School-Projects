;Testprac.asm
;Lucas Crockett
;Status: May forget to change this

INCLUDE Irvine32.inc

Str_copy PROTO,
	source: PTR BYTE,
	target: PTR BYTE

Str_length PROTO,
	pString: PTR BYTE

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

INVOKE Str_length,
	ADDR string1

movzx ecx, insertPos
mov edx, OFFSET string1

L1:
	call WriteChar
	inc edx
	loop L1

POPAD
stringCop endp
end main