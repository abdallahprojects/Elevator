	.file	"lcd1602A.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	LCD_Out
	.type	LCD_Out, @function
LCD_Out:
/* prologue: function */
/* frame size = 0 */
	mov r20,r24
	sbrs r24,0
	rjmp .L2
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+3
	lsr r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	or r19,r24
	st Z,r19
	rjmp .L3
.L2:
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+3
	lsr r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	and r24,r19
	st Z,r24
.L3:
	sbrs r20,1
	rjmp .L4
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+3
	swap r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	or r19,r24
	st Z,r19
	rjmp .L5
.L4:
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+3
	swap r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	and r24,r19
	st Z,r24
.L5:
	sbrs r20,2
	rjmp .L6
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r24,lcd+3
	rol r24
	clr r24
	rol r24
	lds r18,lcd+4
	andi r18,lo8(3)
	lsl r18
	or r18,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	or r19,r24
	st Z,r19
	rjmp .L7
.L6:
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r24,lcd+3
	rol r24
	clr r24
	rol r24
	lds r18,lcd+4
	andi r18,lo8(3)
	lsl r18
	or r18,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	and r24,r19
	st Z,r24
.L7:
	sbrs r20,3
	rjmp .L8
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+4
	lsr r18
	lsr r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	or r19,r24
	st Z,r19
	ret
.L8:
	lds r30,lcd
	lds r31,(lcd)+1
	ld r19,Z
	lds r18,lcd+4
	lsr r18
	lsr r18
	andi r18,lo8(7)
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	and r24,r19
	st Z,r24
	ret
	.size	LCD_Out, .-LCD_Out
.global	LCD_Write
	.type	LCD_Write, @function
LCD_Write:
	push r16
	push r17
/* prologue: function */
/* frame size = 0 */
	lds r30,lcd
	lds r31,(lcd)+1
	ld r25,Z
	lds r18,lcd+2
	andi r18,lo8(7)
	ldi r16,lo8(1)
	ldi r17,hi8(1)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r18
	brpl 1b
	movw r18,r20
	com r18
	and r18,r25
	st Z,r18
	call LCD_Out
	lds r30,lcd
	lds r31,(lcd)+1
	ld r18,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r24
	brpl 1b
	or r18,r20
	st Z,r18
	ldi r24,lo8(32000)
	ldi r25,hi8(32000)
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	lds r30,lcd
	lds r31,(lcd)+1
	ld r25,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	rjmp 2f
1:	lsl r16
	rol r17
2:	dec r24
	brpl 1b
	com r16
	and r16,r25
	st Z,r16
/* epilogue start */
	pop r17
	pop r16
	ret
	.size	LCD_Write, .-LCD_Write
.global	LCD_Init
	.type	LCD_Init, @function
LCD_Init:
	push r29
	push r28
	rcall .
	rcall .
	push __tmp_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 5 */
	std Y+1,r20
	std Y+2,r21
	std Y+3,r22
	std Y+4,r23
	std Y+5,r24
	ldi r26,lo8(lcd)
	ldi r27,hi8(lcd)
	movw r30,r28
	adiw r30,1
	ldi r24,lo8(5)
.L14:
	ld r0,Z+
	st X+,r0
	subi r24,lo8(-(-1))
	brne .L14
	lds r24,lcd
	lds r25,(lcd)+1
	cpi r24,59
	cpc r25,__zero_reg__
	brne .L15
	ldi r24,lo8(-1)
	out 58-32,r24
	rjmp .L27
.L15:
	cpi r24,56
	cpc r25,__zero_reg__
	brne .L17
	ldi r24,lo8(-1)
	out 55-32,r24
	rjmp .L27
.L17:
	cpi r24,53
	cpc r25,__zero_reg__
	brne .L18
	ldi r24,lo8(-1)
	out 52-32,r24
	rjmp .L27
.L18:
	sbiw r24,50
	breq .L19
	ldi r24,lo8(0)
	rjmp .L20
.L19:
	ldi r24,lo8(-1)
	out 49-32,r24
.L27:
	ldi r24,lo8(800)
	ldi r25,hi8(800)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L23:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L23
	ldi r24,lo8(3)
	call LCD_Write
	ldi r24,lo8(-25536)
	ldi r25,hi8(-25536)
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(3)
	call LCD_Write
	ldi r24,lo8(640)
	ldi r25,hi8(640)
	ldi r18,lo8(200)
	ldi r19,hi8(200)
.L21:
	movw r30,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r30,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	sbiw r24,1
	brne .L21
	ldi r24,lo8(3)
	call LCD_Write
	ldi r24,lo8(2)
	call LCD_Write
	ldi r24,lo8(2)
	call LCD_Write
	ldi r24,lo8(8)
	call LCD_Write
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(6)
	call LCD_Write
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(12)
	call LCD_Write
	ldi r24,lo8(0)
	call LCD_Write
	ldi r24,lo8(1)
	call LCD_Write
	ldi r24,lo8(1)
.L20:
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop r28
	pop r29
	ret
	.size	LCD_Init, .-LCD_Init
.global	LCD_putc
	.type	LCD_putc, @function
LCD_putc:
	push r13
	push r14
	push r15
	push r16
	push r17
/* prologue: function */
/* frame size = 0 */
	mov r13,r24
	lds r30,lcd
	lds r31,(lcd)+1
	ld r18,Z
	lds r24,lcd+2
	andi r24,lo8(7)
	ldi r16,lo8(1)
	ldi r17,hi8(1)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r24
	brpl 1b
	or r18,r20
	st Z,r18
	mov r24,r13
	swap r24
	andi r24,lo8(15)
	call LCD_Out
	lds r30,lcd
	lds r31,(lcd)+1
	ld r18,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r24
	brpl 1b
	or r18,r20
	st Z,r18
	ldi r24,lo8(320)
	mov r14,r24
	ldi r24,hi8(320)
	mov r15,r24
	movw r24,r14
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	lds r30,lcd
	lds r31,(lcd)+1
	ld r18,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r24
	brpl 1b
	movw r24,r20
	com r24
	and r24,r18
	st Z,r24
	mov r24,r13
	andi r24,lo8(15)
	call LCD_Out
	lds r30,lcd
	lds r31,(lcd)+1
	ld r18,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	movw r20,r16
	rjmp 2f
1:	lsl r20
	rol r21
2:	dec r24
	brpl 1b
	or r18,r20
	st Z,r18
	movw r24,r14
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	lds r30,lcd
	lds r31,(lcd)+1
	ld r25,Z
	lds r24,lcd+2
	lsr r24
	lsr r24
	lsr r24
	andi r24,lo8(7)
	rjmp 2f
1:	lsl r16
	rol r17
2:	dec r24
	brpl 1b
	com r16
	and r16,r25
	st Z,r16
/* epilogue start */
	pop r17
	pop r16
	pop r15
	pop r14
	pop r13
	ret
	.size	LCD_putc, .-LCD_putc
.global	LCD_puts
	.type	LCD_puts, @function
LCD_puts:
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
	movw r28,r24
	rjmp .L31
.L32:
	call LCD_putc
.L31:
	ld r24,Y+
	tst r24
	brne .L32
/* epilogue start */
	pop r29
	pop r28
	ret
	.size	LCD_puts, .-LCD_puts
.global	LCD_putrs
	.type	LCD_putrs, @function
LCD_putrs:
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
	movw r28,r24
	rjmp .L35
.L36:
	call LCD_putc
.L35:
	ld r24,Y+
	tst r24
	brne .L36
/* epilogue start */
	pop r29
	pop r28
	ret
	.size	LCD_putrs, .-LCD_putrs
	.comm lcd,5,1
.global __do_clear_bss
