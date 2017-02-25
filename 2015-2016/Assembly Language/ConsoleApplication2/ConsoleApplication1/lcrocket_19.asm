;Exercise 19
;Lucas Crockett
;Status: Working

INCLUDE Irvine32.inc

.data
targetStr BYTE "String of ", 20 DUP (0)
sourceStr BYTE "characters.", 0

.code
main proc
	mov edi, OFFSET targetStr
	mov esi, OFFSET sourceStr
	mov edx, OFFSET targetStr
	call Str_length
	call StrConcat
	mov edx, OFFSET targetStr
	call WriteString

	exit
main endp

StrConcat proc
	PUSH EAX
	PUSH EBX
	PUSH ECX
	PUSH EDX
	PUSHFD

	mov ecx, eax
	mov ebx, 0
L1:
	mov edx, [edi+ebx]
	cmp edx, 0
	je Copy
	inc ebx
	loop L1
Copy:
	;INVOKE Str_copy, ADDR [esi], ADDR [edi+ebx]

	sub eax, ebx
	mov ecx, eax
	mov eax, 0
L2:
	mov edx, [esi+eax]
	cmp edx, 0
	je Done
	mov [edi+ebx], edx
	inc eax
	inc ebx
	loop L2
Done:
	
	POPFD
	POP EDX
	POP ECX
	POP EBX
	POP EAX
	ret
StrConcat endp
end main