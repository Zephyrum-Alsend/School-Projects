;HW 5 - Question 2 - Grade Book
;Lucas Crockett

INCLUDE Irvine32.inc

.data


.code
CalcGrade proc
	PUSHFD					;Preserves flags b/c using CMP. Only eax is tampered with so other registers not PUSHed
	
	cmp eax, 60d			;Compares value to a threshold and jumps to appropriate label if value falls below
	jl Fail
	cmp eax, 70d
	jl Dumb
	cmp eax, 80d
	jl Crap
	cmp eax, 90d
	jl Burn
	mov al, 41h				;Value is 90+ by elimination, just move 'A' into al
	jmp done
Fail:
	mov al, 46h				;Grade is 'F'
	jmp done
Dumb:
	mov al, 44h				;Grade is 'D'
	jmp done
Crap:
	mov al, 43h				;Grade is 'C'
	jmp done
Burn:
	mov al, 42h				;Grade is 'B'
	jmp done
done:
	
	POPFD
	ret
CalcGrade endp

GenRandInt proc
	PUSHFD					;Preserve flags as a precaution. Only eax is tampered with so other registers not PUSHed
	
	mov eax, 51				;Generates random integer between 50 - 100 inclusive
	call RandomRange
	add eax, 50
	
	POPFD
	ret
GenRandInt endp

main proc
	call Randomize			;Seeds randomizer
	mov ecx, 10				;Set loop counter to 10
L1:
	call GenRandInt
	call WriteInt			;Displays generated integer
	call CalcGrade
	call WriteChar			;Displays corresponding grade
	call Crlf
	loop L1

	exit
main endp
end main