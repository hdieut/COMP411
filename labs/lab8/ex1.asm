.data
  AA:     .space 400  		# int AA[100]
  BB:     .space 400  		# int BB[100]
  CC:     .space 400  		# int CC[100]
  m:      .space 4   		# m is an int whose value is at most 10
                     		# actual size of the above matrices is mxm

      # You may add more variables here if you need to



.text

main:


#------- INSERT YOUR CODE HERE for main -------
#
#  Best is to convert the C program line by line
#    into its assembly equivalent.  Carefully review
#    the coding templates near the end of Lecture 8.
#
#
#  1.  First, read m (the matrices will then be size mxm).
	addi $v0, $0, 5		# syscall 5 for reading in int
	syscall
	# sw $v0, m($0)		# store value into m
	add $t0, $0, $v0	# copy m into t0
	mult $t0, $t0		# mxm
	mflo $t1		# move product to t1
	add $t2, $0, $0		# i = 0 in t2
	add $s1, $0, $0		# j = 0
	add $s2, $0, $0		# k = 0
	add $4, $0, $0		# l = 0
	add $5, $0, $0		# n = 0
	la $a1, AA		# loading base address into register
	la $a2, BB		# loading base address into register 
	la $a3, CC		# loading base address into a register
	
	
#  2.  Next, read matrix A followed by matrix B.
loopA:
	addi $v0, $0, 5		# reading in int
	syscall
	add $t3, $0, $v0	# store into t3
	sll $t2, $t2, 2		# t4  = t2 or i*4
	# lw $t3, AA($t3)
	add $t4, $t2, $a1	# adding offset to a[i] 
	sw $t3, AA($t4)		# t3 = AA[i]
	addi $t2, $t2, 1	# i++ 
	sltu $t5, $t2, $t1	# t5 = t2<t1 aka t5 = i<mxm
	bne $t5, $0, loopA	# checking if true, then loop
	bne $t5, $1, initialize	# if loop is done, reset i = 0

loopB:
	addi $v0, $0, 5		# reading in int
	syscall
	add $t6, $0, $v0	# store into t6
	sll $t2, $t2, 2		# t4 = i*4
	# lw $t6, BB($t6)		# t6 = BB[i]
	add $t4, $t2, $a2	# adding offset to b[i]
	sw $t6, BB($t4)
	addi $t2, $t2, 1	# i++
	sltu $t7, $t2, $t1	# t7 = t2<t1 aka t5 = i<mxm
	bne $t7, $0, loopB	# checking if true, then loop
	bne $t7, $1, initialize	# if loop is done, reset i = 0
	
#  3.  Compute matrix product.  You will need triple-nested loops for this.
multLoop1:
	sll $t2, $t2, 2		# t8 = i*4
	addi $t2, $t2, 1	# i++
	sltu $1, $t2, $t0	# 1 = i < m
	bne $1, $0, multLoop2	# if true, go to next loop
	# bne $1, $1, print1	# if not true, go print
	
multLoop2:
	sll $s1, $s1, 2		# t9 = j*4
	addi $s1, $s1, 1	# j++
	sltu $2, $s1, $t0	# 2 = j < m
	bne $2, $0, multLoop3	# if true, go to next loop
	bne $2, $1, multLoop1	# if not true, go back to first loop

multLoop3:
	mult $t2, $t0		# i*M
	mflo $s3		# move to k0
	add $s4, $s3, $s1	# s4 = i*m+j
	add $s5, $s3, $s2	# s5 = i*m+k
	mult $s2, $t0		# k*m
	mflo $s6		# s6 = k*m
	add $s7, $s6, $s1	# s7 = k*m+j
	sll $t8, $s2, 2		# t8 = k*4
	lw $s5, AA($s5)		# get A[i*m+k]
	lw $s7, BB($s7)		# get B[k*m+j]
	mult $s5, $s7		# A*B
	mflo $gp		# move product to gp
	add $sp, $gp, $sp	# sum sp = gp + sp
	sw $sp, CC($s4)		# store sum into C
	sll $s2, $s2, 2		# n*4
	addi $s2, $s2, 1	# k++
	sltu $3, $s2, $t0	# 3 = k < m
	bne $3, $0, multLoop3	# if true, keep looping
	bne $3, $1, multLoop2	# if not true, go back to 2nd loop
	
#  4.  Print the result, one row per line, with one (or more) space(s) between
#      values within a row.	
print1:
	addi $4, $4, 1		# l++
	sltu $6, $4, $t0	# 6 = l < m
	bne $6, $0, print1	# if true, loop
	bne $6, $1, print2	# if not true, go to next loop
	
print2:
	addi $v0, $0, 1		# syscall for printing integer
	add $a0, $0, $s4	
	syscall
	addi $5, $5, 1		# n++
	sltu $7, $5, $t0	# 7 = n < m
	bne $7, $0, print2	# if true keep looping
	bne $7, $0, exit	# if not true, exit 
	
	
initialize: 
	add $t2, $0, $0		# i = 0	
	
#  5.  Exit.
#
#------------ END CODE ---------------


exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



#------- If you decide to make other functions, place their code here -------
#
#  You do not have to use helper methods, but you may if you would like to.
#  If you do use them, be sure to do all the proper stack management.
#  For this exercise though, it is easy enough to write all your code
#  within main.
#
#------------ END CODE ---------------