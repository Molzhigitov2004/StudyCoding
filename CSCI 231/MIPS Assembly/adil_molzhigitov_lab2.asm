.data
	prompt: .asciiz "Enter a num: " 
.text
	main:
		#Prompting the user
		li $v0, 4
		la $a0, prompt
		syscall
		
		#Getting users input
		li $v0, 5
		syscall
		
		#Storing users input
		move $t0, $v0
		
		#Introducing counter
		addi $t1, $zero, 0
	
	    	# Loading divisor 10
    		li $t2, 10 
    		
		#Check if input is 0
		beq $t0, $zero, ZeroCase
		
		#Check if input is negative
		bltz  $t0, NegativeCase
    		
	while:
		blez  $t0, exit #exit condition - if less or equal than zero
    		div $t0, $t2      # Divide $t0 by $t2(10)
    		mflo $t0          # Move the quotient back to $t0
		addi $t1, $t1, 1 #counter++
		j while	#jump to while, loop is done here
	exit:
		#prints the answer
		li $v0, 1
		move $a0, $t1
		syscall
	#Exit from programm
	li $v0, 10
	syscall
	
	#Handling zero
    	ZeroCase:
    		addi $t1, $t1, 1
    		j exit
    		
    	#Getting Absolute value
    	NegativeCase:
    		mul $t0, $t0, -1
    		j while
    		
  
    		
    		
    	
