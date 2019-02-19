/*
This program is the first several notes of several songs from
The Legend of Zelda Ocarina of Time. Composer: Koji Kondo. 
It's designed to be played on the robots in Professor Walker's
Operating Systems and Concurencies course. This program will not 
run properly without the hardware (scribbler 2 robotics kit).
*/

#include "MyroC.h" // include the library for Scribbler commands
#include "scale-notes.h"  // header file for the scale notes provided by Professor Walker
#include "eSpeakPackage.h"  // library for espeak voice synthesizer

//functions for songs
void lullaby();
void storms();
void saria();
void time();
void godess();

int main() // main function calls the functions for all of the songs. They all play in the sequence in which they're called.
{
  eSpeakConnect(); //connects to eSpeak
  eSpeakTalk ("This program plays several songs from the Legend of Zelda composed by Koji Kondo.");
  rConnect("/dev/rfcomm0"); // connect to Scribbler
    // All songs are composed by Koji Kondo

    // During the test run, the songs lasted aproximately 39.5 seconds not including the espeak messages.
    // To test how long the songs play, I timed each of them with a stop watch
    
  lullaby(); // Zelda's Lullaby		- lasts for approximately 10 seconds
  storms();  // Song of Storms		- lasts for approximately 4.5 seconds
  saria();  // Saria's Song		- lasts for approximately 10 seconds
  time();  // Song of Time		- lasts for approximately 5 seconds
  godess();  // Ballad of the Goddess	- lasts for approximately 10 seconds

  eSpeakTalk ("Program done. Thank you for listening to the zelda soundtrack composed by Koji Kondo. goodbye");
  eSpeakDisconnect(); // disconnect from eSpeak
  rDisconnect(); // disconnect from Scribbler
  return 0; // return, indicating no errors have occurred
} // main

void lullaby() {
// Zelda's Lullaby from The Legend of Zelda Ocarina of Time. Composer: Koji Kondo.
  eSpeakTalk ("Zelda's Lullaby composed by Koji Kondo");

  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchA5);

  rBeep(0.125,pitchG5);
  rBeep(0.125,pitchA5);
  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.75,pitchA5);

  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchA6);
  rBeep(0.25,pitchG6);
  rBeep(0.5,pitchD6);
  rBeep(0.125,pitchC6);
  rBeep(0.125,pitchB5);
  rBeep(0.5,pitchA5);

  rBeep(0.125,pitchG5);
  rBeep(0.125,pitchA5);
  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.75,pitchA5);

  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchA5);
return;
}

void storms() {
// Song of Storms from The Legend of Zelda Ocarina of Time. Composer: Koji Kondo.
  eSpeakTalk ("Song of Storms composed by Koji Kondo");
 
  rBeep(0.125,pitchD5);
  rBeep(0.125,pitchF5);
  rBeep(0.5,pitchD6);

  rBeep(0.125,pitchD5);
  rBeep(0.125,pitchF5);
  rBeep(0.5,pitchD6);

  rBeep(0.1,pitchE6);
  rBeep(0.25,pitchF6);
  rBeep(0.25,pitchE6);
  rBeep(0.25,pitchF6);
  rBeep(0.25,pitchE6);
  rBeep(0.25,pitchC6);
  rBeep(0.25,pitchA5);
return;
}

void saria() // Saria's Song from the Legend of Zelda Ocarina of Time
{
  eSpeakTalk ("Saria's song composed by Koji Kondo");

  rBeep(0.125,pitchF5); // beep for 1 second at a frequency of 698 Hz.
  rBeep(0.125,pitchA5);
  rBeep(0.25,pitchB5);
 
  rBeep(0.125,pitchF5); 
  rBeep(0.125,pitchA5); 
  rBeep(0.25,pitchB5);  

  rBeep(0.125,pitchF5); 
  rBeep(0.125,pitchA5); 
  rBeep(0.125,pitchB5); 
  rBeep(0.125,pitchE6); 
  rBeep(0.25,pitchD6);
  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchC6);
  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchG5);
  rBeep(0.75,pitchE5);

  rBeep(0.125,pitchD5);
  rBeep(0.125,pitchE5);
  rBeep(0.125,pitchG5);
  rBeep(0.75,pitchE5);

  rBeep(0.125,pitchF5);
  rBeep(0.125,pitchA5);
  rBeep(0.25,pitchB5);

  rBeep(0.125,pitchF5);
  rBeep(0.125,pitchA5);
  rBeep(0.25,pitchB5);

  rBeep(0.125,pitchF5);
  rBeep(0.125,pitchA5);
  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchE6);
  rBeep(0.25,pitchD6);
  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchC6);
  rBeep(0.125,pitchE6);
  rBeep(0.125,pitchB5);
  rBeep(0.75,pitchG5);

  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchG5);
  rBeep(0.125,pitchD5);
  rBeep(0.75,pitchE5);
  return;	
}

void time() // Song of Time from the Legend of Zelda Ocarina of Time
{
  eSpeakTalk ("Song of Time composed by Koji Kondo");

  rBeep(0.25,pitchA5);
  rBeep(0.5,pitchD5);
  rBeep(0.25,pitchF5);
  rBeep(0.25,pitchA5);
  rBeep(0.5,pitchD5);

  rBeep(0.25,pitchF5);
  rBeep(0.125,pitchA5);
  rBeep(0.125,pitchC6);
  rBeep(0.25,pitchB5);
  rBeep(0.25,pitchG5);
  rBeep(0.125,pitchF5);
  rBeep(0.125,pitchG5);
  rBeep(0.25,pitchA5);
  rBeep(0.25,pitchD5);
  rBeep(0.125,pitchA5);
  rBeep(0.25,pitchC5);
  rBeep(0.125,pitchE5);
  rBeep(0.5,pitchD5);
  return;	
}

void godess() {
// Ballad of the Goddess from The Legend of Zelda Skyward Sword. Composer: Koji Kondo.
  eSpeakTalk ("Ballad of the Goddess composed by Koji Kondo");
  
  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchA5);

  rBeep(0.75,pitchA5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchB5);
  rBeep(0.125,pitchA5);
  rBeep(0.125,pitchG5);

  rBeep(0.5,pitchA5);
  rBeep(0.125,pitchB5);
  rBeep(0.125,pitchC6);
  rBeep(0.5,pitchD6);
  rBeep(0.25,pitchG6);
  rBeep(0.5,pitchA6);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchB5);

  rBeep(0.75,pitchA5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchB5);
  rBeep(0.125,pitchA5);
  rBeep(0.125,pitchG5);

  rBeep(0.5,pitchB5);
  rBeep(0.25,pitchD6);
  rBeep(0.5,pitchA5);
return;
}
