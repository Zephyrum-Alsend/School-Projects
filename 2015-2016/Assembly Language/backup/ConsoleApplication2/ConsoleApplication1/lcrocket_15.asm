INCLUDE Irvine32.inc

.data
Str1 BYTE "Hello, I'm fine.", 0

.code
RandomColor proc
	PUSHFD

	cmp eax, 3
	jl Whi
	cmp eax, 4
	jl Blu
	mov ax, green + (black*16)
	jmp done
Whi:
	mov ax, white + (black*16)
	jmp done
Blu:
	mov ax, blue + (black*16)
	jmp done
done:
	call SetTextColor

	POPFD
	ret
RandomColor endp

RandomNum proc
	PUSHFD

	mov eax, 10
	call RandomRange
	call RandomColor

	POPFD
	ret
RandomNum endp

main proc
	call Randomize
	mov edx, OFFSET Str1
	
	mov ecx, 20
L1:
	call RandomNum
	call WriteString
	call Crlf
	loop L1

	exit
main endp
end main