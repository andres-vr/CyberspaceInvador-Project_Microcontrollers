/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "my_UART.h"
#include "string.h"

int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    my_UART_start();
 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        led_Write(0);
        if(links_Read() == 0)
        {
            UART_PutString("0");
            led_Write(1);
            CyDelay(500);
        }
        if(rechts_Read() == 0)
        {
            UART_PutString("1");
            led_Write(1);
            CyDelay(500);
        }
        if(schiet_Read() == 0)
        {
            UART_PutString("2");
            led_Write(1);
            CyDelay(500);
        }
    }
}

/* [] END OF FILE */