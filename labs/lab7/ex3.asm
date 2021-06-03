#---------------------------------
# Lab 7: Pixel Conversion
#
# --------------------------------
# Below is the expected output.
# 
# Converting pixels to grayscale:
# 0
# 1
# 2
# 34
# 5
# 67
# 89
# Finished.
# -- program is finished running --
#---------------------------------

.data 0x0
  startString:  .asciiz "Converting pixels to grayscale:\n"
  finishString: .asciiz "Finished.\n"
  newline:      .asciiz "\n"
  i: 		.word 0
  pixels:       .word   0x00010000, 0x010101, 0x6,      0x3333,
                        0x030c,     0x700853, 0x294999, -1

.text 0x3000

main:
  addi $v0, $0, 4       	# system call code 4 for printing a string
  la   $a0, startString      	# put address of startString in $a0
  syscall               	# print the string

  lw $8, i 		# $8 or i = 0

#------- INSERT YOUR CODE HERE -------
#
# Read and understand the C version of the program, then convert
#   it to MIPS assembly.  The following gives you step-by-step
#   details on how to do it.
#
# First, make sure you have configured MARS under Settings as follows:
#   "Memory Configuration->Compact, Data at Address 0"
#   "Permit extended (pseudo) instructions and formats" should be checked
#
# Write a loop that reads the array pixels using "lw",
#   one word at a time, until a -1 is encountered, which
#   indicates the end of the array.

while:
  sll $9,$8,2     	# convert "i" to word offset by multiplying by 4
  lw $9, pixels($9) 	# load pixels[i]
  add $10, $0, -1 	# $10 = -1
  beq $9, $10, exit	# if pixels[i] == -1, exit 
  add $a3, $0, $9 	# rgb = pixels[i]
  andi $a2, $a3, 0xff	# blue (a2) = rgb (a3) & 0xff
  srl $11, $a3, 8	# (rgb >> 8) stored into $11
  andi $a1, $11, 0xff	# green (a1) = (rgb >> 8) & 0xff 
  srl $12, $a3, 16 	# (rgb >> 16) stored into $12
  andi $a0, $12, 0xff	# red (a0) = (rgb >> 16) & 0xff
  

  jal rgb_to_gray
 
 
  addi $v0, $0, 1	# printing an integer 
  add $a0, $0, $13	# gray stored in $13 to be printed
  syscall
  
  addi $v0, $0, 4	# printing a string
  la $a0, newline	# loading new line
  syscall
  
  addi $8, $8, 1	# incrementing i; i++
  j while		# continue looping 



exit:

  addi $v0, $0, 4         # system call code 4 for printing a string
  la   $a0, finishString  # put address of finishString in $a0
  syscall               	# print the string

  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



#----------------------------------------------------------#



#---- Procedure rgb_to_gray ----#
#
#
#-------------------------------#

rgb_to_gray:            # procedure to calculate gray = (red + green + blue) / 3
                        # red is in $a0, green is in $a1, blue is in $a2
                        # gray should be computed in $v0 (return value)
                        # there is no need to use a stack

#------- INSERT YOUR CODE HERE -------
#
# Simply add instructions here to calculate
#   gray = (red + green + blue) / 3
#
#   i.e., $v0 = ($a0 + $a1 + $a2) / 3
#
#  That's it! 
  add $14, $a0, $a1		# add red and blue and store into $a3
  add $14, $14, $a2		# add blue to sum
  div $14, $14, 3			# divide sum by 3
  mflo $13  			# move quotient into $14
  add $v0, $0, $13		# put answer into gray, $v0
#
#------------ END CODE ---------------

  jr $ra                # return to main