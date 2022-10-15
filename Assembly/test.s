.text
hello:	.asciz "Hello world!\n"

.global main

main:
	movq	%rsp, %rbp
	movq	$0, %rax
	movq	$hello, %rdi
	call	printf

end:
	movq	$0, %rdi
	call	end
