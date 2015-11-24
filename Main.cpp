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
   initialization();

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

void initialization()
{
   //Initialization code

   // Default settings for piano
   instrumentChange("piano", currentInstrument);
   octaveChange("piano", "medium", currentOctave);

   // Default settings for display
   displayChange(currentInstrument, currentOctave);
}

void instrumentChange(string instrument, string &newInstrument) // Function for changing instruments
{
   if (instrument == "piano")
   {
      // Switch all button sound files to medium piano

      newInstrument = "piano";
   }
   else if (instrument == "guitar")
   {
      // Switch all button sound files to medium guitar

      newInstrument = "guitar";
   }
   else
   {
      // Switch all button sound files to medium trumpet

      newInstrument = "trumpet"
   }
}

void octaveChange(string instrument, string octave, string &newOctave) // Function for changing octaves
{
   if (instrument == "piano")
   {
      if (octave == "low")
      {
         // Switch all button sound files to low piano

         newOctave = "low";
      }
      else if (octave == "medium")
      {
         // Switch all button sound files to medium piano

         newOctave = "medium";
      }
      else
      {
         // Switch all button sound files to high piano

         newOctave = "high";
      }
   }
   else if (instrument == "guitar")
   {
      if (octave == "low")
      {
         // Switch all button sound files to low guitar

         newOctave = "low";
      }
      else if (octave == "medium")
      {
         // Switch all button sound files to medium guitar

         newOctave = "medium";
      }
      else
      {
         // Switch all button sound files to high guitar

         newOctave = "high";
      }
   }
   else
   {
      if (octave == "low")
      {
         // Switch all button sound files to low trumpet

         newOctave = "low";
      }
      else if (octave == "medium")
      {
         // Switch all button sound files to medium trumpet

         newOctave = "medium";
      }
      else
      {
         // Switch all button sound files to high trumpet

         newOctave = "high";
      }
   }

   void displayChange(string instrument, string octave)
   {
      // Displays instrument and octave
      cout << "Instrument: " << instrument << endl;
      cout << "Octave: " << octave;
   }
}