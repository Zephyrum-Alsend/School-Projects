; Homework 3.2
; Lucas Crockett
; 

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE irvine32.inc

.data
	array SBYTE 26, -81, -104, -57
	total_sum SWORD ?

.code
main2 proc
	
	invoke ExitProcess,0
main2 endp
end main2