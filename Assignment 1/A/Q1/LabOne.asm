.data
name: .asciz "Name : Jahnabi Roy.\n"
entry_number: .asciz "Entry Number : 2022CS11094.\n"

.text
.global main
main:
	li a7, 4
	la a0, name
	ecall
	
	li a7, 4
	la a0, entry_number
	ecall
	
	li a0, 0
	li a7, 93
	ecall
	
	