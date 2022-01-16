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
#define U_ECHO_pin		PIND2
#define U_TRIG_pin		PIND3
#define U_PWR_pin		PIND1

#define ULTR_PWR_ON		PORTD |= (1<<U_PWR_pin)
#define ULTR_PWR_OFF	PORTD &= ~(1<<U_PWR_pin)

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