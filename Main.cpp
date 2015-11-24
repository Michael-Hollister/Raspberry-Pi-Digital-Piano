#include <iostream>
#include <string>
#include <wiringPi.h>
#include <lcd.h>
#include <mcp23017.h>
#include <SFML/Audio.hpp>
#include "Main.h"

using namespace std;


// Hardware powers on start up

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
	wiringPiSetupSys();

	// --- Code snippet from http://wiringpi.com/examples/adafruit-rgb-lcd-plate-and-wiringpi/ 
	mcp23017Setup(AF_BASE, 0x20);
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


void displayChange(Instrument currentInstrument, Octave currentOctave) // Function to change display values
{
    // Change instrument on display
    string instrument = "Instrument: ";

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

    lcdPosition(lcdHandle, 0, 0); 
    lcdPuts(lcdHandle, instrument.c_str());

    // Change octave on display
    string octave = "Octave: ";

    switch (currentOctave)
    {
    case Low :
		octave =+ "Low";
        break;
    case Medium :
		octave =+ "Medium";
        break;
    case High :
		octave =+ "High";
        break;
    }

    lcdPosition(lcdHandle, 0, 1);
    lcdPuts(lcdHandle, octave.c_str());
}
