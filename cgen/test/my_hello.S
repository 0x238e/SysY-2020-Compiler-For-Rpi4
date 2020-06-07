@ Architecture specific attributes
.arch armv7-a
.file	"hello.c"

@ .data section usually contains initialized data
.data
	.align	4
hello_str:
	.asciz	"Hello world!"

@ .text section contains code
.text
	.align	4
	.global	main
	.syntax unified
	.arm
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
@ function prologue
	push	{fp, lr}
	add	fp, sp, #4
@ arguments are passed in r0 - r3
	ldr	r0, =hello_str + 2
@ libc function calls are appended with (PLT)
	bl	puts(PLT)
	mov	r0, #99
	bl	putchar(PLT)
	mov	r3, #0
	mov	r0, r3
	pop	{fp, pc}
