/*
  SoundTest
  Modified from Arduino IDE example 02.ToneMelody and 02.Button

  Plays a melody and blinks an LED when a button is pushed 

  circuit:
  - 8 ohm speaker on digital pin 8
  - LED attached from pin 13 to ground through 330 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  created 21 Jan 2010
  by Tom Igoe
  modified 19 Mar 2025
  by Avis Chen

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

// Declaration for sound variables
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_FS5, NOTE_DS5, NOTE_A4, NOTE_GS4, NOTE_E5, NOTE_GS5, NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 4
};

// Declaration for button variables
const int buttonPin = 2;
int buttonState = 0;

// Declaration for LED variables
const int ledPin = 13;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    playMelody();
  } 
  
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

void playMelody() {
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


