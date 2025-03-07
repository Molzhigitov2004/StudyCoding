.macro preFunc
addi $sp $sp -40
sw $ra ($sp)
sw $s0 4($sp)
sw $s1 8($sp)
sw $s2 12($sp)
sw $s3 16($sp)
sw $s4 20($sp)
sw $s5 24($sp)
sw $s6 28($sp)
sw $s7 32($sp)
.end_macro 

.macro postFunc
lw $ra ($sp)
lw $s0 4($sp)
lw $s1 8($sp)
lw $s2 12($sp)
lw $s3 16($sp)
lw $s4 20($sp)
lw $s5 24($sp)
lw $s6 28($sp)
lw $s7 32($sp)
addi $sp $sp 40
.end_macro 

.macro saveAV
	addi $sp $sp -8
	sw $a0 ($sp)
	sw $v0 4($sp)
.end_macro

.macro reloadAV
	lw $a0 ($sp)
	lw $v0 4($sp)
	addi $sp $sp 8
.end_macro

.macro printInt (%i)
	saveAV
	add $a0 $zero %i
	li $v0 1
	syscall
	reloadAV
.end_macro 

.macro printChar (%c)
	saveAV
	lb $a0 %c
	li $v0 11
	syscall
	reloadAV
.end_macro
