// This source code is subject to the terms of The MIT License.
// If a copy of The MIT License was not distributed with this file,
// you can obtain one at http://opensource.org/licenses/MIT.

#ifndef MAIN_H
#define MAIN_H

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
	C = 5,
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
