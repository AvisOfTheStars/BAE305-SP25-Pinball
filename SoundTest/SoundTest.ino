/*
  SoundTest
  Modified from Arduino IDE example 02.ToneMelody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  by Tom Igoe
  modified 19 Mar 2025
  by Avis Chen

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_FS5, NOTE_DS5, NOTE_A4, NOTE_GS4, NOTE_E5, NOTE_GS5, NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take 1.75 seconds divided by the note type.
    // 1.75 seconds feels right for the BPM of this motif
    //e.g. quarter note = 1750 / 4, eighth note = 1750/8, etc.
    int noteDuration = 1750 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * .70;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
