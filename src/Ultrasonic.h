/*
 * Ultrasonic.h
 *
 * Created: 14.03.2020 17:19:25
 *  Author: lenovo
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/* Configuration */
#define DIST_MAX 250			// Upper limit of the sensor
#define DIST_MIN 10				// Lower limit of the sensor
#define ULTRAS_ITER_MAX 3		// max iterations in the case measurements are not consistent
#define DISTANCE_E_NOK 0xFF		
#define SNSR_TOLERANCE 5		// cm

/* Macros */
/* Trigger pin */
#define U_Port_trig		PORTB
#define U_DDR_trig		DDRB
#define U_TRIG_pin		PINB4
/* Echo pin */
#define U_Port_echo		PORTD
#define U_DDR_echo		DDRD
#define U_ECHO_pin		PIND2
/* Power pin */
#define U_Port_pwr		PORTB
#define U_DDR_pwr		DDRB
#define U_PWR_pin		PINB5

#define ULTR_PWR_ON		U_Port_pwr |= (1<<U_PWR_pin)
#define ULTR_PWR_OFF	U_Port_pwr &= ~(1<<U_PWR_pin)


/* Prototype functions */
void configUltrasonicPorts(void);
void enable_interrupts(void);
void disableInterrupts(void);
uint8_t getLevel_main (void);
uint8_t getDistance_main(uint8_t *);
uint16_t getLevel(uint16_t);
float getDistance(void);
void triggerUltrasonic(void);
void init_ultrasonic(void);


#endif /* ULTRASONIC_H_ */