@ ---- start of .data section ---- @
.align 4
.data
arr:
	.word	1
	.word	2
	.word	3
	.word	4

a:
	.word	1234

@ ---- end of .data section ---- @
@ ---- start of .text section ---- @
.align 4
.text
.global main

fib:
	push	{r4, r5, r6, r7, r8, r9, fp, lr}
	mov	fp, sp
fib_0:
	sub	sp, sp, #4
	sub	sp, sp, #4
	str	r0, [fp, #-8]
	ldr	r6, [fp, #-8]
	cmp	r6, #2
	bgt	fib_2
fib_1:
	mov	r10, #1
	str	r10, [fp, #-4]
	b	fib_3
fib_2:
	ldr	r6, [fp, #-8]
	sub	r6, r6, #1
	mov	r0, r6
	bl	fib
	mov	r6, r0
	ldr	r5, [fp, #-8]
	sub	r5, r5, #2
	mov	r0, r5
	bl	fib
	mov	r5, r0
	add	r5, r6, r5
	str	r5, [fp, #-4]
	b	fib_3
fib_3:
	ldr	r4, [fp, #-4]
	mov	r0, r4
	mov	sp, fp
	pop	{r4, r5, r6, r7, r8, r9, fp, pc}


main:
	push	{r4, r5, r6, r7, r8, r9, fp, lr}
	mov	fp, sp
main_0:
	sub	sp, sp, #4
	sub	sp, sp, #4
	sub	sp, sp, #4
	sub	sp, sp, #4
	mov	r10, #0
	str	r10, [fp, #-4]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	mov	r10, #0
	sub	r4, r10, r4
	str	r4, [fp, #-8]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	add	r4, r4, #1
	ldr	r10, =a
	str	r4, [r10, #0]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	sub	r4, r4, #2
	ldr	r10, =a
	str	r4, [r10, #0]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	mov	r10, #3
	mul	r4, r4, r10
	ldr	r10, =a
	str	r4, [r10, #0]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	@ division operation
	mov	r0, r4
	mov	r1, #4
	bl	__divsi3
	mov	r4, r0
	ldr	r10, =a
	str	r4, [r10, #0]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	@ remainder operation
	mov	r0, r4
	mov	r1, #5
	bl	__modsi3
	mov	r4, r0
	ldr	r10, =a
	str	r4, [r10, #0]
	ldr	r10, =a
	ldr	r4, [r10, #0]
	cmp	r4, #0
	ble	main_2
main_1:
	ldr	r10, =a
	ldr	r4, [r10, #0]
	str	r4, [fp, #-8]
	b	main_6
main_2:
	ldr	r10, =a
	ldr	r4, [r10, #0]
	cmp	r4, #0
	bne	main_4
main_3:
	mov	r10, #0
	str	r10, [fp, #-8]
	b	main_5
main_4:
	ldr	r10, =a
	ldr	r4, [r10, #0]
	mov	r10, #0
	sub	r4, r10, r4
	str	r4, [fp, #-8]
	b	main_5
main_5:
	b	main_6
main_6:
	ldr	r4, [fp, #-8]
	cmp	r4, #0
	ble	main_7
main_7:
	b	main_9
main_8:
	ldr	r4, [fp, #-8]
	mov	r0, r4
	bl	fib
	mov	r4, r0
	str	r4, [fp, #-8]
	b	main_9
main_9:
	ldr	r10, =a
	ldr	r4, [r10, #0]
	ldr	r5, [fp, #-8]
	add	r4, r4, r5
	ldr	r10, =arr+12
	str	r4, [r10, #0]
	mov	r10, #10
	str	r10, [fp, #-12]
	mov	r10, #0
	str	r10, [fp, #-16]
	b	main_10
main_10:
	ldr	r4, [fp, #-12]
	cmp	r4, #0
	ble	main_12
main_11:
	ldr	r5, [fp, #-16]
	ldr	r8, [fp, #-12]
	add	r5, r5, r8
	str	r5, [fp, #-16]
	ldr	r5, [fp, #-12]
	sub	r5, r5, #1
	str	r5, [fp, #-12]
	b	main_10
main_12:
	ldr	r4, [fp, #-16]
	ldr	r10, =arr+12
	ldr	r5, [r10, #0]
	add	r4, r4, r5
	mov	r0, r4
	mov	sp, fp
	pop	{r4, r5, r6, r7, r8, r9, fp, pc}

@ ---- end of .text section ---- @
