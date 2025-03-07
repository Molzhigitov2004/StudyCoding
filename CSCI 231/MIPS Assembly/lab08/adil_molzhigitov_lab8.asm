.data
    	filename: .asciiz "matrix.txt" 
    	success: .asciiz "The file was successfully opened."
    	fail: .asciiz "Can't open the file."
    	user_prompt: .asciiz "Enter a number of double data type: "
    	not_found_prompt: .asciiz "The entered number was not found."
    	found_prompt: .asciiz "The entered number was found at ["
    	close_bracket: .asciiz "]"
    	open_bracket: .asciiz "["
    	dot: .asciiz "."
    	
    	buffer: .space 1024 #Buffer
    	double: .double 0.0 #Zero as double
    	int_10: .word 10 #Ten
    	double_10: .double 10.0 #ten as double
    	double_1.0: .double 1.0 #one as double
    	newline: .asciiz "\n" #new line
	
	#This lab was much more difficult than the previous one
	#I usually spend about 5-6 hours on lab
	#This time I spent more than 15 hours
	#But the satisfaction after its completion is worth it
.text
main:
    	li $v0, 13 #open file         
    	la $a0, filename     
    	li $a1, 0            
    	syscall

    	bltz $v0, file_open_error #check if successful
    	move $s0, $v0 #saving file descriptor

    	li $v0, 4 #print success message   
    	la $a0, success
    	syscall

    	li $v0, 14 #saving whole text in buffer   
    	move $a0, $s0 #passing descriptor    
    	la $a1, buffer #passing buffer
    	li $a2, 1024 #passing its size    
    	syscall

    	la $s2, buffer #saving address of buffer
    	#saving rows
    	lb $s3, 0($s2)      
    	subi $s3, $s3, 48  
    	addi $s2, $s2, 3  
    	#saving cols   
    	lb $s4, 0($s2)       
    	subi $s4, $s4, 48   
    	addi $s2, $s2, 3   

    	#calculating size
    	mul $t7, $s3, $s4
    	move $s7, $t7 #save size
    	move $t5, $t7 #save size for next part
    	li $t6, 8

    	#Allocating heap
    	li $v0, 9            
    	move $a0, $t7
    	syscall
    	move $s5, $v0 #saving base address heap
	move $s6, $s5 #saving base adress for next_part
	
    	#Initializing element counter
    	li $t0, 0 
    	
loop_through_buffer:
    	bge $t0, $s7, next_part #check if we got all elements
    
    	li $t6, 10 #ASCII for  newline
    	lb $t2, 0($s2) #load next char
   	beq $t2, $t6, skip_1 #check if new line then skip 1
    	li $t6, 13 #ASCII for carriage return
    	beq $t2, $t6, skip_2 #check if carriage return then skip 2

    	li $t1, 0 #reset integer part
    	ldc1 $f4, double #load decimal part
    	jal int_converter #get integer part
    	move $t3, $t1 #save it in $t3
    	li $t1, 0 #reset for decimal part
    	jal int_converter #get decimal part as int
    	jal double_converter #convert decimal part to double

	#Get final value
    	mtc1 $t3, $f6
    	cvt.d.w $f8, $f6 #convert integer part to the double
    	add.d $f10, $f4, $f8 #add integer and decimal part to get final vaue

    	sdc1 $f10, 0($s5) #store it in the heap
    
    	addi $t0, $t0, 1 #Increment element counter
    	addi $s5, $s5, 8 #move to the next position in heap

    	j loop_through_buffer #do loop
    	
#After saving all in heap we do search_part
# $s6 has base address of heap
# $s3 has rows
# $s4 has cols
next_part:
	li $v0, 4 #print newline
	la $a0, newline
	syscall

	li $v0, 4 #promp the user
	la $a0, user_prompt
	syscall
	
	li $v0, 7 #get user input as double
    	syscall
    	mov.d $f12, $f0
    	
    	j search #proceed with searching
    	
# $s6 has base address of heap
# $s3 has rows
# $s4 has cols   
search: 
	#$t0 has number of elements
	li $t1, 0 #counter of all elements
	
search_loop:
	bge $t1, $t0, not_found #if we checked all elements, then it was not found
	ldc1 $f4, 0($s6) #load current element
	c.eq.d $f4, $f12 #check if equal to input
	bc1t found #if equal then it was found
	
	addi $t1, $t1, 1 #increment searched elements
	addi $s6, $s6, 8 #go to the next element in the heap
	j search_loop #do loop
not_found:
	li $v0, 4 #if not found print not_found text
	la $a0, not_found_prompt
	syscall
	j exit
found:
	div $t1, $s4 #getting i and j
	mflo $t2 #i coordinate
	mfhi $t3 #j coordinate
	
	li $v0, 4 #print first part
	la $a0, found_prompt
	syscall
	
	li $v0, 1 #print i
	move $a0, $t2
	syscall
	
	li $v0, 4 #print ]
	la $a0, close_bracket
	syscall
	
	li $v0, 4 #print [
	la $a0, open_bracket
	syscall
	
	li $v0, 1 #print j
	move $a0, $t3
	syscall
	
	li $v0, 4 #print ]
	la $a0, close_bracket
	syscall
	
	li $v0, 4 #print .
	la $a0, dot
	syscall
	
	j exit #exit the code

#here i convert string to int
int_converter:
    	li $t7, 10 #load 10      
int_converter_loop:
    	lb $t2, 0($s2) #load character 
    	addi $s2, $s2, 1 #go to the next character

    	li $t6, 46 #ASCII for dot
    	beq $t2, $t6, int_converter_loop_end #if . then end
    	li $t6, 32 #ASCII for " "
    	beq $t2, $t6, int_converter_loop_end #if " " then end

    	subi $t2, $t2, 48 #convert to integer
    	mul $t1, $t1, $t7 #*10
    	add $t1, $t1, $t2 #add integer
    	j int_converter_loop #do loop
int_converter_loop_end:     
    	jr $ra #return
    
#here I convert integer to the double
double_converter: 
	ldc1 $f8, double_1.0 #get 1.0 for comparing
	mtc1 $t1, $f6
	cvt.d.w $f4, $f6 #convert integer to the double
    	ldc1 $f16, double_10 #get 10.0 to divide
double_converter_loop:
	c.lt.d $f4, $f8 #if result is less then 1.0 then we completed
	bc1t double_converter_loop_end #if true end loop
	div.d $f4, $f4, $f16 #divide result by 10
    	j double_converter_loop #do loop

double_converter_loop_end:
    	jr $ra #return
	
skip_1:
    	addi $s2, $s2, 1 #skip 1 character
    	j loop_through_buffer #return back

skip_2:
    	addi $s2, $s2, 1 #skip 2 characters
    	j loop_through_buffer #return back
exit: 
    	li $v0, 16 #close the file
    	move $a0, $s0 #pass descriptor
    	syscall
    
    	li $v0, 10 #close the programm
    	syscall

file_open_error: 
    	li $v0, 4 #print cant open file error
    	la $a0, fail
    	syscall
    	li $v0, 10 #close the programm
    	syscall  
