.data 
	x: .word 0
	record: .word 50
	
.text 

 main:
 	 addi $v0, $0, 5		# read in int for total # of inputs
 	 syscall 
 	 add $t0, $0, $v0		# store here 
 	 
 	 la $a0 record			# load location of start of record array
 	 lw $t1, x		# read x 
 	 
 	 j inputs
 	 
 	 
 	 	
 	 
 inputs:
 	addi $v0, $0, 5			# read in inputs
 	syscall
 	sw $v0, record			# store inputs in record array
 	slt $t2, $t1, $t0			# x < inputs 
 	j inputs
 	
 compare:
 	
 
 swap:
 
 loop:
 	subi $t3, $t0, 1		# inputs -1
 	slt $t2, $t1, $t3	# x < inputs-1 stored...????
 	j loop2
 	
 loop2:
 	addi $t3, $0, 1		# inputs +1
 	slt $t2, $t1, $t3	# x < inputs +1 stored...???
 	
 	j compare
 	
 	
 	
 	 