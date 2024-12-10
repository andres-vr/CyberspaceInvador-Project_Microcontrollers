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
        led_Write(0);
        CyDelay(1000);
        led_Write(1);
        CyDelay(1000);
        UART_ClearRxBuffer();
    } 
}
        /*
        //data inlezen
        char8 receivedNumber = UART_ReadRxData();
        char buffer[20];

        sprintf(buffer, "%d", receivedNumber); 
        
        //data analyseren en output meegeven
        if (strcmp(buffer, "Xp")) 
        { 
            UART_PutString("The Player has won the game!");
        }
        else if (strcmp(buffer, "Xa")) 
        { 
            UART_PutString("The Alien has won the game!");
        } 
        */


