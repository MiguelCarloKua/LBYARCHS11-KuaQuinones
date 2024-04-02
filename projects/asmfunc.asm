;Miguel Carlo Kua, Angelo Yanto Quinones S11
section .text
global dotProduct86

dotProduct86:
    ; Parameters are passed in registers: rcx, rdx, r8
    ; rcx contains the address of the float array A
    ; rdx contains the address of the float array B
    ; r8 contains the value of n where n is the size of the vector (array)

    ;set the values of xmm0; rax to zero
    ;readying them for data handling
    xorps xmm0, xmm0
    xor rax, rax

    dotProLP:
    cmp rax, r8
    ;go to end if the counter is equal or greater than the n
    jge end

    ;move the value of the array A (rcx) to xmm1
    movss xmm1, [rcx + rax * 4]
    ;multiply the value of the array B (rdx) with xmm1 (array A) and store it in xmm1
    mulss xmm1, [rdx + rax * 4]
    ;add the value of xmm1 to previous value of xmm0
    addss xmm0, xmm1

    ;incement the counter
    inc rax
    ;repeat the loop
    jmp dotProLP

    end:
    ;return xmm0 to the C program
    ret