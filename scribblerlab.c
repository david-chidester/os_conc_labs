 /***********************************************************************
 * Name(s)  (David Chidester)                                          *
 * Box(s): D155                                                        *
 * Assignment name (Lab 1: Song Program Project)                       *
 *      (25% off if name/number does not match assignment)             *
 * Assignment for: Operating Systems and Concurency                    *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used: None                                 *
 *     [include textbook(s), CS 451 labs or readings;                  *
 *       complete citations for Web or other written sources           *
 *      write "none" if no sources used] The Legend of Zelda Ocarina   *
 *      of Time, Developed and published by Nintendo in 1998 composed  *
 *      by Koji Kondo.                                                 *
 *      The Legend of Zelda Skyward Sword Developed and published by   *
 *      Nintendo in 2011 composed by Koji Kondo.                       *
 *   Help obtained None                                                *
 *     [indicate names of instructor, class mentors                    *
 *      or evening tutors, consulted according to class policy;        *
 *      write "none" if none of these sources used] None               *
 *     ["none" or the instructor's name for Supplemental Problems      *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature:                                                        *
 ***********************************************************************/

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
