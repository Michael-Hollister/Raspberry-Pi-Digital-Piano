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

namespace Button {
	namespace Data {
		struct ButtonData {
			bool pressed = false;
			bool dampSound = false;
			float soundVolume = 100;

			sf::Sound sound;
		};

		ButtonData C;
		ButtonData CS;
		ButtonData D;
		ButtonData DS;
		ButtonData E;
		ButtonData F;
		ButtonData FS;
		ButtonData G;
		ButtonData GS;
		ButtonData A;
		ButtonData AS;
		ButtonData B;
		ButtonData C_High;

		bool instrumentChangePressed = false;
		bool octaveChangePressed = false;
	}

	// GPIO pin number mappings
	enum {
		C = 5,
		CS = 6,
		D = 13,
		DS = 21,
		E = 20,
		F = 16,
		FS = 12,
		G = 25,
		GS = 24,
		A = 23,
		AS = 18,
		B = 27,
		C_High = 22,
		InstrumentChange = 17,
		OctaveChange = 4
	};
}

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
void pinInitialization(void);
void soundInitialization(void);

void readNoteButtonInput(int pin, Button::Data::ButtonData & data);
void instrumentChange(Instrument & currentInstrument);
void octaveChange(Octave & currentOctave);
void soundChange(Instrument currentInstrument, Octave currentOctave);
void displayChange(Instrument currentInstrument, Octave currentOctave);

namespace SoundBuffer {
	const float dampingConstant = 0.0018;

	namespace Piano {
		namespace High {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Medium {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Low {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}
	}

	namespace Guitar {
		namespace High {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Medium {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Low {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}
	}

	namespace Trumpet {
		namespace High {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Medium {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}

		namespace Low {
			sf::SoundBuffer C;
			sf::SoundBuffer CS;
			sf::SoundBuffer D;
			sf::SoundBuffer DS;
			sf::SoundBuffer E;
			sf::SoundBuffer F;
			sf::SoundBuffer FS;
			sf::SoundBuffer G;
			sf::SoundBuffer GS;
			sf::SoundBuffer A;
			sf::SoundBuffer AS;
			sf::SoundBuffer B;
			sf::SoundBuffer C_High;
		}
	}
}

#endif
