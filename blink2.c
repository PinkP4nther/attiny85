/*
 * Compile:
 * avr-gcc -Os -DF_CPU=1000000 -mmcu=attiny85 -o blink2.o blink2.c
 * avr-objcopy -j .text -j .data -O ihex blink2.o blink2.hex
 * avrdude -c usbtiny -p t85 -U flash:w:blink2.hex:i
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED	0

void blink() {
	
	PORTB |= (1 << LED);
	_delay_ms(500); // Speed of blink
	PORTB &= ~(1 << LED);
}

void dlay(uint8_t di) {
	if (di == 0)
		_delay_ms(0);
	else if (di == 1)
		_delay_ms(1000);
	else if (di == 2)
		_delay_ms(2000);
	else if (di == 3)
		_delay_ms(3000);
	else if (di == 4)
		_delay_ms(4000);
	else if (di == 5)
		_delay_ms(5000);
	else if (di == 6)
		_delay_ms(6000);
	else if (di == 7)
		_delay_ms(7000);
	else if (di == 8)
		_delay_ms(8000);
	else if (di == 9)
		_delay_ms(9000);
	else
		return;
}

int main() {
	
	uint8_t rn;
	while (1) {

		rn = (uint8_t) rand();
		rn = rn & 0x0f; // Logical AND to cut rand to 0 <-> 15
		if ( rn > 9)
			rn -= 6; // Will always be 9 or less
		dlay(rn);
		blink();
	}
}
