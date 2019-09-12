/*
 * 	"Cal_Config.h" defines some symbols needed by the rest of the program.
 */

#ifndef _CONFIG_H_			// Prevent double inclusion
#define _CONFIG_H_

/*
 *	These symbols relate to the handling of the EEPROM. If you don't want to
 *	save the correction factor in the EEPROM, set the value of the "USE_EEPROM"
 *	symbol to "DONT_USE".
 *
 *	If you do want to use the EEPROM, then set the "USE_EEPROM: symbol to either
 *	"ESP32" or "ARDNO" depending on which type of processor you are using. If
 *	you don't set it to the correct processor, you will be likely to get
 *	compilation errors related to the EEPROM functions.
 */

#define	DONT_USE	0			// Don't use the EEPROM
#define	ESP32		1			// Running on the ESP32
#define	ARDNO		2			// Running on an Arduino

#define	USE_EEPROM	ESP32		// We're using an ESP32 for now


/*
 *	You might need to change some of the following items.
 *
 *	Although I haven't seen one that does, the Si5351 documentation indicates
 *	that it can be clocked by a 27MHz rather than the more usual 25MHz crystal.
 *	If you happen to have a clock source other than 25MHz, change the following
 *	definition accordingly
 */

#define	SI_XTAL		25000000UL				// Could also be 27000000UL


/*
 *	This defines the default test frequency. If someone simply hits 'Enter' when
 *	asked for the frequency at which to test, this value will be used.
 */

#define	TEST_FREQ	10000000UL			// 10MHz


/*
 *	As the Si5351 module handles all the I2C communications itself without using
 *	the "Wire" library as would be the normal way of handling I2C traffic, the
 *	Si5351 I2C bus can be on any pair of GPIO pins. But beware, it there are other
 *	I2C devices on the processor, the Si5351 MUST be on a separate pair of pins as
 *	TJ's code is incompatible with the standard I2C bus handling.
 *
 *	Normally on an Arduino there are default I2C bus pins. This is not the case
 *	here as TJ's Si5351 code does not use standard libraries, so the pins must
 *	be specified.
 *
 *	The standard I2C address for the Si5351 is 0x60, but we have seen one that has
 *	an address of 0x62; change it if needed.
 */

//	#define	SI_SDA		6					// Non-standard I2C bus pins 
//	#define	SI_SCL		7					// For Arduino UNO testing

	#define	SI_SDA		26					// Non-standard I2C bus pins as used
	#define	SI_SCL		27					// In the VFO program and hardware

#define	SI_I2C_ADDR	0x60					// I2C address of the Si5351 module


/*
 *	The normal output drive level for the Si5351 is 8mA (into an 85 ohm load). You
 *	probably don't need to change it, but other options are available.
 */

#define	VFO_DRIVE	CLK_DRIVE_8MA			// Can be _2MA, _4MA or _6MA also


/*
 *	This is the range limit for the correction factor. It is currently set to
 *	+/- 1,000,000. I don't know for sure what the mazimum range should be, but one
 *	unit that we've seen required a correction factor in the 204K range.
 */

#define CAL_LIMIT 1000000L					// 1MHz for now


/*
 *	If you mess with any of the following, bad things might happen! These are not
 *	used in the calibration program, but are referenced in the Si5351 code.
 */

#define	C_OSC_OFF		0					// No carrier oscillator
#define	C_OSC_CLK0		1					// CLK0 only
#define	C_OSC_CLK1		2					// CLK1 only
#define	C_OSC_QUAD		3					// Quadrature mode (both clocks 90 degrees out of phase)

#define	C_OSC			C_OSC_OFF

#endif
