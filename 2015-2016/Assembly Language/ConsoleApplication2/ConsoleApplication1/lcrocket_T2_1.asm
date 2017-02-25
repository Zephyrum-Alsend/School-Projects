;
;Lucas Crockett
;Status: 

INCLUDE Irvine32.inc

.data
	var1 WORD 4

.code
main proc
	;var1 fits in cx, zero extend so the math/answer is in ecx
	movzx ecx, var1
	;shift 6 bits (x64), add 9x
	shl ecx, 6
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	add ecx, DWORD PTR var1
	;Output to expedite testing
	mov eax, ecx
	call WriteInt
	
	exit
main endp
end main