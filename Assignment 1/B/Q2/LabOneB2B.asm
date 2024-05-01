.data
info:   .asciz "JAHNABI ROY; 2022CS11094 - LAB 1B Q2 B\n"
n:      .asciz "Enter n: "

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
    ecall
    
    jal acc  # Jump and Link to recursive function
    
    li a7, 1
    ecall
    
    li a7, 93
    li a0, 0
    ecall

acc:
    addi sp, sp, -16
    sw ra, 8(sp)
    sw a0, 0(sp)
    
    bge a0, zero, L1
    
    li a0, 0
    addi sp, sp, 16
    jr ra
    
L1:  addi a0, a0, -1
     jal acc
    
    addi t0, a0, 0
    lw a0, 0(sp)
    lw ra, 8(sp)
    addi sp, sp, 16
    
    add a0, a0, t0
    
    jr ra
