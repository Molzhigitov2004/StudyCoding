.data
array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.text
main:
    la $t0, array         # Load the base address of the array into $t0
    li $t1, 0             # Initialize sum to 0
    li $t2, 10            # Number of elements in the array
    li $t3, 0             # Initialize index to 0

loop:
    beq $t3, $t2, exit   # If index equals number of elements, exit loop
    lw $t4, 0($t0)       # Load current element from array
    add $t1, $t1, $t4    # Add the element to sum
    addi $t0, $t0, 4     # Move to the next element (4 bytes ahead)
    addi $t3, $t3, 1     # Increment index
    j loop               # Jump to the beginning of the loop

exit:
    li $v0, 1            # Print integer syscall
    move $a0, $t1        # Move sum to $a0 for printing
    syscall

    li $v0, 10           # Exit syscall
    syscall
