/* Kua, Miguel Carlo F.; Quinones, Angelo Yanto LBYARCH S11 */

section .text
global dotProd86

dotProd86:
	
	; make values of xmm0 and rax zero
	xorps xmm0, xmm0
	xor rax, rax

dotProloop:
	; Parameters to be passed in regs
	; RCX: Float Array A
	; RDX: Float Array B
	; R8: n, or the size of the array/vector
	cmp rax, r8
	; terminate loop if n is equal to the counter
	jge end

	; 
	movss xmm1, [rcx + rax * 4]
	mulss xmm1, [rdx + rax * 4
	addss xmm0, xmm1

	; Increment the counter
	inc rax
	; Repeat Loop
	jmp dotProloop

end:
	; go to C program
	ret