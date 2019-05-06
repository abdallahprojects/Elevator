	.file	"main.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.data
.LC0:
	.string	"Elevator Project!"
.LC1:
	.string	"FW Direction !!"
.LC2:
	.string	"BW Direction !!"
	.text
.global	main
	.type	main, @function
main:
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
	ldi r30,lo8(C.0.1285)
	ldi r31,hi8(C.0.1285)
	ldi r24,lo8(5)
.L2:
	ld r0,Z+
	st X+,r0
	subi r24,lo8(-(-1))
	brne .L2
	out 58-32,__zero_reg__
	ldi r24,lo8(-1)
	out 59-32,r24
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
	ldi r24,lo8(-1)
	out 55-32,r24
	out 49-32,r24
	ldi r24,lo8(.LC0)
	ldi r25,hi8(.LC0)
	call LCD_puts
.L4:
	sbic 57-32,0
	rjmp .L4
.L9:
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(1)
	call LCD_Write
	ldi r24,lo8(2000)
	ldi r25,hi8(2000)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L6:
	movw r30,r18
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
	ldi r24,lo8(10000)
	ldi r25,hi8(10000)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L7:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L7
	sbi 56-32,0
	sbi 56-32,3
	cbi 50-32,7
.L8:
	sbic 57-32,0
	rjmp .L8
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(1)
	call LCD_Write
	ldi r24,lo8(2000)
	ldi r25,hi8(2000)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L10:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L10
	ldi r24,lo8(.LC2)
	ldi r25,hi8(.LC2)
	call LCD_puts
	cbi 56-32,0
	ldi r24,lo8(10000)
	ldi r25,hi8(10000)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L11:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L11
	sbi 56-32,0
	cbi 56-32,3
	sbi 50-32,7
.L12:
	sbic 57-32,0
	rjmp .L12
	rjmp .L9
	.size	main, .-main
	.data
	.type	C.0.1285, @object
	.size	C.0.1285, 5
C.0.1285:
	.word	53
	.byte	102
	.byte	167
	.byte	0
.global __do_copy_data
