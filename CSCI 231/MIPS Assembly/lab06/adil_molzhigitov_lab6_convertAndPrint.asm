.include "Macros.asm" #I used Macros.asm that was given in lab

.data
    	ArrPrompt: .asciiz "Arr:" #Arr:
    	Space: .asciiz " " #space character
    	NewLine: .asciiz "\n" #\n character

.text
#convert function that also call print function
.globl convert
.globl print
convert:
    	preFunc #callimg preFunc to save $s registers
    	move $t0, $a0 #save size in $t0size
    	move $t1, $a1 #save array in $t1

convert_loop:
    	beqz $t0, end_convert #if size is 0, its last string, go to end convert
    	lw $t2, 0($t1) #loading array of string 

    	li $t3, 0 #declare resulting number
    
convert_string:
    	lb $t5, 0($t2) #load current character from the string
    	beqz $t5, store_value #if string is ended, store the result
    
    	sub $t5, $t5, '0' #convert to integer
    	mul $t3, $t3, 10 #result = result * 10 
    	add $t3, $t3, $t5 #result = result + current_digit
    
    	addi $t2, $t2, 1 #move to the next character
    	j convert_string #loop to the next character

store_value:
    	sw $t3, 0($t1) # store resulting number back in array
    	addi $t1, $t1, 4 #move to the next integer
    	addi $t0, $t0, -1 #decrement size
    	j convert_loop #loop

end_convert:
    	move $v0 $a1 #storing base address of an array in $v0
    	postFunc #calling postFunc, restore $s registers
    	
     	addi $sp, $sp, -4 
     	sw $ra, 0($sp) #save return address

     	jal print #call to print function

     	lw $ra, 0($sp) #restore return address
     	addi $sp, $sp, 4 
    	
    	jr $ra #return from function 


#print procedure
print: 
    	preFunc #callimg preFunc to save $s registers
    	move $t0, $a0 #save size in $t0size
    	move $t1, $v0 #save array in $t1

    	li $v0, 4 #printing "Arr:"
    	la $a0, ArrPrompt
    	syscall

print_loop:
    	beqz $t0, end_print #if size is 0, go to end_print

    	li $v0, 4 #print space
    	la $a0, Space
    	syscall

    	li $v0, 1 #print integer from array
    	lw $a0, 0($t1)
    	syscall

    	addi $t1, $t1, 4 #move to the next integer in array
    	addi $t0, $t0, -1 #decrement size
    	j print_loop #loop 

end_print:
	move $t0 $a0 #restore $t0
    	li $v0, 4 #print \n
    	la $a0, NewLine
    	syscall
    	move $a0 $t0 #restore $a0
    	postFunc #calling postFunc, restore $s registers
    	jr $ra #return from function
              
