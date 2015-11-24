// This source code is subject to the terms of The MIT License.
// If a copy of The MIT License was not distributed with this file,
// you can obtain one at http://opensource.org/licenses/MIT.

#ifndef MAIN_H
#define MAIN_H

// --- Code snippet from http://wiringpi.com/examples/adafruit-rgb-lcd-plate-and-wiringpi/ 
// Defines for the Adafruit Pi LCD interface board
#define AF_BASE         100
#define AF_RED          (AF_BASE + 6)
#define AF_GREEN        (AF_BASE + 7)
#define AF_BLUE         (AF_BASE + 8)

#define AF_E            (AF_BASE + 13)
#define AF_RW           (AF_BASE + 14)
#define AF_RS           (AF_BASE + 15)

#define AF_DB4          (AF_BASE + 12)
#define AF_DB5          (AF_BASE + 11)
#define AF_DB6          (AF_BASE + 10)
#define AF_DB7          (AF_BASE +  9)

#define AF_SELECT       (AF_BASE +  0)
#define AF_RIGHT        (AF_BASE +  1)
#define AF_DOWN         (AF_BASE +  2)
#define AF_UP           (AF_BASE +  3)
#define AF_LEFT         (AF_BASE +  4)

static int lcdHandle;
// ---


// GPIO pin number mappings
enum Button {
	C = 18,
	CS = 23,
	D = 24,
	DS = 25,
	E = 12,
	F = 16,
	FS = 20,
	G = 21,
	GS = 4,
	A = 17,
	AS = 27,
	B = 22,
	C_High = 5,
	InstrumentChange = 6,
	OctaveChange = 13
};

enum Instrument {
	Piano,
	Guitar,
	Trumpet
} currentInstrument;

enum Octave {
	Low,
	Medium,
	High
} currentOctave;



void initialization(void);
void instrumentChange(Instrument & currentInstrument);
void octaveChange(Octave & currentOctave);
void displayChange(Instrument currentInstrument, Octave currentOctave);

#endif
