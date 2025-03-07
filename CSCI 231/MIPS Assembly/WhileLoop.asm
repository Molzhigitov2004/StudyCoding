.data
	message: .asciiz "While loop is done"
	space: .asciiz ", "


.text
	#main function
 	main:
 		#i - our counter
 		addi $t0, $zero, 0
 		
 	
 	#loop
 	while:
 		blez $t0, 10, exit #exit condition	
 		jal PrintNumber	
 		addi $t0, $t0, 1 #i++
 		j while #jump to while

 	#exit from loop
 	exit:
 	li $v0, 4
 	la $a0, message
 	syscall
 	
 	
 	li $v0, 10
 	syscall
 	
 	PrintNumber:
 	li $v0, 1
 	move $a0, $t0
 	syscall
 	
 	li $v0, 4
 	la $a0, space
 	syscall
 	
 	jr $ra
