.data
	row1: .space 64 #Here I allocated 64 bytes for first 2 rows (32 each)
	row3: .space 32 #Here I allocated 32 bytes for 3rd row to (I never used it later)
	row4: .space 64 #Here I allocated another 64 bytes for last 2 rows (32 each)

.text
	main:
		li $t0, 2 #Initial value of the series
		li $t5, 3 #Common ratio
		
		li $t3, 0 #Offset for row1
		li $t4, 0 #Offset for row4
		
		li $t6, 0 #Series counter
		li $t1, 0 #Digits counter
    		li $t2, 10 #Divisor (10)
    
    	compute_series:
    		beq $t6, 16, exit #Exit condition is when we done with first 16 element of the series
    		sw $t0, row1($t3) #Here we save element in row 1
    		addi $t3, $t3, 4  #Here we increment offset by 4 bytes for row1
    		
    		addi $t1, $zero, 0 #Resetting digit counter
    		move $t7, $t0 #Moving element to the $t7 to work with it in count_digits
    		
	count_digits:
		beq  $t7, $zero, store_digits #Store digits count in store_digits when loop is done
    		div $t7, $t2      # Divide $t7 by $t2(10)
    		mflo $t7          # Move the quotient back to $t7
		addi $t1, $t1, 1 #Digits counter++
		j count_digits	#Jump to count_digits, loop is done here
		
	store_digits:
	   sw $t1, row4($t4) #Saving digits count in row 4
	   addi $t4, $t4, 4  #Here we increment offset by 4 bytes for row1
	   
	   mul $t0, $t0, $t5 #Getting next element of the series by *=3
	   addi $t6, $t6, 1 #Incrementing series counter
	   j compute_series #jumping back to the compute series to work with next element
	   
	exit: #Exit from programm
		li $v0, 10
		syscall
    		
    		
    	
