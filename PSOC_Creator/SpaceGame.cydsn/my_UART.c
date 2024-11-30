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



char readBuf[100];
char *rdpt = readBuf;
int bericht = 0;


CY_ISR(myrxint)
{
    char temp = UART_GetChar();
    UART_PutChar(temp);
    *rdpt = temp;
    rdpt++;
    
    if(temp == '\r')
    {
        bericht =1;
        *(rdpt-1) = 0;
        rdpt = readBuf;
    }
    
}

void my_UART_start(void)
{
    UART_Start();
    incoming_StartEx(myrxint);
    
}
int _write(int file, char *ptr, int len)
{
    int i;
    file = file;
    for (i = 0; i < len; i++){
        UART_PutChar(*ptr++);
    }
    return len;
}
/* [] END OF FILE */
