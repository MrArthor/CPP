	.file	"trial.cpp"
	.text
	.globl	__Z8sumArrayPii
	.def	__Z8sumArrayPii;	.scl	2;	.type	32;	.endef
__Z8sumArrayPii:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
L4:
	movl	-8(%ebp), %eax
	cmpl	-12(%ebp), %eax
	je	L2
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	cmpl	$5, -16(%ebp)
	jle	L3
	movl	-16(%ebp), %eax
	addl	%eax, -4(%ebp)
L3:
	addl	$4, -8(%ebp)
	jmp	L4
L2:
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
