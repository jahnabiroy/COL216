.data 
info: .asciz "JAHNABI ROY, 2022CS11094; Lab 1A Q2. Enter Numbers One after Another.\n"
newline: .asciz "\n"
arr: .word 40    # assuming integer array


.text
.globl main
main:
	addi sp, sp, -64
	li t0, 0
	li, t1, 10
	li t4, 0
	
	li a7, 4
	la a0, info
	ecall
	
loop:	li a7,5
	mv a0, sp
	ecall
	
	la t2, arr
	slli t3, t0, 2
	add t2, t2, t3
	
	sw a0, 0(t2)	# stores into t2/ arr
	
	addi t0,t0,1
	
	bne t0, t1, loop
	
loop2: 	la t5, arr
	slli t6, t4,2
	add t5, t5, t6
	lw a0, 0(t5)	# accessing the array
	
	addi t4,t4,1
	add a2, a2, a0
	
	bne t4, t1, loop2
	
	li a7, 4
	la a0, newline
	ecall
	
	li a7, 1
	mv a0, a2
	ecall
	
	addi sp, sp, 64
	
	li a7, 93
	li a0, 0
	ecall
	

	
	
	
