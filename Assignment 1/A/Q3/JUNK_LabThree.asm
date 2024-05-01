#  Read a 10 character alphanumeric string X. Print a string that contains one letter from your name 
# followed by 1 letter/number from X.

.data
info: .asciz "JAHNABI ROY, 2022CS11094; Lab 1A Q3.\n"
prompt1: .asciz "X is: "
prompt: .asciz "String is: "
newline: .asciz "\n"
letter: .asciz "J"
str: .space 40

.text
.globl main
main:
    addi sp, sp, -64

    li a7, 4
    la a0, info
    ecall

    li a7, 4
    la a0, prompt1
    ecall
    
    li a7, 8
    mv a0, sp
    li a1, 11
    ecall

    li a7, 4
    la a0, newline
    ecall
    
    li a7, 4
    la a0, prompt
    ecall

    li a7, 4
    la a0, letter
    ecall

    lb a0, 5(sp)  
    
    li a7, 11
    ecall
    
    addi sp, sp, 64
    
    li a7, 93
    li a0, 0
    ecall
