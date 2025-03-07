.data
	prompt: .asciiz "Enter yout age: "
	message: .asciiz "\nYour age is "
.text
	#prompt the user
	li $v0, 4
	la $a0, prompt
	syscall
	
	#get input
	li $v0, 5
	syscall
	
	#store the result in $t0
	move $t0, $v0
	
	#display the message
	li $v0, 4
	la $a0, message
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	