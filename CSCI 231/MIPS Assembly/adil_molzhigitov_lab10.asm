.data
	array100: .space 800 #array for storing 200 doubles
	array300: .space 2400 #array for storing 300 doubles
	
	array100Indexes: .space 1000 #Array for stroing indexes of pairs for size 100
	array300Indexes: .space 4000 #Array for stroing indexes of pairs for size 300
	
	ArraySizePrompt: .asciiz "Array size: " #all the prompts
	ResultPrompt: .asciiz "Result: "
	DashPromptSpaces: .asciiz " - "
	DashPromptNoSpaces: .asciiz "-"
	OpenRoundBracketPrompt: .asciiz "("
	ClosedRoundBracketPrompt: .asciiz ")"
	OpenSquareBracketPrompt: .asciiz "["
	ClosedSquareBracketPrompt: .asciiz "]"
	CommaPrompt: .asciiz "," #yeah even comma 
	NextLinePrompt: .asciiz "\n"
	NotFoundPrompt: .asciiz "There are no ’x’ and ’2x’ elements in the array.\n"
	
	seed: .word 42 #seed for generating random doubles
	scale: .double 200.0 #scaling factor
	divisor: .double 2.0 #we use it to divide
.text
main: 
	la $a0, array100 #Fill first array
	li $a1, 100
	jal RandomFiller

	la $a0, array100 #Print First Array
	li $a1, 100
	jal ArrayPrinter
	
	la $a0, array100 #Search Pairs First Array
	la $a1, array100Indexes
	li $a2, 100
	jal PairSearcher
	move $s0, $v0
	
	la $a0, array100 #Print Pairs first Array
	la $a1, array100Indexes
	move $a2, $s0
	jal PairPrinter
	
	li $v0, 4 #Next line
	la $a0, NextLinePrompt
	syscall
	
	li $v0, 4 #Next line
	la $a0, NextLinePrompt
	syscall

	#The same but for the size 300
	la $a0, array300 #Fill seccond Array
	li $a1, 300
	jal RandomFiller
		
	la $a0, array300 #Print Second Array
	li $a1, 300
	jal ArrayPrinter

	la $a0, array300 #Search pairs Second Array
	la $a1, array300Indexes
	li $a2, 300
	jal PairSearcher
	move $s1, $v0

	la $a0, array300 #Print Second Array
	la $a1, array300Indexes
	move $a2, $s1
	jal PairPrinter
		
	j exit #Just in Case
	
exit:
	li $v0, 10 #Exit
	syscall

PairPrinter: #Accepts array of pair indexes, array of doubles, number of pairs will print all staff left
	beqz $a2, NotFound
	addi $sp, $sp, -8   # Make space for 2 registers (each is 4 bytes)
	sw $s2, 0($sp)      # Save $s2 at the top of the stack
	sw $s3, 4($sp)      # Save $s3 just below $s2
	#I pretty much run out of temporary registers :-(
	move $t0, $a0 #save original array of doubles
	move $t7, $a0 #Also saved in $t7 because we will overwrite $a0 and $t0
	move $t1, $a1 #array of pairs
	move $t2, $a2 #number of pairs
	#Printing Result
	li $v0, 4
	la $a0, ResultPrompt #Print Result
	syscall
	
	li $v0, 1
	move $a0, $a2 #Print number of pairs
	syscall
	
	li $v0, 4 #next Line
	la $a0, NextLinePrompt
	syscall
	
	li $t3, 5 #max elements in one line
	li $s2, 0 #counter of pairs
PairPrinter_loop:
	move $t0, $t7 #update original address array of doubles
	
	lw $t4, 0($t1) #loading first index
	subi $t4, $t4, 1 #TO DELETE
	addi $t1, $t1, 4 #move to the next index
	
	li $t5, 8 #getting address of double
	mul $t6, $t4, $t5
	add $t0, $t0, $t6
	
	ldc1 $f4, 0($t0) #getting that $t4 indexed double
	move $t0, $t7 #update original address array of doubles
	li $v0, 4
	la $a0, OpenRoundBracketPrompt
	syscall
	
	li $v0, 3 #Print double
	mov.d $f12, $f4
	syscall
	
	li $v0, 4 #I will not comment some code below, it is clearly seen from the string names
	la $a0, OpenSquareBracketPrompt
	syscall
	
	li $v0, 1
	move $a0, $t4 #print index
	syscall
	
	lw $t4, 0($t1) #loading second index
	addi $t1, $t1, 4
	
	li $t5, 8 #getting address of double
	mul $t6, $t4, $t5
	add $t0, $t0, $t6
	
	ldc1 $f4, 0($t0) #getting that $t4 indexed double
	
	li $v0, 4
	la $a0, ClosedSquareBracketPrompt
	syscall
	
	li $v0, 4
	la $a0, CommaPrompt
	syscall
	
	li $v0, 3 #print another double
	mov.d $f12, $f4
	syscall
	
	li $v0, 4
	la $a0, OpenSquareBracketPrompt
	syscall
	
	li $v0, 1 #print second index
	move $a0, $t4
	syscall
	
	li $v0, 4
	la $a0, ClosedSquareBracketPrompt
	syscall
	
	li $v0, 4
	la $a0, ClosedRoundBracketPrompt
	syscall
	
	addi $s2, $s2, 1 #counter for pairs++
	div $s2, $t3 #check if end of the line
	mfhi $s3
	bge $s2, $t2, PairPrinter_end #check if it is last pair
	beqz $s3, PrintNextLine

	#
	
	#
	li $v0, 4 #print that dash
	la $a0, DashPromptNoSpaces
	syscall
continue2:
	j PairPrinter_loop
PairPrinter_end:
	lw $s2, 0($sp)      # Restore $s2 from the stack
	lw $s3, 4($sp)      # Restore $s3 from the stack
	addi $sp, $sp, 8    # Reclaim stack space (move stack pointer back)
	jr $ra
PrintNextLine:
	li $v0, 4
	la $a0, NextLinePrompt #next line
	syscall
	j continue2
NotFound:
	li $v0, 4
	la $a0, NotFoundPrompt #I almost forgot about this, I am 99 percent sure it will not be used
	syscall
	
#gets address of the array, its size, address of array of indexes. Fill out indexes of the pair and returns total number of pairs into $v0	
PairSearcher: #Wow that works :-)
	move $t0, $a0 #save address of the array
	move $t1, $a1 #save address of the array of indexes
	move $t2, $a2 #save total amount of elements
	li $t3, 0 #element counter
	li $t6, 0 #pair counter
PairSearcher_loop_outer: #I pretty much forgot what this loop about :-)
	beq $t3, $t2, PairSearcher_end
	ldc1 $f4, 0($t0) #works like nested loop, linear search for each double n^2
	ldc1 $f6, divisor
	#mov.d $f8, $f4 #to delete used for debugging
	div.d $f4, $f4, $f6
	addi $t0, $t0, 8
	addi $t3, $t3, 1
	li $t4, 0 #inner loop element counter
	move $t5, $a0 #for inner loop
PairSearcher_loop_outer_inner:
	beq $t4, $t2, PairSearcher_loop_outer
	ldc1 $f6, 0($t5) 
	c.eq.d $f6, $f4
	bc1t index_saver
continue:
	addi $t5, $t5, 8
	addi $t4, $t4, 1
	j PairSearcher_loop_outer_inner
PairSearcher_end:
	move $v0, $t6
	jr $ra	
index_saver:
	#li $v0, 3 #This was used for debugging
	#mov.d $f12, $f8 
	#syscall
	
	#li $v0, 3
	#mov.d $f12, $f4 
	#syscall
	
	sw $t3, 0($t1) #save indexes and go
	addi $t1, $t1, 4
	sw $t4, 0($t1)
	addi $t1, $t1, 4
	addi $t6, $t6, 1
	j continue
	
ArrayPrinter: #Gets base address of array to print and its size #return void #prints array
	move $t0, $a0 #save base address
	li $t1, 0 #counter
	li $t2, 1 #index for lines 
	
	li $v0, 4
	la $a0, ArraySizePrompt
	syscall
	
	li $v0, 1
	move $a0, $a1
	syscall
	
	li $v0, 4
	la $a0, NextLinePrompt
	syscall
ArrayPrinter_loop_outer:
	beq $t1, $a1, ArrayPrinter_end
	li $v0, 1 #print index
	move $a0, $t2
	syscall
	
	li $v0, 4 #print " - "
	la $a0, DashPromptSpaces
	syscall
	
	addi $t2, $t2, 1 #update index
	addi $t1, $t1, 10 #update element counter
	
	li $t3, 0 #element counter for line
	li $t4, 10 #number of element in line	
ArrayPrinter_loop_inner:
	li $v0, 3
	ldc1 $f12, 0($t0)
	syscall
	addi $t3, $t3, 1
	addi $t0, $t0, 8
	beq $t3, $t4, ArrayPrinter_loop_outer_J
	li $v0, 4
	la $a0, DashPromptNoSpaces
	syscall
	j ArrayPrinter_loop_inner	
ArrayPrinter_loop_outer_J:
	li $v0, 4
	la $a0, NextLinePrompt
	syscall
	j ArrayPrinter_loop_outer		
ArrayPrinter_end:
	jr $ra #return
	
RandomFiller: #Gets address of array of doubles and its size #returns it filled with random doubles
	move $t0, $a0 #save base address
	li $t1, 0 #element counter

RandomFiller_loop:
	beq $t1, $a1, RandomFiller_Exit #If counter equal size, then we finished
	
	lw $a0, seed #load seed
	li $v0, 44 #syscall for random
	syscall #our random number is in $f0
	
	ldc1 $f4, scale #load scaling factor
	mul.d $f0, $f4, $f0 #random*scale and save in $f0
	round.w.d $f0, $f0 #round to the integer
	cvt.d.w $f0, $f0 #save back as double
	
	sdc1 $f0, 0($t0) #save double
	addi $t0, $t0, 8 #move to the next address
	addi $t1, $t1, 1 #update counter
	#Was used in the debugging
	#li $v0, 3
	#mov.d $f12, $f0 
	#syscall
	
	#li $v0, 4
	#la $a0, NextLinePrompt
	#syscall
	j RandomFiller_loop #loop
RandomFiller_Exit:
	jr $ra	#return
	
#Thanks for your work. Labs were really interesting, although some were difficult
