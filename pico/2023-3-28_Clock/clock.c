#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

void displayNum(int num, int digit, uint pins[], uint digits[]);
void turnDigitsOff(uint digits[]);

int main()
{
	const uint pins[7] = { 6, 7, 8, 9, 18, 17, 16 };
	const uint digits[4] = { 12, 13, 14, 15 };
	const uint buttons[5] = { 0, 1, 2, 3, 4};
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
	for (int i = 0; i < 5; ++i)
	{
		gpio_init(buttons[i]);
		gpio_set_dir(buttons[i], GPIO_IN);
	}

	// NOTE the execution loop is here vvvvvvvv

	for (;;)
	{
		displayNum(0, 0, pins, digits);
	}

	// NOTE it's here ^^^^^^^^^^^^^^^^^^^^^^^^^
}

void displayNum(int num, int digit, uint pins[], uint digits[])
{
	turnDigitsOff(digits);
	gpio_put(digits[digit], false);
	switch (num) 
	{
	case 0:
		for (int i = 0; i < 7; ++i)
		{
			gpio_put(pins[i], true);
			if (i == 3) gpio_put(pins[i], false);
		}
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}
}

void turnDigitsOff(uint digits[])
{
	for (int i = 0; i < 4; ++i)
		gpio_put(digits[i], true);
}
