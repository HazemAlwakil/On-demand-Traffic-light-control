/*
 * On-demand Traffic light control.c
 *
 * Created: 10/4/2022 8:57:59 PM
 * Author : Hazem Alwakil
 */ 
#include "Application/application.h"
#include "MCAL/DIO Driver/dio.h"

int main(void)
{
    /* Initializing */
	APP_init();
	
	/* Starting Application */
 while (1) 
    {
		APP_start();
    }

//Drivers testing
/*BUTTON_init('D',2); // init button
LED_init('B',0); // init RED LED 
TIMER_init(); // init timer
while(1)
{

	uint8_t state=0;
	BUTTON_read('D',2,&state);
	if(state== 1)
	{
		
		LED_on('B',0);
		TIMER_delay(3000);
		LED_toggle('B',0);
		TIMER_delay(2000);
		LED_toggle('B',0);
		TIMER_delay(2000);
		LED_off('B',0);
				
	}
	
	
}*/

}

