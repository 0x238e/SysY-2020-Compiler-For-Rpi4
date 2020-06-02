.arch armv7-a

.text
	.align 4
	.arm
fib:
	push	{r4, r5, r6, lr}
	mov	r4, r0
	cmp	r0, #2
	ble	less_than_2

else:
	sub	r0, r4, #1
	bl	fib
	mov	r5, r3
	sub	r0, r4, #2
	bl	fib
	mov	r6, r3
	@ r3 is used as the return value
	add	r3, r5, r6
	b	fib_ret

less_than_2:
	mov	r3, #1

fib_ret:
	pop	{r4, r5, r6, pc}

.global main
main:
	push	{fp, lr}
	mov	r0, #10
	bl	fib
	mov	r0, r3
	pop	{fp, pc}
