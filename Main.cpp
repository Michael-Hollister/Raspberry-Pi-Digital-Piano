#include <iostream>
#include <string>
#include <wiringPi.h>
#include <lcd.h>
#include <mcp23017.h>
using namespace std;

void instrumentChange(string, &string);
void octaveChange(string, string, &string);
void displayChange(string, string);
void initialization();

// Hardware powers on start up

int main()
{

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
   //}

   return 0; // Exit program
}

   void displayChange(Instrument currentInstrument, Octave currentOctave) // Function to change display values
   {
      // Change instrument on display
      string = Instrument;

      switch (currentInstrument)
      {
      case Piano : 
         Instrument = "Piano";
         break;
      case Guitar :
         Instrument = "Guitar";
         break;
      case Trumpet :
         Instrument = "Trumpet";
         break;
      }

      lcdPosition(lcdHandle, 0, 0); 
      lcdPuts(lcdHandle, "Instrument: " + Instrument);

      // Change octave on display
      string = Octave;

      switch (currentOctave)
      {
      case Low :
         Octave = "Low";
         break;
      case Medium :
         Octave = "Medium";
         break;
      case High :
         Octave = "High";
         break;
      }

      lcdPosition(lcdHandle, 0, 1);
      lcdPuts(lcdHandle, "Octave: " + Octave);
   }
}