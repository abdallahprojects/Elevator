	.file	"main.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.data
.LC0:
	.string	"Forward Direction !!"
.LC1:
	.string	"Backward Direction !!"
	.text
.global	main
	.type	main, @function
main:
	push r14
	push r15
	push r16
	push r17
	push r29
	push r28
	rcall .
	rcall .
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 5 */
	movw r26,r28
	adiw r26,1
	ldi r30,lo8(C.0.1270)
	ldi r31,hi8(C.0.1270)
	ldi r24,lo8(5)
.L2:
	ld r0,Z+
	st X+,r0
	subi r24,lo8(-(-1))
	brne .L2
	out 58-32,__zero_reg__
	ldd r20,Y+1
	ldd r21,Y+2
	ldd r22,Y+3
	ldd r23,Y+4
	ldd r24,Y+5
	call LCD_Init
	ldi r24,lo8(800)
	ldi r25,hi8(800)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L3:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L3
	ldi r24,lo8(.LC0)
	ldi r25,hi8(.LC0)
	call LCD_puts
	ldi r24,lo8(-1)
	out 55-32,r24
	out 49-32,r24
	in r24,56-32
	ori r24,lo8(9)
	out 56-32,r24
	cbi 50-32,7
	ldi r24,lo8(0)
	ldi r16,lo8(200)
	ldi r17,hi8(200)
	ldi r25,lo8(20000)
	mov r14,r25
	ldi r25,hi8(20000)
	mov r15,r25
.L15:
	sbic 57-32,0
	ori r24,lo8(1)
.L4:
	cpi r24,lo8(1)
	brne .L15
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(1)
	call LCD_Write
	ldi r24,lo8(800)
	ldi r25,hi8(800)
.L6:
	movw r30,r16
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L6
	ldi r24,lo8(.LC1)
	ldi r25,hi8(.LC1)
	call LCD_puts
	cbi 56-32,0
	ldi r24,lo8(-25536)
	ldi r25,hi8(-25536)
.L7:
	movw r30,r16
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L7
	sbi 56-32,0
	cbi 56-32,3
	sbi 50-32,7
	movw r24,r14
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(3)
	rjmp .L15
	.size	main, .-main
	.data
	.type	C.0.1270, @object
	.size	C.0.1270, 5
C.0.1270:
	.word	53
	.byte	102
	.byte	167
	.byte	0
.global __do_copy_data
