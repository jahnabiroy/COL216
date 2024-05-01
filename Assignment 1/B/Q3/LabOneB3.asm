.data
info:	.asciz "JAHNABI ROY; 2022CS11094; LAB 1B Q3\n"
n1:	.asciz "Enter: "
arr:	.word 64
arr2:	.word 64
op:     .word 64
.text
.globl main
main:	
	li a7, 4
	la a0, info
	ecall
	
	li a7, 4
	la a0, n1
	li a1, 64
	ecall
	
	li a7, 8
	mv a0, sp
	ecall
	
	mv a1, a0
	li a0, 97
	lb s4, 0(a1)	# stores the first letter of the operation
	sub s4, s4, a0
	addi a1, a1, 3

	li t0, 32	# space
	li s0, 48	# '0'
	li s8, 45	# negative
	li t6, 10
	li t5, 0
	li s2, 0
	la a2, arr
	li a5, 1
	
loop:	lb t3, 0(a1)
	sub t4, t3, t0
	sub s5, t3, s8
	
	beq s5, zero, part
	addi t5, t5, 1
	beq t4, zero, new_reg
	beq t3, t6, loop_exit
	sub t3, t3, s0
	
	mul s2, s2, t6
	add s2, s2, t3
	
	addi a1, a1, 1
	addi a2, a2, 1
	
	
	j loop
	
part:   li a5, -1
	addi a1, a1, 1
	j loop
	
new_reg: la a2, arr2
	 mv s3, s2
	 mul s3, s3, a5
	 li s2, 0
	 addi a1, a1, 1
	 j loop
	
loop_exit:
	mul s2, s2, a5	
	
	beq s4, zero, addition
	li t0, 3
	beq s4, t0, division
	li t0, 12
	beq s4, t0, mult
	li t0, 18
	beq s4, t0, subt
	
addition: add a0, s3, s2
	  li a7, 1
	  ecall
	  j exit
	  
division: div a0, s3, s2
	  li a7, 1
          ecall
	  j exit
	  
mult:	  mul a0, s3, s2
	  li a7, 1
	  ecall
	  j exit

subt:	  sub a0, s3, s2
	  li a7, 1
	  ecall
	  j exit
	
exit:   li a7, 93
	li a0, 0
	ecall
