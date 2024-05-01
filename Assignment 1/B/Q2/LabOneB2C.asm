# C - iterative
.data
info:	.asciz "JAHNABI ROY; 2022CS11094 - LAB 1B Q2 C\n"
n:	.asciz "Enter n: "
.text
.globl main
main:
	li a7, 4
	la a0, info
	ecall
	
	li a7, 4
	la a0, n
	ecall
	
	li a7, 5
	mv a0, sp
	li a1, 64
	ecall
	
	mv t0, a0
	li t1, 0
acc:	add t1, t0, t1
	addi t0, t0 -1
	bne t0, zero, acc
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 93
	li a0, 0
	ecall