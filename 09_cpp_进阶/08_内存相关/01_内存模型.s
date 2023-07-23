	.file	"01_\345\206\205\345\255\230\346\250\241\345\236\213.cpp"
	.text
	.section	.text._ZN6PersonC2Ei,"axG",@progbits,_ZN6PersonC5Ei,comdat
	.align 2
	.weak	_ZN6PersonC2Ei
	.type	_ZN6PersonC2Ei, @function
_ZN6PersonC2Ei:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN6PersonC2Ei, .-_ZN6PersonC2Ei
	.weak	_ZN6PersonC1Ei
	.set	_ZN6PersonC1Ei,_ZN6PersonC2Ei
	.globl	a1
	.data
	.align 4
	.type	a1, @object
	.size	a1, 4
a1:
	.long	1
	.globl	a2
	.bss
	.align 4
	.type	a2, @object
	.size	a2, 4
a2:
	.zero	4
	.globl	a3
	.align 4
	.type	a3, @object
	.size	a3, 4
a3:
	.zero	4
	.section	.rodata
	.align 4
	.type	_ZL2a5, @object
	.size	_ZL2a5, 4
_ZL2a5:
	.long	2
	.globl	a6
.LC0:
	.string	"123456789"
	.section	.data.rel.local,"aw"
	.align 8
	.type	a6, @object
	.size	a6, 8
a6:
	.quad	.LC0
	.globl	a7
	.section	.rodata
.LC1:
	.string	"abcdefh"
	.section	.data.rel.local
	.align 8
	.type	a7, @object
	.size	a7, 8
a7:
	.quad	.LC1
	.globl	a8
	.data
	.align 16
	.type	a8, @object
	.size	a8, 16
a8:
	.long	1
	.long	2
	.long	3
	.long	4
	.globl	pp
	.bss
	.align 8
	.type	pp, @object
	.size	pp, 8
pp:
	.zero	8
	.section	.rodata
.LC2:
	.string	"a1=%d, a2=%d, a3=%d\n"
.LC3:
	.string	"*pp=%d\n"
.LC4:
	.string	"person age=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB18:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	pp(%rip), %rax
	movl	$7, (%rax)
	movl	$1, -44(%rbp)
	movl	$6513249, -28(%rbp)
	movl	$4, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movl	$18, %esi
	movq	%rbx, %rdi
	call	_ZN6PersonC1Ei
	movq	%rbx, -40(%rbp)
	movl	a3(%rip), %ecx
	movl	a2(%rip), %edx
	movl	a1(%rip), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	pp(%rip), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB19:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L7
	cmpl	$65535, -8(%rbp)
	jne	.L7
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, pp(%rip)
.L7:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_a1, @function
_GLOBAL__sub_I_a1:
.LFB20:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	_GLOBAL__sub_I_a1, .-_GLOBAL__sub_I_a1
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_a1
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
