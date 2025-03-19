/*
  SoundTest
  Modified from Arduino IDE example 02.ToneMelody, 02.Button, and 02.BlinkWithoutDelay

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
*/

// Declaration for sound variables
#include "pitches.h"
const int speakerPin = 8;

const int numNotes = 8;
// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_FS5, NOTE_DS5, NOTE_A4, NOTE_GS4, NOTE_E5, NOTE_GS5, NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 4
};

int currentNote = 0;
int noteTimings[numNotes];

// Declaration for button variables
const int buttonPin = 2;
int buttonState = 0;
bool buttonRecentLED = 0;
bool buttonRecentSpeaker = 0;


// Declaration for LED variables
const int ledPin = 13;
int ledState = LOW;
const int intervalLED = 175;  // interval at which to blink LEDs after scoring (milliseconds)
int numBlinks = 0; // Blink tracker 

// Declaration for uninteruptable time variables
unsigned long currentMillis = 0; // Stores the current time (duration the program has been running)
unsigned long previousMillisNote = 0;  // will store last time the speaker was updated
unsigned long previousMillisLED = 0;  // will store last time LED was updated

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // Converts note lengths to millisecond basis
  for (int note; note < numNotes; note++) {
    noteTimings[note] = 1250 / noteDurations[note];
  }
}

void loop() {
  // If the button is pressed blink the LED and play a melody
  currentMillis = millis(); // Store the current time

  buttonState = digitalRead(buttonPin); // Check if the button is pressed

  // When the button is pressed, reset and trigger the operation of the LED and speaker
  if (buttonState == HIGH) {
    buttonRecentLED = 1;
    buttonRecentSpeaker = 1;
    numBlinks = 0;
    currentNote = 0;
  }
  
  // If the LED has not completed its blinks, continue to blink
  if (buttonRecentLED) {
    ledBlink();
  }
  else { // Otherwise, turn it off
    digitalWrite(ledPin, LOW);
  }

  // Likewise for the speaker and its melody
  if (buttonRecentSpeaker) {
    playMelody();
  }
  else {
      noTone(speakerPin);
  }


}

void ledBlink() {
  int timeSinceBlink = currentMillis - previousMillisLED; 
  // If a long time has passed, deactivate LEDs
  if (numBlinks >= 5) {
    buttonRecentLED = 0;
    ledState = LOW;
  }
  
  // If the button has been recently pushed, allow the LED to blink and play the melody
  if (buttonRecentLED) {
    //Blink the LED according to the LED interval
    if (timeSinceBlink >= intervalLED) {
      previousMillisLED = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      }
      else {
        ledState = LOW;
        numBlinks++;
      }
    }
  }

  digitalWrite(ledPin, ledState);

}

void playMelody() {
  int timeSinceNote = currentMillis - previousMillisNote; 
  
  // If all notes have been played, deactivate the speaker
  if (currentNote >= numNotes) {
    buttonRecentSpeaker = 0;
    noTone(speakerPin);
  }

  // For each note in the melody, play the corresponding note for the right duration
  if (timeSinceNote <= noteTimings[currentNote]) {
    tone(speakerPin, melody[currentNote]);
  }
  else { // After a note is done being played, iterate to the next note
    previousMillisNote = currentMillis;
    currentNote++;
    noTone(speakerPin);
  }  
}


