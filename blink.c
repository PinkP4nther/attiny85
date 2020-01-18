/*
 * Compile:
 * avr-gcc -Os -DF_CPU=1000000 -mmcu=attiny85 -o blink.o blink.c
 * avr-objcopy -j .text -j .data -O ihex blink.o blink.hex
 * avrdude -c usbtiny -p t85 -U flash:w:blink.hex:i
 */

#include <avr/io.h>
#include <util/delay.h>

#define LED		0

void blink(int dlay, int dlay2) {

	PORTB |= (1 << LED);
	
	if (dlay == 0)
		_delay_ms(1000);
	else if (dlay == 1)
		_delay_ms(500);
	
	PORTB &= ~(1 << LED);
	
	if (dlay2 == 0)
		_delay_ms(4000);
	else if (dlay2 == 1)
		_delay_ms(2000);
	
	PORTB |= (1 << LED);
	
	if (dlay == 0)
		_delay_ms(1000);
	else if (dlay == 1)
		_delay_ms(500);

	PORTB &= ~(1 << LED);
}


int main() {
	
	uint8_t tswitch = 0;

	while (1) {

		//slow blink
		if (tswitch == 0) {
			blink(0,0);
			tswitch = !tswitch;
		}
		// fast blink
		else if (tswitch == 1) {
			blink(1,1);
			tswitch = !tswitch;
		}

		_delay_ms(5000);
		
	}
}
