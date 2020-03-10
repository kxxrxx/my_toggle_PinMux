#include <stdint.h>
#include <stdbool.h>
#include "toggle_PinMux.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

#define 	GREEN_MASK 		0x08

//*****************************************************************************
//
//!
//! A very simple example that toggles the on-board green LED using PinMux for 
//! port initialization and functions in Peripheral Driver Library for port access
//
//*****************************************************************************
void
PortFunctionInit(void)
{
    //
    // Enable Peripheral Clocks 
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Enable pin PF1 for GPIOOutput
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
}

int main(void)
{
    uint8_t LED_data;
	
		//initialize the GPIO ports	
		PortFunctionInit();
	
    // Turn on the green LED.
    LED_data= GREEN_MASK;
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    
    //
    // Loop forever.
    //
    while(1)
    {
        // Delay for a bit.
				SysCtlDelay(2000000);	

        // Toggle the LED.
        LED_data^=GREEN_MASK;	//toggle green LED (PF3)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    }
}
