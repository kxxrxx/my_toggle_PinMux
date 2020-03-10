//*****************************************************************************
// in this example, we change the blinking LED from Red to Green. Also 
// slowed down the blinking by a factor of 5
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "toggle_PinMux.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

#define GREEN_MASK 0x08

//*****************************************************************************
void
PortFunctionInit(void)
{
    //
    // Enable Peripheral Clocks 
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Enable pin PF3 for GPIOOutput
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

    //
    //First open the lock and select the bits we want to modify in the GPIO commit register.
    //
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x1;

    //
    //Now modify the configuration of the pins that we unlocked.
    //
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
}
int main(void)
{
    uint8_t LED_data;
	
		//initialize the GPIO ports	
		PortFunctionInit();
	
    // Turn on the LED.
    LED_data= GREEN_MASK;
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    
    //
    // Loop forever.
    //
    while(1)
    {
        // Delay for a bit.
				SysCtlDelay(10000000);
				SysCtlDelay(10000000);
				SysCtlDelay(10000000);
	    			SysCtlDelay(10000000);
	    			SysCtlDelay(10000000);

        // Toggle the green LED.
        LED_data^=GREEN_MASK;	//toggle green LED (PF3)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    }
}
