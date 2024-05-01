.data
info:	.asciz "JAHNABI ROY; 2022CS11094 - LAB 1B Q2 A\n"
n:	.asciz "Enter n: "
acc:	.asciz "Enter acc: "
.text
.globl main
main:
	addi sp, sp, -8
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
	
	li a7, 4
	la a0, acc
	ecall
	
	li a7, 5
	mv a0, sp
	ecall

sum:	ble t0, zero, exit
	add a0, a0, t0
	addi t0, t0, -1
	jal sum
	
exit: 	li a7, 1
	ecall
	
	addi sp, sp, 8
	
	li a7, 93
	li a0, 0
	ecall
