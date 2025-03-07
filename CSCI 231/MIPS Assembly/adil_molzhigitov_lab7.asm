.data
    	DISPLAY: .space 262144 #Space 256*256*4
    	DISPLAYWIDTH: .word 256 #Width of display

    	red: .word 0xFF0000 # all RGBs
    	green: .word 0x00FF00
    	violet: .word 0xFF00FF
    	yellow: .word 0xFFFF00
	white: .word 0xFFFFFF
    
    	circle_x: .word 128 # x0 of the circle
    	circle_y: .word 125 # y0 of the circle
    	circle_R: .word 43 # Radius of the circle
    	
    	#I found out that we must use floats after completing lab7
    	#In previous version I used integers that I precalculated
    	#In this version i will just use float version of those numbers to show that 
    	#I can use it, and then I will
    	#convert it to the integer to pass it to set_pixel_color
    	line_60: .float 60.0 #here I loaded all values that i will need as floats
    	line_196: .float 196.0
    	line_168: .float 168.0
    	float_1: .float 1.0
    	line_128: .float 128.0
    	line_30: .float 30.0
    	float_minus2: .float -2.0
    	float_286: .float 286.0
    	float_2: .float 2.0
    	float_minus226: .float -226.0
.text

main:
	lwc1 $f4, line_60 #load 60
	lwc1 $f5, line_196 #load 196
	lwc1 $f6, line_168 #load 168
	lwc1 $f10, float_1 #load 1
	lw $a2, green #load green
	
draw_line1: 
	cvt.w.s $f7, $f4 #get integer value to $f7
	mfc1 $a0, $f7 #get its value to $a0
	cvt.w.s $f8, $f5 #get integer value to $f8
	mfc1 $a3, $f8 #get its value to $a3
	cvt.w.s $f9, $f6 #get integer value to $f9
	mfc1 $a1, $f9 #get its value to $a1
	jal set_pixel_color #draw a pixel
	add.s $f4, $f4, $f10 #move to the next x, x+1
	c.le.s $f4, $f5 #while $f4 is less then $f5 continue loop
	bc1t draw_line1 #branh if true

	
	
	lwc1 $f4, line_128 #load 128
	lwc1 $f5, line_30 #load 30
	lwc1 $f6, line_168 #load 168
	lwc1 $f10, float_1 #load 1
	#Further i leaved some old code, thats logic I used again in for the floats
	#li $a0, 128 #Again loading coordinates
	#li $a1, 30
	#li $a3, 168
	lw $a2, violet
draw_line2:
	cvt.w.s $f7, $f4 #get integer value to $f7
	mfc1 $a0, $f7 #get its value to $a0
	cvt.w.s $f8, $f5 #get integer value to $f8
	mfc1 $a1, $f8 #get its value to $a1
	cvt.w.s $f9, $f6 #get integer value to $f9
	mfc1 $a3, $f9 #get its value to $a3
	jal set_pixel_color #draw a pixel
	add.s $f5, $f5, $f10 #move to the next point
	c.le.s $f5, $f6 #while $f4 is less then $f5 continue loop
	bc1t draw_line2  #branh if true
	#addi $a1, $a1, 1#go to the next y
	#ble $a1, $a3, draw_line2 #check if we reached desired y
	
	
	lwc1 $f4, line_128 #load 128
	lwc1 $f5, line_30 #load 30
	lwc1 $f6, line_60 #load 60
	lwc1 $f10, float_1 #load 1
	#li $a0, 128 #Again loading coordinates
	#li $a1, 30
	lw $a2, yellow #load yellow color
	#li $a3, 60
	
draw_line3:
	cvt.w.s $f7, $f4 #get integer value to $f7
	mfc1 $a0, $f7 #get its value to $a0
	cvt.w.s $f8, $f5 #get integer value to $f8
	mfc1 $a1, $f8 #get its value to $a1
	cvt.w.s $f9, $f6 #get integer value to $f9
	mfc1 $a3, $f9 #get its value to $a3
	jal set_pixel_color #draw a pixel
	sub.s $f4, $f4, $f10 #move to the next x
	#addi $a0, $a0, -1 #go to the next x
	mov.s $f16, $f4 #move it to $f16
	#move $t0, $a0 #move it to $t0
	lwc1 $f18, float_minus2 #load k
	mul.s $f16, $f16, $f18 #multiply to k
	#mul $t0, $t0, -2 #multiply to k
	lwc1 $f17, float_286 #load b
	add.s $f16, $f16, $f17 #add b
	#addi $t0, $t0, 286 #add b
	mov.s $f5, $f16 #get our new y
	#move $a1, $t0 #get our new y

	c.lt.s   $f6, $f4 #while $f6, $f4 continue loop
	bc1t, draw_line3 #if true branch to draw_line3
	#bge $a0, $a3, draw_line3 #check if we reached desired x
	
	
	
	lwc1 $f4, line_128 #load 128
	lwc1 $f5, line_30 #load 30
	lwc1 $f6, line_196 #load 196
	lwc1 $f10, float_1 #load 1
	#li $a0, 128 #Again loading coordinates
	#li $a1, 30
	lw $a2, red #load red color
	#li $a3, 196
draw_line4:
	cvt.w.s $f7, $f4 #get integer value to $f7
	mfc1 $a0, $f7 #get its value to $a0
	cvt.w.s $f8, $f5 #get integer value to $f8
	mfc1 $a1, $f8 #get its value to $a1
	cvt.w.s $f9, $f6 #get integer value to $f9
	mfc1 $a3, $f9 #get its value to $a3
	jal set_pixel_color #draw a pixel
	add.s $f4, $f4, $f10 #move to the next x
	#addi $a0, $a0, 1 #go to the next x
	mov.s $f16, $f4  #move it to the $f16
	#move $t0, $a0 #move it to $t0
	lwc1 $f18, float_2 #load k
	mul.s $f16, $f16, $f18  #multiply to k
	#mul $t0, $t0, 2 #multiply to k
	lwc1 $f17, float_minus226 #load b
	add.s $f16, $f16, $f17 #add b
	#addi $t0, $t0, -226 #add b
	mov.s $f5, $f16 #get our new y
	#move $a1, $t0 #get our new y
	c.le.s $f4, $f6 #while $f4 is less then $f6 continue loop
	bc1t, draw_line4 #if true go to  the draw_line4
	#ble $a0, $a3, draw_line4 #check if we reached desired x


	# To draw circle I used Bresenham circle drawing algorithm
    	lw $t0, circle_x #Loading center coordinates
    	lw $t1, circle_y                
    
    	li $t3, 0 #Introduce decision parameter e = 0 
    	#here x and y are offsets from midpoint
    	lw $t4, circle_R # x is initially equal to radius
    	li $t5, 0 # y is 0
    
circle_loop:
    	ble $t4, $t5, exit # Exit if x < y
    
    	#Drawing the 8 symmetrical points of the circle
    	add $t6, $t0, $t4 # x0 + x
   	add $t7, $t1, $t5 # y0 + y
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	lw $a2, white #Load color (white)
    	jal set_pixel_color #Put pixel

    	add $t6, $t0, $t5 # x0 + y
    	add $t7, $t1, $t4 # y0 + x
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	sub $t6, $t0, $t5 # x0 - y
    	add $t7, $t1, $t4 # y0 + x
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	sub $t6, $t0, $t4 # x0 - x
    	add $t7, $t1, $t5 # y0 + y
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	sub $t6, $t0, $t4 # x0 - x
    	sub $t7, $t1, $t5 # y0 - y
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	sub $t6, $t0, $t5 # x0 - y
    	sub $t7, $t1, $t4 # y0 - x
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	add $t6, $t0, $t5 # x0 + y
    	sub $t7, $t1, $t4 # y0 - x
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	add $t6, $t0, $t4 # x0 + x
    	sub $t7, $t1, $t5 # y0 - y
    	move $a0, $t6 #pass coordinates
    	move $a1, $t7 #pass coordinates
    	jal set_pixel_color # Put pixel

    	# Update decision parameter and coordinates
    	blez $t3, case1 # If decision param <= 0, go to the case 1

    	addi $t4, $t4, -1 # Decrement x
    	move $t6, $t4 #move it to $t6
    	sll $t6, $t6, 1 #*2
    	addi $t6, $t6, -1 #-1
    	sub $t3, $t3, $t6 # Update e
    	j circle_loop #loop

case1:
    	addi $t5, $t5, 1 # Increment y
    	move $t6, $t5 # load it to $t6
    	sll $t6, $t6, 1 #$*2
    	addi $t6, $t6, 1 #+1
    	add $t3, $t3, $t6 # Update e
    	j circle_loop #loop

exit:
    	li $v0, 10 # Exit from programm
    	syscall

set_pixel_color:
    	lw $t9, DISPLAYWIDTH 
    	mul $t9, $t9, $a1 # y*DISPLAYWIDTH
    	add $t9, $t9, $a0 # +x
    	sll $t9, $t9, 2 # *4
    	la $t8, DISPLAY # get address of DISPLAY
    	add $t8, $t8, $t9 # add the calculated address of the pixel
    	sw $a2, ($t8) # write color to that pixel
    	jr $ra # return
