	.file	"proc2.c"
	.text
	.globl	sum_of_squares
	.type	sum_of_squares, @function
sum_of_squares:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	imull  -4(%rbp), %eax
	movl  -8(%rbp), %edx
	imull  -8(%rbp), %edx
	addl  %edx,%eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sum_of_squares, .-sum_of_squares
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
