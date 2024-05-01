.data
info:	.asciz "JAHNABI ROY; 2022CS11094 - LAB 1B Q1\n"
n:	.asciz "Enter N: "
r:	.asciz "Enter R: "
ans:	.asciz "Combinatorial of N and R: "
.text
.global main
main:
	addi sp, sp, -64
	li a7, 4
	la a0, info
	ecall
	
	li a7, 4
	la a0, n
	ecall
	
	li a7, 5
	mv a0, sp
	li a1, 4
	ecall
	
	mv a2, a0
	
	li a7, 4
	la a0, r
	ecall
	
	li a7, 5
	mv a0, sp
	li a1, 4
	ecall
	
	mv a3, a0
	
	sub a4, a2, a3
	
	li t0, 1
	li t2, 0
	mv t1, a2
	
fact:	addi t2, t2, 1
	mul t0, t0, t2
	bne t2, t1, fact
	
	mv a2, t0
	
	li t0, 1
	li t2, 0
	mv t1, a3
	
fact2:	addi t2, t2, 1
	mul t0, t0, t2
	bne t2, t1, fact2
	
	mv a3, t0
	
	li t0, 1
	li t2, 0
	mv t1, a4
	
fact3:	addi t2, t2, 1
	mul t0, t0, t2
	bne t2, t1, fact3
	
	mv a4, t0
	
	mul a3, a3, a4
	div a2, a2, a3
	
	li a7, 4
	la a0, ans
	ecall
	
	li a7, 1
	mv a0, a2
	ecall
	
	addi sp, sp, 64
	
	li a7, 93
	li a0, 0
	ecall
