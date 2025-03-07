.data
	word: .asciiz "Hello"
.text
	la $t0 word
	addi $t0 $t0 3
	lb $t1, 0($t0)
	
	li $v0, 11
	move $a0, $t1
	syscall
	
	
