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


void ReceiveData()
{   
    if(UART_GetRxBufferSize() > 0) 
    {
        char receivedNumber = UART_ReadRxData();
        
        if (receivedNumber == '5')
        {
            led_Write(1);
            CyDelay(1000);
        }
    }
}
