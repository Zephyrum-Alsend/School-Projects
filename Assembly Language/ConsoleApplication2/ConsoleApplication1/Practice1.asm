;Chapter 9 #3
;Status: First line of Len: loop makes an illegal call to memory.

INCLUDE Irvine32.inc

.data
Str1 BYTE "abcxxxxdefghijklmnopqrstuvwxyz", 0
Str2 BYTE 80 DUP (0)

.code
main proc
	mov edx, OFFSET [Str1+3]
	mov eax, 4
	call Str_remove

	mov edx, OFFSET Str1
	call WriteString

	exit
main endp

Str_remove proc
	PUSHAD
	PUSHFD

	mov esi, 0		;ESI used to track length of the passed string.
	mov ecx, 80		;80 is the length of the empty string for copying. Cannot edit a passed string longer than the buffer.
Len:
	mov bl, [edx+esi]
	cmp bl, 0
	inc esi
	je LenGet		;Prematurely end loop if end of passed string found.
	loop Len

LenGet:
	dec esi			;Counted null terminator so decrement ESI.
	
	mov ecx, esi
	mov edi, 0		;ESI used as index for strings.
	add edx, eax	;Changes address passed in EDX to after the undesired characters.
	;Copies desired part of passed string to empty string.
L1:
	mov bl, [edx+edi]
	mov [Str2+edi], bl
	inc edi
	loop L1

	mov ecx, esi
	mov edi, 0
	sub edx, eax	;Changes address in EDX back to the passed address.
	;Copies the copied string segment into the passed string, overwriting the undesired segment.
L2:	
	mov bl, [Str2+edi]
	mov [edx+edi], bl
	inc edi
	loop L2

	POPAD
	POPFD
	ret
Str_remove endp
end main