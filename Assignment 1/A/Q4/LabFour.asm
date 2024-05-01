.data
info: .asciz "JAHNABI ROY, 2022CS11094; LAB 1A Q5\n"
Q_assumption: .asciz "Takes binary numbers in reverse and prints answer in reverse.\n"
newline: .asciz "\n"
no: 	.asciz "0101000011100011001001000000111000000001101010101010000011110111010100001110000000000000000011100000000110000000101000000000011101010000111000000000000000001110000000011000000010100000000001110101000011100000000000000000111000000001100000001010000000000111"
no2:	.asciz "1100100100011000000001110001010000001010000001110000000000000110101010101010101010101010101010100101010101010101010100101010101010101010100101010101010101010100101010101010101010100101010101010101010100101010101010101010100101010101010101010100101010101010"

.text
.global main
main:
	addi sp, sp, -64
	li t3, 0	# indexing
	li t1, 256
	li s0, 48
	li a5, 0	# carrying

	li a7, 4
	la a0, info
	ecall
	
	li a7, 4
	la a0, Q_assumption
	ecall
	
	li a7, 4
	la a0, no
	ecall
	
	la a2, no
	
	li a7, 4
	la a0, newline
	ecall
	
	li a7, 4
	la a0, no2
	ecall
	
	la a3, no2
	
	li a7, 4
	la a0, newline
	ecall
	
loop:	lb t4, 0(a2)
	sub t4, t4, s0
	
	lb t5, 0(a3)
	sub t5, t5, s0
	
	addi a2, a2, 1
	addi a3, a3, 1
	
	add t6, t4, t5
	add t6, t6, a5
	
	li a0, 2
	div t2, t6, a0
	beq t2, zero, case1 	# 0/1
	bne t2, zero, case2		#2/3
	
case1:	li a7, 1
	mv a0, t6
	ecall
	
	li a5, 0
	addi t3, t3, 1
	bne t3, t1, loop
	j exit
	
case2:	li a0, 3
	beq t6, a0, case4
	
	li a7, 1
	mv a0, zero
	ecall
	
	li a5, 1
	addi t3, t3, 1
	bne t3, t1, loop
	j exit
	
case4:	li a7, 1
	li a0, 1
	ecall

	li a5, 1
	addi t3, t3, 1
	bne t3, t1, loop
	j exit
	
exit:	li a7, 1
	mv a0, a5
	ecall
	
	addi sp, sp, 64
		
	li a7, 93
	li a0, 0
	ecall
