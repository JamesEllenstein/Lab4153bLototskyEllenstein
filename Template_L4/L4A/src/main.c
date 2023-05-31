/*
 * ECE 153B - Winter 2023
 *
 * Name(s):
 * Section:
 * Lab: 4A
 */


#include "stm32l476xx.h"
#include "LED.h"
#include "SysClock.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>

// Initializes USARTx
// USART2: UART Communication with Termite
// USART1: Bluetooth Communication with Phone
void Init_USARTx(int x) {
	if(x == 1) {
		UART1_Init();
		UART1_GPIO_Init();
		USART_Init(USART1);
	} else if(x == 2) {
		UART2_Init();
		UART2_GPIO_Init();
		USART_Init(USART2);
	} else {
		// Do nothing...
	}
}

int main(void) {
	System_Clock_Init(); // Switch System Clock = 80 MHz
	LED_Init();
	Green_LED_Toggle();
	
	// Initialize UART -- change the argument depending on the part you are working on
	Init_USARTx(1);
	int led = 0;
	char rxByte;
	while(1) {
		// [TODO]
		printf("Please give an input(y/n):");
		Init_USARTx(1);
		scanf("%c",&rxByte);
		Init_USARTx(1);
		if (rxByte == 'n' || rxByte == 'N') {
			if (led == 1) {
			printf("LED turned off \n");
				Init_USARTx(1);
			}
			Green_LED_Off();
			led = 0;
			
		} else if (rxByte == 'y' || rxByte == 'Y') {
			if (led == 0) {
				printf("LED turned on \n");
				Init_USARTx(1);
			}
			Green_LED_On();
			led = 1;
		} else {
			printf("Please give a valid input \n");
			Init_USARTx(1);
		}
	}
}
