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
}



