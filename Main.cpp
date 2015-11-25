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

	system("sleep 10");

	/*
   string currentInstrument;
   string currentOctave;

   bool instrumentButton;
   bool octaveButton;

   while (1) // Infinite loop
   {
      while (instrumentButton == 1) // While the instrument button is pressed...
      {
         if (currentInstrument == "piano")
         {
            instrumentChange("guitar", currentInstrument);
            displayChange(currentInstrument, currentOctave);
         }
         else if (currentInstrument == "guitar")
         {
            instrumentChange("trumpet", currentInstrument);
            displayChange(currentInstrument, currentOctave);
         }
         else
         {
            instrumentChange("piano", currentInstrument);
            displayChange(currentInstrument, currentOctave);
         }
      }

      while (octaveButton == 1) // While the octave button is pressed...
      {
         if (currentOctave == "medium")
         {
            octaveChange("high", currentOctave);
            displayChange(currentInstrument, currentOctave);
         }
         else if (currentOctave == "high")
         {
            octaveChange("low", currentOctave);
            displayChange(currentInstrument, currentOctave);
         }
         else
         {
            octaveChange("medium", currentOctave);
            displayChange(currentInstrument, currentOctave);
         }
      }
   //}*/

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



	// Defaults setup
	currentInstrument = Instrument::Piano;
	currentOctave = Octave::Medium;

	displayChange(currentInstrument, currentOctave);
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

   displayChange(currentInstrument, currentOctave);
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
