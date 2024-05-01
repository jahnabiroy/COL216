#  Read a 10 character alphanumeric string X. Print a string that contains one letter from your name 
# followed by 1 letter/number from X.

.data
info: .asciz "JAHNABI ROY, 2022CS11094; Lab 1A Q3.\n"
prompt1: .asciz "X is: "
prompt: .asciz "String is: "
newline: .asciz "\n"
name: .asciz "JAHNABIROY"

.text
.globl main
main:
    addi sp, sp, -64
    
    li t0, 0
    li t1, 10

    li a7, 4
    la a0, info
    ecall
    
    li a7, 8
    mv a0, sp
    li a1, 11
    ecall

    li a7, 4
    la a0, newline
    ecall
    
loop: 	la t2, name
      	mv t3, sp	   
      	
      	add t2, t2, t0
      	add t3, t3, t0
      	
	lb a0, 0(t2)
	li a7, 11
	ecall
	
	lb a0, 0(t3)
	li a7, 11
	ecall
	
	addi t0, t0, 1
	bne t0, t1, loop  
    
    addi sp, sp, 64
    
    li a7, 93
    li a0, 0
    ecall
