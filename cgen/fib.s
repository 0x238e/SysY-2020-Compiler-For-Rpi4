	.text
	.syntax unified
	.eabi_attribute	67, "2.09"	@ Tag_conformance
	.eabi_attribute	6, 10	@ Tag_CPU_arch
	.eabi_attribute	7, 65	@ Tag_CPU_arch_profile
	.eabi_attribute	8, 1	@ Tag_ARM_ISA_use
	.eabi_attribute	9, 2	@ Tag_THUMB_ISA_use
	.fpu	neon
	.eabi_attribute	34, 1	@ Tag_CPU_unaligned_access
	.eabi_attribute	15, 1	@ Tag_ABI_PCS_RW_data
	.eabi_attribute	16, 1	@ Tag_ABI_PCS_RO_data
	.eabi_attribute	17, 2	@ Tag_ABI_PCS_GOT_use
	.eabi_attribute	20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute	21, 0	@ Tag_ABI_FP_exceptions
	.eabi_attribute	23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute	24, 1	@ Tag_ABI_align_needed
	.eabi_attribute	25, 1	@ Tag_ABI_align_preserved
	.eabi_attribute	38, 1	@ Tag_ABI_FP_16bit_format
	.eabi_attribute	18, 4	@ Tag_ABI_PCS_wchar_t
	.eabi_attribute	26, 2	@ Tag_ABI_enum_size
	.eabi_attribute	14, 0	@ Tag_ABI_PCS_R9_use
	.file	"fib.c"
	.globl	fib                     @ -- Begin function fib
	.p2align	2
	.type	fib,%function
	.code	32                      @ @fib
fib:
	.fnstart
@ %bb.0:
	.save	{r11, lr}
	push	{r11, lr}
	.setfp	r11, sp
	mov	r11, sp
	.pad	#16
	sub	sp, sp, #16
	str	r0, [sp, #8]
	ldr	r0, [sp, #8]
	cmp	r0, #2
	bgt	.LBB0_2
@ %bb.1:
	movw	r0, #1
	str	r0, [r11, #-4]
	b	.LBB0_3
.LBB0_2:
	ldr	r0, [sp, #8]
	sub	r0, r0, #1
	bl	fib
	ldr	r1, [sp, #8]
	sub	r1, r1, #2
	str	r0, [sp, #4]            @ 4-byte Spill
	mov	r0, r1
	bl	fib
	ldr	r1, [sp, #4]            @ 4-byte Reload
	add	r0, r1, r0
	str	r0, [r11, #-4]
.LBB0_3:
	ldr	r0, [r11, #-4]
	mov	sp, r11
	pop	{r11, pc}
.Lfunc_end0:
	.size	fib, .Lfunc_end0-fib
	.cantunwind
	.fnend
                                        @ -- End function
	.ident	"clang version 10.0.0 "
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.addrsig_sym fib
	.eabi_attribute	30, 6	@ Tag_ABI_optimization_goals
