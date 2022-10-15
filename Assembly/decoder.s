.text
format: .asciz "\033[%dm\033[48;5;%dm\033[38;5;%dm%c"	# background color; character color; effect; character; escape

.include "final.s"

.global main

# ************************************************************
# Subroutine: decode                                         *
# Description: decodes message as defined in Assignment 4    *
#   - 1 byte background color                                *
#   - 1 byte character color                                 *
#   - 4 byte index                                           *
#   - 1 byte amount                                          *
#   - 1 byte character                                       *
# Parameters:                                                *
#   first: the address of the message to read                *
#   return: no return value                                  *
#*************************************************************

reset:
	movq	$0, %r14
	jmp	output
stop:
	movq	$25, %r14
	jmp	output
bold:
	movq	$1, %r14
	jmp	output
faint:
	movq	$2, %r14
	jmp	output
conceal:
	movq	$8, %r14
	jmp	output
reveal:
	movq	$28, %r14
	jmp	output
blink:
	movq	$5, %r14
	jmp	output
same:
	cmpq	$0, %r11
	je	reset
	cmpq	$37, %r11
	je	stop
	cmpq	$42, %r11
	je	bold
	cmpq	$66, %r11
	je	faint
	cmpq	$105, %r11
	je	conceal
	cmpq	$153, %r11
	je	reveal
	cmpq	$182, %r11
	je	blink

decode:
	# prologue
	pushq	%rbp 				# push the base pointer (and align the stack)
	movq	%rsp, %rbp			# copy stack pointer value to base pointer


	# first block of the message
	movq	(%rdi), %rbx			# bl: character, bh: amount

	# initialize r12, r13, r14
	movq	$0, %r12			# r12: prev char color
	movq	$0, %r13			# r13: prev bg color
	movq	$0, %r14			# r14: effect

print:
	# getting background and character color
	movq	%rbx, %r10
	shr	$48, %r10			# r10b: character color
	movq	%rbx, %r11
	shr	$56, %r11			# r11: background color

	# check if bg and char color is the same
	cmpb	%r10b, %r11b
	je	same				# assign effects

	# save color values
	movb	%r10b, %r12b			# r12: previous character color
	movq	%r11, %r13			# r13: previous background color

output:
	# print the character
	movq	$0, %rax
	movq	$format, %rdi
	movq	%r14, %rsi
	movq	%r13, %rdx
	movq	%r12, %rcx
	movb	%bl, %r8b
	call	printf

check:
	# check printing amount
	cmp	$1, %bh
	jle	next				# amount <= 1 go to next

	dec	%bh				# decrement 1 from amount
	jmp	print				# print the character again


# move to next block to get the values, and jump to print
next:
	shr	$16, %rbx			# ebx: index

	cmpl	$0, %ebx			# if the index is 0,
	je	end				# finish subroutine

	movl	%ebx, %r8d			# assign index to r8
	movq	$0, %r9				# r9 = 0
	movq	MESSAGE(%r9, %r8, 8), %rbx	# rbx = MESSAGE[r8]
	jmp	print				# jump to print

end:
	# epilogue
	movq	%rbp, %rsp			# clear local variables from stack
	popq	%rbp				# restore base pointer location 
	ret

main:
	pushq	%rbp 				# push the base pointer (and align the stack)
	movq	%rsp, %rbp			# copy stack pointer value to base pointer

	movq	$MESSAGE, %rdi			# first parameter: address of the message
	call	decode				# call decode

	popq	%rbp				# restore base pointer location 
	movq	$0, %rdi			# load program exit code
	call	exit				# exit the program

