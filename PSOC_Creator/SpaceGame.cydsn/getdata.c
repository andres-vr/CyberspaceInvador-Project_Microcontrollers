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
{   if(UART_GetRxBufferSize() > 0) 
    {
    char8 receivedNumber = UART_ReadRxData();
    char buffer[20];

    sprintf(buffer, "%c", receivedNumber);  
    
    if (buffer[0] == 'a')  
    { 
        UART_PutString("The Player has won the game!");
    }
    else if (buffer[0] == 'p')
    { 
        UART_PutString("The Alien has won the game!");
    }
    }
}
