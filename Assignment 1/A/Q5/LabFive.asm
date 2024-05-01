.data
info: .asciz "JAHNABI ROY, 2022CS11094; Lab 1A Q5.\n"
prompt: .asciz "Enter an Integer: " 
ans: .asciz "Fibonacci number at that index: "

.text
.globl main
main:
	addi sp, sp, -64
	li a7, 4
	la a0, info
	ecall
	
	li a7, 5
	mv a0, sp
	ecall
	
	li a7, 1

	li t0, 0
	li t1, 1
	
	li t5, 1
	
	li a4, 0
	li a5, 1
	li a3, 0
			
loop:	beq a0, a4, L1
	beq a0, a5, L2
	
	add t2, zero, t1
	add t1, t1, t0
	mv t0, t2
	
	addi t5, t5, 1
	
	bne t5, a0, loop
	beq t5, a0, exit2

exit2:	add a3, t1, zero
	j exit

L1:	add a3, a3, t0
	j exit

L2:	add a3, a3, t1
	j exit
	
exit:	li a7, 1
	mv a0, a3
	ecall
	
	addi sp, sp, 64
	
	li a7, 93
	li a0, 0
	ecall
