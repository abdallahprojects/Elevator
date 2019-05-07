// motor enable PB0
// motor in1 PB3
// motor in2 PD7

#define InitMotor		DDRB|= (1<<PB0)|(1<<PB3);\
						DDRD|= (1<<PD7)

#define MotorDisable  	PORTB&= ~(1<<PB0)
#define MotorEnable		PORTB|= (1<<PB0)

#define MotorOnLeft     PORTB|= (1<<PB3) ;\
						PORTD&= ~(1<<PD7)
#define MotorOnRight	PORTB&= ~(1<<PB3) ;\
						PORTD|= (1<<PD7)
						
#define MotorOff		PORTB&= ~(1<<PB3) ;\
						PORTD&= ~(1<<PD7)
						
#define MotorHold		PORTB|= (1<<PB3) ;\
						PORTD|= (1<<PD7)
						