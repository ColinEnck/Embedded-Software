#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

void displayNum(int num, int digit, uint pins[], uint digits[]);
void turnOff(uint pins[], uint digits[]);

int main()
{
    const uint pins[7] = { 6, 7, 8, 9, 18, 17, 16 };
    const uint digits[4] = { 10, 11, 12, 13 }; 
    const uint button = 0;
    for (int i = 0; i < 7; ++i)
    {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }
    for (int i = 0; i < 4; ++i)
    {
        gpio_init(digits[i]);
        gpio_set_dir(digits[i], GPIO_OUT);
    }

    gpio_init(button);
    gpio_set_dir(button, GPIO_IN);
    gpio_set_input_enabled(button, true);

    set_time:;
    time_t unix_time = time(NULL); 
    unsigned int seconds = 0;
    unsigned int minutes = 0;
    unsigned int hours = 0;

    // NOTE the execution loop is here vvvvvvvv

    for (;;)
    {

        if (gpio_get(button)) goto set_time;

        if (minutes == 60) 
        {
            seconds = 0;
            minutes = 0;
        }

        if (unix_time != time(NULL)) 
        {
            unix_time = time(NULL);
            ++seconds;
        } 

        minutes = seconds / 60;

        displayNum((seconds % 10), 0, pins, digits);
        sleep_ms(1);
        displayNum(((seconds / 10) % 6), 1, pins, digits);
        sleep_ms(1);
        displayNum((minutes % 10), 2, pins, digits);
        sleep_ms(1);
        displayNum(((minutes / 10) % 6), 3, pins, digits);
        sleep_ms(1);
    }

    // NOTE it's here ^^^^^^^^^^^^^^^^^^^^^^^^^
}

void displayNum(int num, int digit, uint pins[], uint digits[])
{
    turnOff(pins, digits);
    gpio_put(digits[digit], true);
    switch (num) 
    {
    case 0:
        for (int i = 0; i < 7; ++i)
            if (i != 3) gpio_put(pins[i], true);
        break;
    case 1:
        gpio_put(pins[0], true);
        gpio_put(pins[4], true);
        break;
    case 2:
        for (int i = 0; i < 7; ++i)
            if (i != 2 && i != 4) gpio_put(pins[i], true);
        break;
    case 3:
        for (int i = 0; i < 7; ++i)
            if (i != 2 && i != 6) gpio_put(pins[i], true);
        break;
    case 4:
        gpio_put(pins[2], true);
        gpio_put(pins[3], true);
        gpio_put(pins[0], true);
        gpio_put(pins[4], true);
        break;
    case 5:
        for (int i = 0; i < 7; ++i)
            if (i != 0 && i != 6) gpio_put(pins[i], true);
        break;
    case 6:
        for (int i = 0; i < 7; ++i)
            if (i != 0) gpio_put(pins[i], true);
        break;
    case 7:
        gpio_put(pins[1], true);
        gpio_put(pins[0], true);
        gpio_put(pins[4], true);
        break;
    case 8:
        for (int i = 0; i < 7; ++i)
            gpio_put(pins[i], true);
        break;
    case 9:
        for (int i = 0; i < 7; ++i)
            if (i != 6) gpio_put(pins[i], true);
        break;
    }
}

void turnOff(uint pins[], uint digits[])
{
    for (int i = 0; i < 4; ++i)
        gpio_put(digits[i], false);
    for (int i = 0; i < 7; ++i)
        gpio_put(pins[i], false);
}