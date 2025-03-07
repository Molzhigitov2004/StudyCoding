.data
	v: .word -2 #declaring variables in data 
	q: .word -2
	w: .word -3
	e: .word -4
	u: .word 3
	p: .word -4
	f: .word 5
	h: .word -2
.text
	lw $s0, v #loading variables
	lw $s1, q
	lw $s2, w
	lw $s3, e
	lw $s4, u
	lw $s5, p
	lw $s6, f
	lw $s7, h
	
	add $t1, $s0, $s1 # v+q into $t1
	
	mul $s3, $s3, $s3 # getting e^2 into $s3
	mul $t2, $s2, $s3 # w*(e^2) into $t2
	
	div $t3, $s4, $s5 # u/p into $t3
	
	mul $t4, $s7, $s7 # getting h^2 into $t4
	mul $t4, $t4, $s7 # getting h^3 into $t4
	
	sub $t4, $s6, $t4 # getting f-(h^3) into $t4
	
	sub $t5, $t1, $t2 # getting (v+q)-(w*e^2) into $t5
	add $t6, $t3, $t4 # getting (u/p)+f-(h^3) into $t6
	
	sub $t7, $t5, $t6 # getting final value into $t7
	
	li $v0, 10 
	syscall
	
	
	