; Homework 3.2
; Lucas Crockett
; 

INCLUDE irvine32.inc

.data
	array SBYTE 26, -81, -104, -57
	total_sum SWORD ?

.code
main2 proc
	mov eax, 0				;clear eax
	mov ebx, 0				;clear ebx
	mov esi, 0				;index
	mov ecx, 4				;loop counter

L1:
	movsx bx, array[esi]	;preserves sign of value		;Attempted addition straight to al, overflow data (and thus sign) not carried into ah
	add ax, bx				;intermediate sums stored in ax
	inc esi
	loop L1

	mov total_sum, ax		;transfers final sum (FF28h) to total_sum
	
	movsx eax, total_sum	;copies total_sum to eax for WriteInt function, preserves sign
	call WriteInt			;prints eax (-216d)

	exit
main2 endp
end main2