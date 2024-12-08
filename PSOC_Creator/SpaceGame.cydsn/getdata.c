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
    if(UART_GetRxBufferSize() > 0) {
        uint8_t receivedByte = UART_ReadRxData();
        led_Write(receivedByte);
    }
}
