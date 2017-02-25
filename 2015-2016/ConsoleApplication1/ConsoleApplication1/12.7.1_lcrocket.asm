;Floating Practice
;Lucas Crockett
;Status: Working

INCLUDE Irvine32.inc

.data
X REAL8 ?
Y REAL8 ?
repor1 BYTE "X is lower", 0dh, 0ah, 0
repor2 BYTE "X is not lower", 0dh, 0ah, 0

.code
main proc
	FLD X
	FLD Y
	FCOMPP
	FNSTSW ax
	SAHF
	JNB LESS
	mov edx, OFFSET repor2
	call WriteString
	jmp done
LESS:
	mov edx, OFFSET repor1
	call WriteString
done:
	exit
main endp
end main