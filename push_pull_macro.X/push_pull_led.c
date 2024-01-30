
#include "pic24_all.h"
#define LED _LATB14 
// Configure RB14 as normal digital output 
#define CONFIG_LED() CONFIG_RB14_AS_DIG_OUTPUT () 
#define SW _RB13 
// If SW1 = _RB13 = 0 ?> Switch is pressed
#define SW_PRESSED() SW == 0
//If SW1 = _RB13 = 1 ?> Switch is released
 #define SW_RELEASED() SW == 1

int main(void) {
    
    configClock ();
    CONFIG_SW (); // Configure _RB13
    
    //Delay a short time to enable weak pull-up 
	DELAY_US (1);
	
    CONFIG_LED (); // Configure _RB14
    LED=1;
	while (1)
  	{ 
    		//Wait for pressing SW
    		while (SW_RELEASED ()); 
    		DELAY_MS (15);
    		//Wait for releasing SW
    		
            while (SW_PRESSED ());
    		DELAY_MS (15); 
    		LED = !LED; 
  	}


    return 0;
}
inline void CONFIG_SW () 
{
   CONFIG_RB13_AS_DIG_INPUT (); 
   ENABLE_RB13_PULLUP ();
} 

