;//Within the isPalindrome proc I had changed used registers in some areas without updating all locations and had an incorrect index for the last character.
;Lucas Crockett
;Status: Working

INCLUDE Irvine32.inc

.data
Sentence BYTE "papa", 0
SentenceSize DWORD 4					;Fine
Corr BYTE " is a palindrome.", 0
Wron BYTE " is not a palindrome.", 0

.code
main proc
	mov edx, 0
	mov edx, OFFSET Sentence
	mov eax, SentenceSize
	call isPalindrome
	exit
main endp

isPalindrome proc
	PUSHAD
	PUSHFD

	mov ebx, eax		;Preserves length value

	SHR eax, 1			;Divides eax by 2

	mov ecx, eax		;Set half length as loop counter
	mov eax, ebx		;Move full length back into eax
	dec eax				;Use eax as index for last character
	mov esi, 0			;First character index
L1:			
	mov bl, [edx+esi]	;Copy first character of Str1 into bl
	PUSH ecx
	mov cl, [edx+eax]	;Copy last character of Str1 into bh
	cmp bl, cl			;Compare characters
	jne notTrue			;If bh and bl ever not match, isNotPalindrome
	POP ecx
	inc esi
	dec eax
	loop L1

	;Message display if word is a palindrome
	mov edx, OFFSET Sentence
	call WriteString
	mov edx, OFFSET Corr
	call WriteString
	jmp Done

	;Message display if word is not a palindrome
notTrue:
	mov edx, OFFSET Sentence
	call WriteString
	mov edx, OFFSET Wron
	call WriteString

Done:

	POPFD
	POPAD
	ret
isPalindrome endp
end main