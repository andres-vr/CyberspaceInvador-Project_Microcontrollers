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
#include "getdata.h"

CY_ISR(RX_int)
{
        char8 receivedNumber = UART_ReadRxData();
        char buffer[20];

        sprintf(buffer, "%d", receivedNumber); 
        
        //data analyseren en output meegeven
        if (strcmp(buffer, "Xp")) 
        { 
            player_Write(1);
            CyDelay(1000);
            player_Write(0);
            CyDelay(1000);
            UART_PutString("The Player has won the game!");
        }
        if (strcmp(buffer, "Xa")) 
        { 
            alien_Write(1);
            CyDelay(1000);
            alien_Write(0);
            CyDelay(1000);
            UART_PutString("The Alien has won the game!");
        }
}
int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    my_UART_start();
    CyDelay(1000);
    incoming_StartEx(RX_int);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(links_Read() == 0)
        {
            UART_PutString("0\n");
            CyDelay(500);
        }
        if(rechts_Read() == 0)
        {
            UART_PutString("1\n");
            CyDelay(500);
        }
        if(schiet_Read() == 0)
        {
            UART_PutString("2\n");
            CyDelay(500);
        }
    }
}

/* [] END OF FILE */