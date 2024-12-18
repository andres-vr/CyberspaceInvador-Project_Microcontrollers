#include <stdio.h>
#include "string.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// #define PLAYER 34
// #define ALIEN 35
#define LINKS 27
#define RECHTS 25
#define SCHIET 26
/*
void IRAM_ATTR ISR()
{
    char receivedNumber = UART_ReadRxData();
    char buffer[20];
    sprintf(buffer, "%d", receivedNumber);
    print();

    // data analyseren en output meegeven
    if (strcmp(buffer, "Xp"))
    {
        gpio_set_level(PLAYER, 1);
        vTaskDelay(50);
        gpio_set_level(PLAYER, 0);
        vTaskDelay(50);
        UART_PutString("The Player has won the game!");
    }
    if (strcmp(buffer, "Xa"))
    {
        gpio_set_level(ALIEN, 1);
        vTaskDelay(50);
        gpio_set_level(ALIEN, 0);
        vTaskDelay(50);
        UART_PutString("The Alien has won the game!");
    }
}
*/

void app_main(void)
{
    gpio_reset_pin(LINKS);
    gpio_set_direction(LINKS, GPIO_MODE_INPUT);
    gpio_pullup_en(LINKS);

    gpio_reset_pin(RECHTS);
    gpio_set_direction(RECHTS, GPIO_MODE_INPUT);
    gpio_pullup_en(RECHTS);

    gpio_reset_pin(SCHIET);
    gpio_set_direction(SCHIET, GPIO_MODE_INPUT);
    gpio_pullup_en(SCHIET);
    /*gpio_reset_pin(ALIEN);
    gpio_set_direction(ALIEN, GPIO_MODE_INPUT_OUTPUT);
    gpio_reset_pin(PLAYER);
    gpio_set_direction(PLAYER, GPIO_MODE_INPUT_OUTPUT);*/

    // my_UART_start();
    // vTaskDelay(10);
    // incoming_StartEx(RX_int);

    while (1)
    {
        printf("loop\n");
        vTaskDelay(100);
        if (gpio_get_level(LINKS) == 0)
        {
            // gpio_isr_handler_add(LINKS, ISR, (void *)LINKS);

            //printf("links\n");
            printf("0\n");
        }
        if (gpio_get_level(RECHTS) == 0)
        {
            //printf("rechts\n");
            printf("1\n");
        }
        if (gpio_get_level(SCHIET) == 0)
        {
            //printf("schiet\n");
            printf("2\n");
        }
    }
}
