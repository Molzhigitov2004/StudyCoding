.data 
	ExitString: .asciiz "The number of arguments is not 3. Program finished."
	newLine: .asciiz "\n"	#nextLine character
	String: .asciiz "String:" #String prompt
	Length: .asciiz "Length:" #Length prompt
	X: .asciiz "X:" #X prompt
	Char: .asciiz "Char:" #Char prompt
	Match: .asciiz "Match:" #Match prompt
	InvalidSymbol: .asciiz "Invalid symbol found among arguments:" #InvalidSymbol prompt
	
.text 
main: 
	li $t0, 3 #load 3
	bne $a0, $t0, Not3Exit #check if there is 3 arguments
	
	addiu $sp, $sp, -16 #Adjusting stack pointer
	sw $s0, 0($sp) #Save $s0
	sw $s1, 4($sp) #Save $s1
	sw $s2, 8($sp) #Save $s2
	sw $s3, 12($sp) #Save $s3
	lw $t0, 0($a1) #loading string to $t1 to check validity
	jal StringChecker
	lw $s0, 0($sp) #Restore $s0
	lw $s1, 4($sp) #Restore $s1
	lw $s2, 8($sp) #Restore $s2
	lw $s3, 12($sp) #Restore $s3
	addiu $sp, $sp, 16 # Deallocate stack space (restore stack pointer)
	
	addiu $sp, $sp, -16 #Adjusting stack pointer
	sw $s0, 0($sp) #Save $s0
	sw $s1, 4($sp) #Save $s1
	sw $s2, 8($sp) #Save $s2
	sw $s3, 12($sp) #Save $s3
	lw $t0, 8($a1)
	jal StringChecker
	lw $s0, 0($sp) #Restore $s0
	lw $s1, 4($sp) #Restore $s1
	lw $s2, 8($sp) #Restore $s2
	lw $s3, 12($sp) #Restore $s3
	addiu $sp, $sp, 16 # Deallocate stack space (restore stack pointer)
	
	addiu $sp, $sp, -16 #Adjusting stack pointer
	sw $s0, 0($sp) #Save $s0
	sw $s1, 4($sp) #Save $s1
	sw $s2, 8($sp) #Save $s2
	sw $s3, 12($sp) #Save $s3
	lw $t0, 4($a1)
	jal DigitChecker
	lw $s0, 0($sp) #Restore $s0
	lw $s1, 4($sp) #Restore $s1
	lw $s2, 8($sp) #Restore $s2
	lw $s3, 12($sp) #Restore $s3
	addiu $sp, $sp, 16 # Deallocate stack space (restore stack pointer)
	
	lw $a0, 0($a1) #loading  string to $a0
	
	addiu $sp, $sp, -16 #Adjusting stack pointer
	sw $s0, 0($sp) #Save $s0
	sw $s1, 4($sp) #Save $s1
	sw $s2, 8($sp) #Save $s2
	sw $s3, 12($sp) #Save $s3
	jal getStringLength #calling procedure for String length
	lw $s0, 0($sp) #Restore $s0
	lw $s1, 4($sp) #Restore $s1
	lw $s2, 8($sp) #Restore $s2
	lw $s3, 12($sp) #Restore $s3
	addiu $sp, $sp, 16 # Deallocate stack space (restore stack pointer)
	
	
	lw $a0, 0($a1) #loading first string to $a0
	lw $s1, 4($a1) #loading x to $s1
	lb $a2, 0($s1) #loading first byte
	addi $a2, $a2, -48 #converting it to integer
	lw $s2, 8($a1) #loading ch
	lb $a3, 0($s2) #converting it to character
	move $a1, $s3 #loading length to $a1
	
	addiu $sp, $sp, -16 #Adjusting stack pointer
	sw $s0, 0($sp) #Save $s0
	sw $s1, 4($sp) #Save $s1
	sw $s2, 8($sp) #Save $s2
	sw $s3, 12($sp) #Save $s3
	jal checkOccurrences #calling procedure checkOccurrences
	lw $s0, 0($sp) #Restore $s0
	lw $s1, 4($sp) #Restore $s1
	lw $s2, 8($sp) #Restore $s2
	lw $s3, 12($sp) #Restore $s3
	addiu $sp, $sp, 16 #Deallocate stack space (restore stack pointer)
	
	
    	j Exit # Jump to exit
DigitChecker:
	li $t6, 48 #loading range
	li $t5, 57 #loading range
	lb $s2, ($t0) #load digit
	blt $s2, $t6, InvalidSymbolExit #checking range
	bgt $s2, $t5, InvalidSymbolExit #checking range
	jr $ra #return statement
	
StringChecker:
	move $s1, $t0 #load string
	lb $s2, 0($s1) #load character
	addiu $sp, $sp, -4 #adjust stack pointer
	sw $ra, 0($sp) #save return address

check_string_loop:
	beqz $s2, end_check_string #if string is ended exit loop
	jal IsCharacter #go to check char function
	addi $s1, $s1, 1 #move to the next character
	lb $s2, 0($s1) #load that character
	j check_string_loop #loop jump statement
	
end_check_string:
	lw $ra, 0($sp) #get saved return address
	addiu $sp, $sp, 4 #adjust back stack pointer
	jr $ra #return statement

IsCharacter:
	li $t2, 65 #load range
	li $t3, 90 #load range
	li $t4, 97 #load range
	li $t5, 122 #load range
	
	blt $s2, $t2, InvalidSymbolExit #check range
	bgt $s2, $t5, InvalidSymbolExit #check range
	bgt $s3, $t3, check_lower_case #check range of that window between intervals
	jr $ra #return statement
	
check_lower_case:
	blt $s2, $t4, InvalidSymbolExit #check lower boundary of that window
	jr $ra #return statement
	
InvalidSymbolExit: 
	li $v0, 4 #get ready to print string
	la $a0, InvalidSymbol #load address of string
	syscall #print string
	
	li $v0, 11 #get ready to print character
	li $t7, 39 #load ASCII value for '
	move $a0, $t7 #move it to $a0
	syscall #print '
	
	li $v0, 11 #get readu to print character
	move $a0, $s2 #move it to $a0
	syscall #print it
	
	li $v0, 11 #get ready to print character
	li $t7, 39 #load ASCII value for '
	move $a0, $t7 #move it to $a0
	syscall #print '
	
	li $v0, 10 #get ready to end program
	syscall #exit program

getStringLength:
	li $s0, 0 #creating counter for length
	move $s1, $a0 #loading string 
length_loop:
    	lb $s2, 0($a0) #loading character        
    	beqz $s2, end_length #check if character is null
    	addi $s0, $s0, 1 #increment counter        
    	addi $a0, $a0, 1 #move to the next character      
    	j length_loop    #loop       
end_length:

	li $v0, 4 #Prepare to print a string
	la $a0, String #load address
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	move $a0, $s1 #load address
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, newLine #load address
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, Length #load address
	syscall #print
	
	li $v0, 1 #Prepare to print a integer
	move $a0, $s0 #load integer
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, newLine #load address
	syscall #print
	         
    	jr $ra #return to call address
	
checkOccurrences:
	move $s0, $a0 #we will use $a0 for printing, so we stored it in $s0

	 
	li $v0, 4 #Prepare to print a string
	la $a0, X #load address
	syscall #print
	
	li $v0, 1 #Prepare to print a int
	move $a0, $a2 #load int
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, newLine #load address
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, Char #load address
	syscall #print
	
	li $v0, 11 #Prepare to print a character
	move $a0, $a3 #load character
	syscall #print
	
	li $v0, 4 #Prepare to print a string
	la $a0, newLine #load address
	syscall #print
	
	move $s1, $zero #Occurrence to 0
    	move $s2, $s0 #move first string to $s2
    	
count_loop:
    	lb $s3, 0($s2) #Get character
    	beqz $s3, end_count #If character is null go to end_count
    	beq $s3, $a3, increment #If character matches $a3 go to increment counter
    	j skip_increment #Skip incrementing

increment:
    	addi $s1, $s1, 1 #Increment the occurrence counter

skip_increment:
    	addi $s2, $s2, 1 #Move to the next character
    	j count_loop #loop

end_count:
	li $v0, 4 #Prepare to print a string
	la $a0, Match #load address
	syscall #print
	
	beq $s1, $a2, EndMatch1 #check if occurrence equals x
	
	li $v0, 1 #Prepare to print int       
    	li $a0, 0 #0 - false 
    	syscall #print
    	
    	jr $ra
EndMatch1:
	li $v0, 1 #Prepare to print int          
    	li $a0, 1 #1 - true     
    	syscall #print    
	
    	jr $ra #return to call address

    	
Not3Exit: #Exit when there paramters count is not equal to 3
	li $v0, 4 #prepare to print string
	la $a0, ExitString #load address of ExitString
	syscall #print
Exit: #Standard Exit
	li $v0, 10 # Prepare to exit the program
	syscall #exit program
