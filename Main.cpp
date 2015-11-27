// This source code is subject to the terms of The MIT License.
// If a copy of The MIT License was not distributed with this file,
// you can obtain one at http://opensource.org/licenses/MIT.

#include <iostream>
#include <string>
#include <wiringPi.h>
#include <lcd.h>
#include <mcp23017.h>
#include <SFML/Audio.hpp>
#include "Main.h"

using namespace std;

int main()
{
	initialization();
	
	// Main loop
	while (true) {
		
		readNoteButtonInput(Button::C, Button::Data::C);
		readNoteButtonInput(Button::CS, Button::Data::CS);
		readNoteButtonInput(Button::D, Button::Data::D);
		readNoteButtonInput(Button::DS, Button::Data::DS);
		readNoteButtonInput(Button::E, Button::Data::E);
		readNoteButtonInput(Button::F, Button::Data::F);
		readNoteButtonInput(Button::FS, Button::Data::FS);
		readNoteButtonInput(Button::G, Button::Data::G);
		readNoteButtonInput(Button::GS, Button::Data::GS);
		readNoteButtonInput(Button::A, Button::Data::A);
		readNoteButtonInput(Button::AS, Button::Data::AS);
		readNoteButtonInput(Button::B, Button::Data::B);
		readNoteButtonInput(Button::C_High, Button::Data::C_High);
		
		if (Button::Data::instrumentChangePressed == false) {
			if (digitalRead(Button::InstrumentChange) == true) {
				instrumentChange(currentInstrument);
				Button::Data::instrumentChangePressed = true;
			}
		}
		
		if (Button::Data::instrumentChangePressed == true) {
			if (digitalRead(Button::InstrumentChange) == false) {
				Button::Data::instrumentChangePressed = false;
			}
		}

		// ---

		if (Button::Data::octaveChangePressed == false) {
			if (digitalRead(Button::OctaveChange) == true) {
				octaveChange(currentOctave);
				Button::Data::octaveChangePressed = true;
			}
		}
		
		if (Button::Data::octaveChangePressed == true) {
			if (digitalRead(Button::OctaveChange) == false) {
				Button::Data::octaveChangePressed = false;
			}
		}
		
	}

   return 0; // Exit program
}

void initialization(void) {
	wiringPiSetupGpio();

	// --- Code snippet from http://wiringpi.com/examples/adafruit-rgb-lcd-plate-and-wiringpi/ 
	mcp23017Setup(AF_BASE, 0x20);
	
	//	Backlight LEDs
	pinMode(AF_RED, OUTPUT);
	pinMode(AF_GREEN, OUTPUT);
	pinMode(AF_BLUE, OUTPUT);
	pinMode(AF_RW, OUTPUT); digitalWrite(AF_RW, LOW);	// Not used with wiringPi - always in write mode
														// The other control pins are initialised with lcdInit ()
	
	lcdHandle = lcdInit(2, 16, 4, AF_RS, AF_E, AF_DB4, AF_DB5, AF_DB6, AF_DB7, 0, 0, 0, 0);

	if (lcdHandle < 0)
	{
		fprintf(stderr, "lcdInit failed\n");
		exit(EXIT_FAILURE);
	}
	// ---

	lcdClear(lcdHandle);
	lcdPosition(lcdHandle, 0, 0);
	lcdPuts(lcdHandle, "Initializing...");

	pinInitialization();
	soundInitialization();

	// Defaults setup
	currentInstrument = Instrument::Piano;
	currentOctave = Octave::Medium;

	soundChange(currentInstrument, currentOctave);
	displayChange(currentInstrument, currentOctave);
}

void pinInitialization(void) {
	pinMode(Button::C, INPUT);
	pinMode(Button::CS, INPUT);
	pinMode(Button::D, INPUT);
	pinMode(Button::DS, INPUT);
	pinMode(Button::E, INPUT);
	pinMode(Button::F, INPUT);
	pinMode(Button::FS, INPUT);
	pinMode(Button::G, INPUT);
	pinMode(Button::GS, INPUT);
	pinMode(Button::A, INPUT);
	pinMode(Button::AS, INPUT);
	pinMode(Button::B, INPUT);
	pinMode(Button::C_High, INPUT);
	pinMode(Button::InstrumentChange, INPUT);
	pinMode(Button::OctaveChange, INPUT);

	pullUpDnControl(Button::C, PUD_DOWN);
	pullUpDnControl(Button::CS, PUD_DOWN);
	pullUpDnControl(Button::D, PUD_DOWN);
	pullUpDnControl(Button::DS, PUD_DOWN);
	pullUpDnControl(Button::E, PUD_DOWN);
	pullUpDnControl(Button::F, PUD_DOWN);
	pullUpDnControl(Button::FS, PUD_DOWN);
	pullUpDnControl(Button::G, PUD_DOWN);
	pullUpDnControl(Button::GS, PUD_DOWN);
	pullUpDnControl(Button::A, PUD_DOWN);
	pullUpDnControl(Button::AS, PUD_DOWN);
	pullUpDnControl(Button::B, PUD_DOWN);
	pullUpDnControl(Button::C_High, PUD_DOWN);
	pullUpDnControl(Button::InstrumentChange, PUD_DOWN);
	pullUpDnControl(Button::OctaveChange, PUD_DOWN);
}

void soundInitialization(void) {
	try {

		// Piano sounds
		if (!SoundBuffer::Piano::High::C.loadFromFile("Media/Piano/High/C.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::CS.loadFromFile("Media/Piano/High/CS.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::D.loadFromFile("Media/Piano/High/D.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::DS.loadFromFile("Media/Piano/High/DS.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::E.loadFromFile("Media/Piano/High/E.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::F.loadFromFile("Media/Piano/High/F.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::FS.loadFromFile("Media/Piano/High/FS.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::G.loadFromFile("Media/Piano/High/G.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::GS.loadFromFile("Media/Piano/High/GS.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::A.loadFromFile("Media/Piano/High/A.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::AS.loadFromFile("Media/Piano/High/AS.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::B.loadFromFile("Media/Piano/High/B.flac")) throw new exception();
		if (!SoundBuffer::Piano::High::C_High.loadFromFile("Media/Piano/High/C_High.flac")) throw new exception();

		if (!SoundBuffer::Piano::Medium::C.loadFromFile("Media/Piano/Medium/C.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::CS.loadFromFile("Media/Piano/Medium/CS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::D.loadFromFile("Media/Piano/Medium/D.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::DS.loadFromFile("Media/Piano/Medium/DS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::E.loadFromFile("Media/Piano/Medium/E.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::F.loadFromFile("Media/Piano/Medium/F.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::FS.loadFromFile("Media/Piano/Medium/FS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::G.loadFromFile("Media/Piano/Medium/G.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::GS.loadFromFile("Media/Piano/Medium/GS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::A.loadFromFile("Media/Piano/Medium/A.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::AS.loadFromFile("Media/Piano/Medium/AS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::B.loadFromFile("Media/Piano/Medium/B.flac")) throw new exception();
		if (!SoundBuffer::Piano::Medium::C_High.loadFromFile("Media/Piano/High/C.flac")) throw new exception();

		if (!SoundBuffer::Piano::Low::C.loadFromFile("Media/Piano/Low/C.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::CS.loadFromFile("Media/Piano/Low/CS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::D.loadFromFile("Media/Piano/Low/D.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::DS.loadFromFile("Media/Piano/Low/DS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::E.loadFromFile("Media/Piano/Low/E.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::F.loadFromFile("Media/Piano/Low/F.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::FS.loadFromFile("Media/Piano/Low/FS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::G.loadFromFile("Media/Piano/Low/G.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::GS.loadFromFile("Media/Piano/Low/GS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::A.loadFromFile("Media/Piano/Low/A.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::AS.loadFromFile("Media/Piano/Low/AS.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::B.loadFromFile("Media/Piano/Low/B.flac")) throw new exception();
		if (!SoundBuffer::Piano::Low::C_High.loadFromFile("Media/Piano/Medium/C.flac")) throw new exception();

		// Guitar sounds
		if (!SoundBuffer::Guitar::High::C.loadFromFile("Media/Guitar/High/C.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::CS.loadFromFile("Media/Guitar/High/CS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::D.loadFromFile("Media/Guitar/High/D.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::DS.loadFromFile("Media/Guitar/High/DS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::E.loadFromFile("Media/Guitar/High/E.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::F.loadFromFile("Media/Guitar/High/F.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::FS.loadFromFile("Media/Guitar/High/FS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::G.loadFromFile("Media/Guitar/High/G.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::GS.loadFromFile("Media/Guitar/High/GS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::A.loadFromFile("Media/Guitar/High/A.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::AS.loadFromFile("Media/Guitar/High/AS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::B.loadFromFile("Media/Guitar/High/B.flac")) throw new exception();
		if (!SoundBuffer::Guitar::High::C_High.loadFromFile("Media/Guitar/High/C_High.flac")) throw new exception();

		if (!SoundBuffer::Guitar::Medium::C.loadFromFile("Media/Guitar/Medium/C.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::CS.loadFromFile("Media/Guitar/Medium/CS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::D.loadFromFile("Media/Guitar/Medium/D.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::DS.loadFromFile("Media/Guitar/Medium/DS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::E.loadFromFile("Media/Guitar/Medium/E.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::F.loadFromFile("Media/Guitar/Medium/F.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::FS.loadFromFile("Media/Guitar/Medium/FS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::G.loadFromFile("Media/Guitar/Medium/G.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::GS.loadFromFile("Media/Guitar/Medium/GS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::A.loadFromFile("Media/Guitar/Medium/A.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::AS.loadFromFile("Media/Guitar/Medium/AS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::B.loadFromFile("Media/Guitar/Medium/B.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Medium::C_High.loadFromFile("Media/Guitar/High/C.flac")) throw new exception();

		if (!SoundBuffer::Guitar::Low::C.loadFromFile("Media/Guitar/Low/C.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::CS.loadFromFile("Media/Guitar/Low/CS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::D.loadFromFile("Media/Guitar/Low/D.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::DS.loadFromFile("Media/Guitar/Low/DS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::E.loadFromFile("Media/Guitar/Low/E.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::F.loadFromFile("Media/Guitar/Low/F.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::FS.loadFromFile("Media/Guitar/Low/FS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::G.loadFromFile("Media/Guitar/Low/G.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::GS.loadFromFile("Media/Guitar/Low/GS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::A.loadFromFile("Media/Guitar/Low/A.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::AS.loadFromFile("Media/Guitar/Low/AS.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::B.loadFromFile("Media/Guitar/Low/B.flac")) throw new exception();
		if (!SoundBuffer::Guitar::Low::C_High.loadFromFile("Media/Guitar/Medium/C.flac")) throw new exception();

		// Trumpet sounds
		if (!SoundBuffer::Trumpet::High::C.loadFromFile("Media/Trumpet/High/C.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::CS.loadFromFile("Media/Trumpet/High/CS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::D.loadFromFile("Media/Trumpet/High/D.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::DS.loadFromFile("Media/Trumpet/High/DS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::E.loadFromFile("Media/Trumpet/High/E.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::F.loadFromFile("Media/Trumpet/High/F.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::FS.loadFromFile("Media/Trumpet/High/FS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::G.loadFromFile("Media/Trumpet/High/G.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::GS.loadFromFile("Media/Trumpet/High/GS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::A.loadFromFile("Media/Trumpet/High/A.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::AS.loadFromFile("Media/Trumpet/High/AS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::B.loadFromFile("Media/Trumpet/High/B.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::High::C_High.loadFromFile("Media/Trumpet/High/C_High.flac")) throw new exception();

		if (!SoundBuffer::Trumpet::Medium::C.loadFromFile("Media/Trumpet/Medium/C.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::CS.loadFromFile("Media/Trumpet/Medium/CS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::D.loadFromFile("Media/Trumpet/Medium/D.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::DS.loadFromFile("Media/Trumpet/Medium/DS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::E.loadFromFile("Media/Trumpet/Medium/E.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::F.loadFromFile("Media/Trumpet/Medium/F.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::FS.loadFromFile("Media/Trumpet/Medium/FS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::G.loadFromFile("Media/Trumpet/Medium/G.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::GS.loadFromFile("Media/Trumpet/Medium/GS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::A.loadFromFile("Media/Trumpet/Medium/A.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::AS.loadFromFile("Media/Trumpet/Medium/AS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::B.loadFromFile("Media/Trumpet/Medium/B.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Medium::C_High.loadFromFile("Media/Trumpet/High/C.flac")) throw new exception();

		if (!SoundBuffer::Trumpet::Low::C.loadFromFile("Media/Trumpet/Low/C.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::CS.loadFromFile("Media/Trumpet/Low/CS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::D.loadFromFile("Media/Trumpet/Low/D.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::DS.loadFromFile("Media/Trumpet/Low/DS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::E.loadFromFile("Media/Trumpet/Low/E.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::F.loadFromFile("Media/Trumpet/Low/F.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::FS.loadFromFile("Media/Trumpet/Low/FS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::G.loadFromFile("Media/Trumpet/Low/G.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::GS.loadFromFile("Media/Trumpet/Low/GS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::A.loadFromFile("Media/Trumpet/Low/A.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::AS.loadFromFile("Media/Trumpet/Low/AS.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::B.loadFromFile("Media/Trumpet/Low/B.flac")) throw new exception();
		if (!SoundBuffer::Trumpet::Low::C_High.loadFromFile("Media/Trumpet/Medium/C.flac")) throw new exception();
	}
	catch (...) {
		cout << "A sound file failed to load. Terminating application..." << endl;
		exit(EXIT_FAILURE);
	}
}

void readNoteButtonInput(int pin, Button::Data::ButtonData & data) {
	if (data.pressed == false) {
		if (digitalRead(pin) == true) {
			data.soundVolume = 100;
			data.sound.setVolume(data.soundVolume);
			data.sound.play();
			
			data.pressed = true;
			data.dampSound = false;
		}
	}

	if (data.pressed == true) {
		if (digitalRead(pin) == false) {
			data.pressed = false;
			data.dampSound = true;
		}
	}

	if (data.dampSound) {
		data.sound.setVolume(data.soundVolume);
		
		if (data.soundVolume > SoundBuffer::dampingConstant) {
			data.soundVolume -= SoundBuffer::dampingConstant;
		}
		else {
			data.sound.stop();
			data.dampSound = false;
		}
	}
}

void instrumentChange(Instrument & currentInstrument) // Function to change instrument
{
   switch (currentInstrument)
   {
   case Piano :
      currentInstrument = Instrument::Guitar;
      break;
   case Guitar :
      currentInstrument = Instrument::Trumpet;
      break;
   case Trumpet :
      currentInstrument = Instrument::Piano;
      break;
   }

   soundChange(currentInstrument, currentOctave);
   displayChange(currentInstrument, currentOctave);
}

void octaveChange(Octave & currentOctave) // Function to change octave
{
   switch (currentOctave)
   {
   case Low:
      currentOctave = Octave::Medium;
      break;
   case Medium:
      currentOctave = Octave::High;
      break;
   case High:
      currentOctave = Octave::Low;
      break;
   }

   soundChange(currentInstrument, currentOctave);
   displayChange(currentInstrument, currentOctave);
}

void soundChange(Instrument currentInstrument, Octave currentOctave) {
	switch (currentInstrument) 
	{
	case Instrument::Piano:
		switch (currentOctave) 
		{
		case Octave::Low:
			Button::Data::C.sound.setBuffer(SoundBuffer::Piano::Low::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Piano::Low::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Piano::Low::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Piano::Low::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Piano::Low::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Piano::Low::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Piano::Low::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Piano::Low::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Piano::Low::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Piano::Low::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Piano::Low::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Piano::Low::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Piano::Medium::C);
			break;

		case Octave::Medium:
			Button::Data::C.sound.setBuffer(SoundBuffer::Piano::Medium::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Piano::Medium::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Piano::Medium::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Piano::Medium::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Piano::Medium::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Piano::Medium::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Piano::Medium::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Piano::Medium::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Piano::Medium::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Piano::Medium::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Piano::Medium::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Piano::Medium::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Piano::High::C);
			break;

		case Octave::High:
			Button::Data::C.sound.setBuffer(SoundBuffer::Piano::High::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Piano::High::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Piano::High::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Piano::High::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Piano::High::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Piano::High::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Piano::High::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Piano::High::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Piano::High::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Piano::High::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Piano::High::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Piano::High::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Piano::High::C_High);
			break;
		}

		break;

	case Instrument::Guitar:
		switch (currentOctave)
		{
		case Octave::Low:
			Button::Data::C.sound.setBuffer(SoundBuffer::Guitar::Low::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Guitar::Low::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Guitar::Low::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Guitar::Low::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Guitar::Low::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Guitar::Low::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Guitar::Low::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Guitar::Low::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Guitar::Low::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Guitar::Low::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Guitar::Low::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Guitar::Low::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Guitar::Medium::C);
			break;

		case Octave::Medium:
			Button::Data::C.sound.setBuffer(SoundBuffer::Guitar::Medium::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Guitar::Medium::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Guitar::Medium::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Guitar::Medium::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Guitar::Medium::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Guitar::Medium::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Guitar::Medium::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Guitar::Medium::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Guitar::Medium::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Guitar::Medium::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Guitar::Medium::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Guitar::Medium::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Guitar::High::C);
			break;
				
		case Octave::High:
			Button::Data::C.sound.setBuffer(SoundBuffer::Guitar::High::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Guitar::High::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Guitar::High::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Guitar::High::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Guitar::High::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Guitar::High::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Guitar::High::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Guitar::High::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Guitar::High::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Guitar::High::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Guitar::High::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Guitar::High::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Guitar::High::C_High);
			break;

		}

		break;

	case Instrument::Trumpet:
		switch (currentOctave)
		{
		case Octave::Low:
			Button::Data::C.sound.setBuffer(SoundBuffer::Trumpet::Low::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Trumpet::Low::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Trumpet::Low::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Trumpet::Low::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Trumpet::Low::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Trumpet::Low::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Trumpet::Low::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Trumpet::Low::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Trumpet::Low::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Trumpet::Low::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Trumpet::Low::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Trumpet::Low::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Trumpet::Medium::C);
			break;

		case Octave::Medium:
			Button::Data::C.sound.setBuffer(SoundBuffer::Trumpet::Medium::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Trumpet::Medium::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Trumpet::Medium::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Trumpet::Medium::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Trumpet::Medium::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Trumpet::Medium::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Trumpet::Medium::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Trumpet::Medium::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Trumpet::Medium::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Trumpet::Medium::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Trumpet::Medium::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Trumpet::Medium::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Trumpet::High::C);
			break;

		case Octave::High:
			Button::Data::C.sound.setBuffer(SoundBuffer::Trumpet::High::C);
			Button::Data::CS.sound.setBuffer(SoundBuffer::Trumpet::High::CS);
			Button::Data::D.sound.setBuffer(SoundBuffer::Trumpet::High::D);
			Button::Data::DS.sound.setBuffer(SoundBuffer::Trumpet::High::DS);
			Button::Data::E.sound.setBuffer(SoundBuffer::Trumpet::High::E);
			Button::Data::F.sound.setBuffer(SoundBuffer::Trumpet::High::F);
			Button::Data::FS.sound.setBuffer(SoundBuffer::Trumpet::High::FS);
			Button::Data::G.sound.setBuffer(SoundBuffer::Trumpet::High::G);
			Button::Data::GS.sound.setBuffer(SoundBuffer::Trumpet::High::GS);
			Button::Data::A.sound.setBuffer(SoundBuffer::Trumpet::High::A);
			Button::Data::AS.sound.setBuffer(SoundBuffer::Trumpet::High::AS);
			Button::Data::B.sound.setBuffer(SoundBuffer::Trumpet::High::B);
			Button::Data::C_High.sound.setBuffer(SoundBuffer::Trumpet::High::C_High);
			break;
		}

		break;
	}
}

void displayChange(Instrument currentInstrument, Octave currentOctave) // Function to change display values
{
    // Change instrument on display
    string instrument = "Inst: ";

    switch (currentInstrument)
    {
    case Piano : 
		instrument += "Piano";
        break;
    case Guitar :
		instrument += "Guitar";
        break;
    case Trumpet :
		instrument += "Trumpet";
        break;
    }

    // Change octave on display
    string octave = "Octa: ";

    switch (currentOctave)
    {
    case Low :
		octave += "Low";
        break;
    case Medium :
		octave += "Medium";
        break;
    case High :
		octave += "High";
        break;
    }

	lcdClear(lcdHandle);

	lcdPosition(lcdHandle, 0, 0);
	lcdPuts(lcdHandle, instrument.c_str());

    lcdPosition(lcdHandle, 0, 1);
    lcdPuts(lcdHandle, octave.c_str());
}
