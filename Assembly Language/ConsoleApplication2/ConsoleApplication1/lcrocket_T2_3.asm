;//Due to time constraints I was unable to implement proper formatting.  I had also not properly incremented ebx within L2, resulting in each line having one character repeated.
;Lucas Crockett
;Status: Not working

INCLUDE Irvine32.inc

.data
Str1 BYTE "tango", 0
Str1Size DWORD 5 ;Fine

.code
main proc
	mov esi, OFFSET Str1
	mov eax, Str1Size
	call PyraWrite

	exit
main endp

PyraWrite proc
PUSHAD
PUSHFD

mov ecx, eax			;Sets loop counter to length of Str1
mov ebx, 0				;Index for looping
mov dh, 1				;Coordinates for cursor
mov dl, 40

L1:
	call Gotoxy
	PUSH ecx			;Pushes ecx for inline loop
	mov ecx, ebx
	inc ecx
	PUSH ebx
	mov ebx, 0
L2:						;Print out characters on each line
	mov al, [esi+ebx]
	call WriteChar
	mov al, 20h
	call WriteChar
	inc ebx
	loop L2

	call Crlf

	POP ebx
	POP ecx
	inc dh
	dec dl
	inc ebx
	loop L1

POPFD
POPAD
ret
PyraWrite endp
end main