.include "Macros.asm" #I used Macros.asm that was given in lab

.data
	P_3: .asciiz "P_3:" #P_3 
	Space: .asciiz " " #Space
	NewLine: .asciiz "\n" #\n character

.text
.globl PrintPowersOfThree #declare PrintPowersOfThree as global
.globl isPowerOfThree #declare isPowerOfThree as global

main:
	jal convert  #go to the convert
	jal PrintPowersOfThree #go to the PrintPowersOfThree
	li $v0, 10 #exit from programm
	syscall

# Function to print numbers that are powers of 3
PrintPowersOfThree:
	preFunc #callimg preFunc to save $s registers
	move $t0, $a0 #save size in $t0
	move $t1, $a1 #save array in $t1

	li $v0, 4 #print "P_3:"
	la $a0, P_3
	syscall
	
PrintPowersOfThree_loop: 
	blez  $t0, PrintPowersOfThree_end #if size is zero, go to PrintPowersOfThree_end

	lw $t2, 0($t1) #load current number from array
	move $a0, $t2 #pass number to isPowerOfThree

	addi $sp, $sp, -4 #saving return address
	sw $ra, 0($sp) 

	jal isPowerOfThree #call isPowerOfThree

	lw $ra, 0($sp) #Restore return address
	addi $sp, $sp, 4

	addi $t0, $t0, -1 #decrement size
	addi $t1, $t1, 4 #move to the next integer in the array

	bnez $v0, PrintPowersOfThree_print #if result is not zero (means 1) print the number


	j PrintPowersOfThree_loop #loop

PrintPowersOfThree_print:
	li $v0, 4 #print space
	la $a0, Space
	syscall

	li $v0, 1 #print power of three
	move $a0, $t2                  
	syscall

	j PrintPowersOfThree_loop #back to the loop

PrintPowersOfThree_end:
	postFunc #calling postFunc, restore $s registers
	jr $ra #return from function

# recursive function to check if a number is a power of 3
isPowerOfThree:
	addi $sp, $sp, -8 #save $ra and $a0
	sw $ra, 0($sp)            
	sw $a0, 4($sp)             

	bltz $a0, notPowerOfThree #if num < 1, return 0 false
	beqz $a0, notPowerOfThree #if num == 0, return 0 false

	li $t7, 1
	beq $a0, $t7, powerOfThree #if num == 1, return 1 true

	li $t6, 3 #load 3
	rem $t4, $a0, $t6 # num % 3
	bnez $t4, notPowerOfThree #if not divisible by 3, return 0 false

	div $a0, $a0, $t6 #num = num/3
	jal isPowerOfThree #recursive call

	#restore registers after recursive call
	lw $a0, 4($sp) #restore $ra and $a0        
	lw $ra, 0($sp)             
	addi $sp, $sp, 8           

	jr $ra #return from function

notPowerOfThree:
	li $v0, 0 #return 0 false
	lw $a0, 4($sp) #restore $ra and $a0    
	lw $ra, 0($sp)            
	addi $sp, $sp, 8          
	jr $ra

powerOfThree:
	li $v0, 1 #return 1 tru
	lw $a0, 4($sp) #restore $ra and $a0    
	lw $ra, 0($sp)             
	addi $sp, $sp, 8           
	jr $ra

