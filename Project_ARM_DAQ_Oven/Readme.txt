SERIAL INPUT/OUTPUT
*******************************************************
CONFIGURATION -SEND FROM PC
REQUEST-SEND FROM PC
RESPONSE-FROM MICROCONTROLLER TO PC

*******************************************************
THE COMMUNICATION ALWAYS FOLLOWS THE FRAME
8 BIT COMMAND FOLLOWED BY 8 BIT DATA
*******************************************************

configuration (from pc)		command		data
**************************************************************************************************
initialize adc			0x40		clock div(0-255)
initialize capture		0x48		dont care
initialize pwm			0x50		period size(will be multiplied by 1000 in program)
initialize dac			0x58		dont care
initialize port as input 	0x60		pins to be output in binary
initialize port as output	0x61		pins to be input in binary



request	(from pc)				command		data
**************************************************************************************************
request adc channel data			0x80		clock channel 0-3
request frequecny measured			0x88		dont care
set pwm duty cycle for pwm1			0x90		pwm duty cycle-0-99
set pwm duty cycle for pwm2			0x91		pwm duty cycle-0-99
input dac with digital value			0x98		digital value to be converted
read port inputs				0xA0		pin to be read
set ports to output				0xA1		pin to be set



response(from microcontroller)			command		data
**************************************************************************************************
request adc channel data			0xC0		adc value in decimal
request frequecny measured			0xC8		frequency in float
set pwm duty cycle for pwm1			dont care	dont care
set pwm duty cycle for pwm2			dont care	dont care
input dac with digital value			dont care	dont care
read port inputs				0xe0		value read from pin 
set ports to output				dont care	dont care
