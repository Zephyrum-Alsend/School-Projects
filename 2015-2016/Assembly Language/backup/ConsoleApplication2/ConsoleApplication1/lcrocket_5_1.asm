;HW 5 - Question 1 - Hexadecimal Calculator
;Lucas Crockett

Include Irvine32.inc

.data
CaseTable BYTE '1'
	DWORD Process_A
EntrySize = ($ - CaseTable)
	BYTE '2'
	DWORD Process_B
	BYTE '3'
	DWORD Process_C
	BYTE '4'
	DWORD Process_D
	BYTE '5'
	DWORD Process_E
NumberOfEntries = ($ - CaseTable) / EntrySize
prompt BYTE "Press the following keys for their respective functions.", 0dh, 0ah,
			"1. x AND y", 0dh,0ah,
			"2. x OR y", 0dh,0ah,
			"3. NOT x", 0dh,0ah,
			"4. x XOR y", 0dh,0ah,
			"5. Exit", 0dh,0ah,0dh,0ah, 0

MenuError BYTE "Invalid keystroke.",0dh,0ah, 0
msgA BYTE "x AND y",0dh,0ah,
		  "Enter two hexadecimal numbers.", 0dh,0ah,0
msgB BYTE "x OR y",0dh,0ah,
		  "Enter two hexadecimal numbers.", 0dh,0ah,0
msgC BYTE "NOT x",0dh,0ah,
		  "Enter a hexadecimal number.", 0dh,0ah,0
msgD BYTE "x XOR y",0dh,0ah,
		  "Enter two hexadecimal numbers.", 0dh,0ah,0
msgE BYTE "Exiting...",0dh,0ah, 0

Temp SDWORD ?

.code
main proc
	jmp Start						;Skips error message for first input
Error:								;Displays error message
	mov edx, OFFSET MenuError
	call WriteString
Start:
	mov edx, OFFSET prompt			;Display prompt
	call WriteString
	call ReadChar					;User input
	mov ebx, OFFSET CaseTable		;Use ebx as a PTR to CaseTable
	mov ecx, NumberOfEntries		;Set ecx to 5 for looping
L1:
	cmp al, [ebx]					;Check input with CaseTable
	jne L2							;Cycle to next entry in CaseTable if input does not match
	call NEAR PTR [ebx + 1]			;Call function from CaseTable when user input is matched
	
	jmp L3
L2:
	add ebx, EntrySize
	loop L1
L3:
	cmp ecx, 1						;Checks ecx to determine if pressed key was (and then) 1 - 4 (jump to Start), 5 (continue to Exit), or a wrong key (jump to Error)
	jg Start
	jl Error
	exit
main endp

Process_A proc
	PUSH ecx						;Precaution to preserve ecx for check at L3
	
	mov edx, OFFSET msgA			;Prompts user for input and reminds which function called
	call WriteString
	call readHex					;User input, stores in Temp so can get 2nd number
	mov Temp, eax
	call readHex
	and eax, temp					;Performs AND operation, stores answer in eax
	call WriteHex					;Reports answer
	call Crlf

	POP ecx
	ret
Process_A endp

Process_B proc
	PUSH ecx						;Precaution to preserve ecx for check at L3
	
	mov edx, OFFSET msgB			;Prompts user for input and reminds which function called
	call WriteString
	call readHex					;User input, stores in Temp so can get 2nd number
	mov Temp, eax
	call readHex
	or eax, temp					;Performs OR operation, stores answer in eax
	call WriteHex					;Reports answer
	call Crlf

	POP ecx
	ret
Process_B endp

Process_C proc
	PUSH ecx						;Precaution to preserve ecx for check at L3
	
	mov edx, OFFSET msgC			;Prompts user for input and reminds which function called
	call WriteString
	call readHex					;User input
	not eax							;Performs NOT operation, stores answer in eax
	call WriteHex					;Reports answer
	call Crlf

	POP ecx
	ret
Process_C endp

Process_D proc
	PUSH ecx						;Precaution to preserve ecx for check at L3
	
	mov edx, OFFSET msgD			;Prompts user for input and reminds which function called
	call WriteString
	call readHex					;User input, stores in Temp so can get 2nd number
	mov Temp, eax
	call readHex
	xor eax, temp					;Performs XOR operation, stores answer in eax
	call WriteHex					;Reports answer
	call Crlf

	POP ecx
	ret
Process_D endp

Process_E proc
	mov edx, OFFSET msgE			;Displays exit message
	call WriteString
	ret
Process_E endp

end main