/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	16th January 2022	 ***/
/*******************************/

#include <asf.h>
#include "Ultrasonic.h"
#include "LCD.h"
#include "PowerManagement.h"

/*------------------ Global variables ---------------*/
volatile uint16_t pulse;
volatile uint8_t iIRC = 0;
volatile int f_wdt = 1;

int main(void)
{
	while( f_wdt == 1 )
	{
		uint8_t distance = 0;
		uint8_t diagnostics = 0;
		
		/* Ultrasonic sensor */
		init_ultrasonic();
		distance = getDistance_main(&diagnostics);
		
		/* Display measurements */
		displayLCD_main(1, "Distance = ", distance, " cm");
		displayLCD_main(2, "DTC = ", diagnostics, "NONE");
		
		/* Power management - processor sleep for energy reduction */
		PwrMngmnt_main();
	}
}


/* *****************************************************************
Name:		Ultrasonic Interrupt
Inputs:		none
Outputs:	internal timer
Description:calculates elapsed time of a measurement
******************************************************************** */
ISR(INT0_vect)
{
	switch (iIRC)
	{
		case 0: //when logic changes from LOW to HIGH
		{
			iIRC = 1;
			TCCR1B |= (1<<CS11);
			break;
		}
		case 1:
		{
			/* reset iIRC */
			iIRC = 0;
			/* stop counter */
			TCCR1B &= ~(1<<CS11);
			/* assign counter value to pulse */
			pulse = TCNT1;
			/* reset counter */
			TCNT1=0;
			break;
		}
	}
}

/* *****************************************************************
Name:		Watchdog Interrupt
Inputs:		none
Outputs:	f_wdt
Description:wakes up processor after internal timer limit reached (8 sec)
******************************************************************** */
ISR(WDT_vect)
{
	/* set the flag. */
	if(f_wdt == 0)
	{
		f_wdt = 1;
	}
	//else there is an error -> flag was not cleared
}
