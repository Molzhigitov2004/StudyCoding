.macro wait_display #Provided wait display
	lw $t0 DISPCTRL #load value from DISPCTRL to check if its ready
	display_loop:
		lw $t2 ($t0) #load it to the $t2
		andi $t2 $t2 1 #Checking least significant bit
		beqz $t2 display_loop #If it is still zero (not ready), loop
		
.end_macro

.macro wait_keyboard #Provided wait keyboard
	lw $t0 KBRDCTRL #load value from keyboard control
	keyboard_loop:
		lw $t2 ($t0) #move it to $t2
		andi $t2 $t2 1 #Checking least significant bit
		beqz $t2 keyboard_loop #If it is still zero (not ready), loo
.end_macro

.data #provided addresses and myprompts
	KBRDCTRL:		.word 0xffff0000
	KBRDDATA:		.word 0xffff0004
	DISPCTRL:		.word 0xffff0008
	DISPDATA:		.word 0xffff000c
	
	prompt1: .asciiz "This program calculates (A+B)/C.\n"
	prompt2: .asciiz "Enter A (positive integer or zero): "
	prompt3: .asciiz "Enter B (positive integer or zero): "
	prompt4: .asciiz "Enter C (positive integer or zero): "
	prompt5: .asciiz "Check result in MARS terminal window."
	nextLine: .asciiz "\n"
	InvalidPrompt: .asciiz "Input contains invalid character. Try again!\n"
	Result: .asciiz "Result: "
	ABC_overflow_prompt: .asciiz "Entered value exceeds the maximum possible value for 32-bit signed integer. Try Again!\n"
	No_You_CANT: .asciiz "You can not divide by zero.\n"
	input_buffer: .space 64 #I hope this size is enough
	AplusB_prompt: .asciiz "Entered values for A and B result in an arithmetic overflow.\n"
.text
main:
	la $a0, prompt1 #print first prompt
	jal print_string

promptA:	
	la $a0, prompt2  #print prompt to ask A
	jal print_string
	jal get_input #get users input as string
	la $a0, input_buffer #print entered string
	jal print_string #print entered string
	la $a0, nextLine #print next line
	jal print_string
	
	la $a0, input_buffer #Convert input to the integer value
	jal string_to_int
	move $s0, $v0 #save it in $s0

	
promptB:	
	la $a0, prompt3 #prompt to ask B
	jal print_string
	jal get_input #get user input as string
	la $a0, input_buffer 
	jal print_string #print it
	la $a0, nextLine #print next line
	jal print_string 

	la $a0, input_buffer #Convert input string to integer
	jal string_to_int
	move $s1, $v0 #save it in $s1
	add $s3, $s0, $s1 #checking for (A+B) overflow	
	bnez $s4, AplusBException	 #check if A+b exception occured																																																																																			
promptC:
	la $a0, prompt4 #ask user for C
	jal print_string
	jal get_input #get it as string
	la $a0, input_buffer #print it
	jal print_string
	la $a0, nextLine  #print \n
	jal print_string

	la $a0, input_buffer #convert it to the integer
	jal string_to_int
	teq $zero, $v0 #check if 0, if it is throw exception
	bnez $s5, ZeroException #checking for if there was exception by checking $s5 (this maybe be stupid)
	move $s2, $v0 #save value it in $s2
	
	la $a0, prompt5 #print prompt 5 about checking in MARS
	jal print_string	 
																															
	#Calculations as double																																																																																																																																																																																																																																																																																																																										
	mtc1 $s0, $f20
	cvt.d.w $f20, $f20 #saving A as double
	
	mtc1 $s1, $f22
	cvt.d.w $f22, $f22 #saving B as double
	
	mtc1 $s2, $f24
	cvt.d.w $f24, $f24 #saving C as double
	
	add.d $f4, $f20, $f22
	div.d $f4, $f4, $f24 #getting result of (A+B)/C
																																																																																																																																																																																																																																																																																																																													
	li $v0, 4 #print Result: 
	la $a0, Result
	syscall
	
	li $v0, 3 #print resulting value as double
	mov.d $f12, $f4
	syscall
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											
	li $v0 10 #exit the programm
	syscall


#prints string at $a0
print_string:
    	addi $sp, $sp, -4 #saving return address
    	sw $ra, 0($sp)
print_string_loop:
    	lb $t3, 0($a0) #get first byte
    	beqz $t3, exit_print_string #if it is \0 exit
	
	lw $t1, DISPDATA #load displaydata address
    	wait_display #wait untill its ready
    	sw $t3, ($t1) #save byte in it to print

    	addi $a0, $a0, 1 #move to the next byte
    	j print_string_loop #loop

exit_print_string:
    	lw $ra, 0($sp) #restore $ra
    	addi $sp, $sp, 4
    	jr $ra #return



#Gets input as a string
get_input:
    	addi $sp, $sp, -4 #store $ra
    	sw $ra, 0($sp)
	lw $t3, KBRDDATA #get adress of keyboard data
	la $t7, input_buffer #safe address of input_buffer
	li $t5, 10 #value of \n
get_input_loop:
	wait_keyboard #wait till its ready
	lb $t4, 0($t3) #load first byte
	beq $t4, $t5, exit_get_input #if it is Enter exit
    	sb $t4, 0($t7) #save it in buffer
    	addi $t7, $t7, 1 #move to the next in buffer
	j get_input_loop #loop
exit_get_input:
    	lw $ra, 0($sp) #restore $ra
    	addi $sp, $sp, 4
	sb $zero, 0($t7) #zero terminate buffer 
	jr $ra #return

string_to_int: #this procedure convert string to int and checks it
    	addi $sp, $sp, -4 #store $ra
    	sw $ra, 0($sp)
	li $v0, 0 #$v0 will be result, set to 0 to start
	li $t9, 10 #value to mul
	li $t0, 48 #bound1
	li $t1, 57 #bound2
string_to_int_loop:
	lb $t8, 0($a0) #get first byte
	beqz $t8, string_to_int_end #if its \0 exit
	
	blt $t8, $t0, InvalidInput #check if its digit
	bgt $t8, $t1, InvalidInput #check if its digit
	
	subi $t8, $t8, 48 #convert to integer
	mulo $v0, $v0, $t9 #mul * 10, and check for overflow
	bnez $s6, ABC_overflow_handler #if overflow happened go to  the special method
	add $v0, $v0, $t8 #add that also checks for overflow
	bnez $s6, ABC_overflow_handler #if overflow happened go to  the special method
	addi $a0, $a0, 1 #move to the next byte
	j string_to_int_loop #loop
string_to_int_end:
    	lw $ra, 0($sp) #restore $ra
    	addi $sp, $sp, 4
	jr $ra #return 

InvalidInput:
	la $a0, InvalidPrompt #print invalid prompt
	jal print_string 
	beqz $s0, promptA #check where we need to  go  based on which value is still not obtained
	beqz $s1, promptB
	beqz $s2, promptC
ABC_overflow_handler: 
	li $s6, 0 #set special register back to 0
	la $a0, ABC_overflow_prompt #print overflow prompt
	jal print_string
	beqz $s0, promptA #check where we need to  go  based on which value is still not obtained
	beqz $s1, promptB
	beqz $s2, promptC
ZeroException: 
	li $s5, 0 #reset special register back to the 0
	la $a0, No_You_CANT #print You cant divide by 0
	jal print_string
	j promptC #jump back to the asking C 
AplusBException: 
	li $s4, 0 #set special register back to 0
	la $a0, AplusB_prompt #print that prompt
	jal print_string
	j promptA #go back to asking A and B