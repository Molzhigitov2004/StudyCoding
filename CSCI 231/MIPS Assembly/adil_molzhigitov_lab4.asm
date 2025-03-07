.data
	newLine: .asciiz "\n"	#nextLine character
	Space: .asciiz " " #space character 
	ConstructedWord: .space 12 #11 characters + null terminator for ConstructedWord

.text
main:
	move $t0, $a0 #Store quantuty of arguments
	move $t3, $a0 #Store quantuty of arguments
	li $v0, 1 #get ready to print quantity of the arguments
	move $a0, $t0 #move quantity of the argumentsto $a0
	syscall #printing quantity of the arguments
	
	beq $t0, $zero, ExitZero #if no arguments we call another Exit
	
	li $v0, 4 #get ready to print string
	la $a0, newLine #print \n
	syscall #printing new line character
	
	move $t1, $a1 #load base adress to $t1
	
PrintArgs:
	beq $t0, $zero, ConstructWord #finish loop if no arguments left
	
	lw $t2, 0($t1) #get address of argument to $t2
	li $v0, 4 #get ready to print argument
	move $a0, $t2 #move argument to $a0
	syscall #print argument
	
	
	li $v0, 4 #get ready to print string
	la $a0, Space #print " "
	syscall #print space between arguments
	
	addi $t1, $t1, 4 #move to the next pointer
	addi $t0, $t0, -1 #decrement counter
	j PrintArgs  #unconditional jump back to loop
	
ConstructWord:
	addi $t0, $zero, 0 #make counter
	move $t1, $a1 #get base address
	
ConstructLoop:
 	beq $t0, $t3, Exit #when all characters stored go to Exit
 	
 	lw $t2, 0($t1) #base adress of argument
 	add $t2, $t2, $t0 #calculated address of character
 	
 	lb $t4, ($t2) #load character
 	sb $t4, ConstructedWord($t0) #save character
 	
 	addi $t1, $t1, 4 #increment base address to next argument
 	addi $t0, $t0, 1 #increment iterator
 	j ConstructLoop #unconditional jump back to loop

Exit:
	li $v0, 4 #get ready to print string
	la $a0, newLine #print \n
	syscall #printing new line character
	
	sb $zero, ConstructedWord($t0) #add null terminator
	li $v0, 4 #get ready to print string
	la $a0, ConstructedWord #load adress of ConstructedWord
	syscall #print ConstructedWord
    	
	li $v0, 10 #exit programm
	syscall #thats all
ExitZero:
	li $v0, 10 #exit programm
	syscall #thats all
	
	
