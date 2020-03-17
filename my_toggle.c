#include <stdint.h>
#include <stdbool.h>
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include "C:\ti\TivaWare_C_Series-2.1.4.178\driverlib\sysctl.h"

#define 	GREEN_MASK 		0x08
//*****************************************************************************
//
//!
//! A very simple example that toggles (blinks) the on-board green LED (PF3) using direct 
//! register access. It flashes 5x slower than the original code.
//
//*****************************************************************************


void
PortFunctionInit(void)
{
//
		volatile uint32_t ui32Loop;   
		// Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the green LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R |= 0x08;
    GPIO_PORTF_DEN_R |= 0x08;

}


int main(void)
{
	
		//initialize the GPIO ports	
		PortFunctionInit();
	
    // Turn on the LED.
    GPIO_PORTF_DATA_R |= 0x08;

    
    //
    // Loop forever.
    //
    while(1)
    {
        // Delay for a bit.
				SysCtlDelay(10000000);	// = 2000000*5

        // Toggle the LED.
        GPIO_PORTF_DATA_R ^=GREEN_MASK;
    }
}
