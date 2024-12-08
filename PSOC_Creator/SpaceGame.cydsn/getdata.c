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
    char receivedNumber = UART_ReadRxData();
    
    if (receivedNumber == "5" || receivedNumber == 5)
    {
    led_Write(1);
    CyDelay(1000);
    }
    
   /* // debugging voor visual studio message box
    
    // Debug print to see if function is called
    UART_PutString("Checking for data...\n");
    
    // Print the actual buffer size
    char bufferSize[10];
    sprintf(bufferSize, "Buffer size: %d\n", UART_GetRxBufferSize());
    UART_PutString(bufferSize);
    */
    
    //deze shit mag nie 0 returnen
    if(UART_GetRxBufferSize() > 0) 
    {
        UART_PutString("Data received!\n");
        char receivedNumber = UART_ReadRxData();
       /* char str[2] = {receivedNumber, '\0'};
        UART_PutString(str); */
        led_Write(1);
        led_Write(receivedNumber);
    }
    /*
        if(UART_GetRxBufferSize() > 0) {
        UART_PutString("5\n");
        char receivedNumber = UART_ReadRxData();
        //UART_PutString(receivedNumber);
        led_Write(receivedNumber);
    */
}
