	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"fib.c"
	.text
	.align	2
	.global	fib
	.arch armv7-a
	.syntax unified
	.arm
	.fpu vfp
	.type	fib, %function
fib:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #12
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	cmp	r3, #2
	bgt	.L2
	mov	r3, #1
	b	.L3
.L2:
	ldr	r3, [fp, #-16]
	sub	r3, r3, #1
	mov	r0, r3
	bl	fib(PLT)
	mov	r4, r0
	ldr	r3, [fp, #-16]
	sub	r3, r3, #2
	mov	r0, r3
	bl	fib(PLT)
	mov	r3, r0
	add	r3, r4, r3
.L3:
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, pc}
	.size	fib, .-fib
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",%progbits
