############################
.kdata #####################
############################
address:	.asciiz "Exception caused by instruction at address: "
code:		.asciiz "\nException code = "
repeat:		.asciiz "\nEnter the value again.\n"
saved_regs: .word 0:5	#space for saved registers

############################
.ktext 0x80000180 #########
############################
move $k0 $at #I almost did no changes to the provided exception handler #save address of instruction that causes exception
la $k1 saved_regs #load adress for saving registers
sw $k0 0($k1) #save exception causing instruction
sw $v0 4($k1) #save $v0	
sw $a0 8($k1) #save $a0
sw $t0 12($k1) #save $t0

la $a0 address #printing all messages
li $v0 4
syscall
mfc0 $a0 $14
li $v0 34
syscall

la $a0 code
li $v0 4
syscall
mfc0 $a0 $13
srl $a0 $a0 2
andi $a0 $a0 31
li $v0 1
syscall

la $a0 repeat
li $v0 4
syscall

mfc0 $t0 $14 #load address cause exception
beq $t0, 0x004001f8, Case1 #each of them check where exception occured
beq $t0, 0x00400204, Case1
beq $t0, 0x004000b8, Case0
beq $t0, 0x0040007c, CaseAplusB
exit_exception: #provided exit exception
la $k1 saved_regs #restoring staff
lw $at 0($k1)
lw $v0 4($k1)
lw $a0 8($k1)
lw $t0 12($k1)

mtc0 $zero $8		# clear $8 (vaddr)
mfc0 $k0 $14		# $k0 = $14 (epc)
addiu $k0 $k0 4		# increment $k0 by 4
mtc0 $k0 $14		# $14 (epc) = point to next instruction
eret				# exception return: PC = EPC
j done
Case1: #each case basically make special register active so i can check it and exits
	li $s6, 1
	j exit_exception
Case0: 
	li $s5, 1
	j exit_exception
CaseAplusB:
	li $s4, 1
	j exit_exception
done:
