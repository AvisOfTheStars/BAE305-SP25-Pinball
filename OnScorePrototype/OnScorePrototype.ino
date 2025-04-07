/*
  OnScorePrototype
  Modified from Arduino IDE example 02.ToneMelody, 02.Button, and 02.BlinkWithoutDelay

  Plays a melody and blinks an LED when a button is pushed, progressing through tones when pressed in succession. 
  A prototype of the onScore function for the mini pinball-like machine


  circuit:
  - 8 ohm speaker on digital pin 8
  - LED attached from pin 13 to ground through 330 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  created 21 Jan 2010
  by Tom Igoe
  modified 06 Apr 2025
  by Avis Chen
*/

// Declaration for sound variables
#include "pitches.h"
const int speakerPin = 8;

int note = NOTE_D4;
bool activeNote = 0;

// Declaration for button variables
const int buttonPin = 2;
int buttonState = 0;

// Declaration for LED variables
const int ledPin = 13;
int ledState = LOW;
int blinkSpeed = 175;  // interval at which to blink LEDs after scoring (milliseconds)
int numBlinks = 0; // Blink tracker 
int maxBlinks = 3;
bool activeLED = 0;


// Declaration for uninteruptable time variables
unsigned long currentMillis = 0; // Stores the current time (duration the program has been running)
unsigned long previousMillisNote = 0;  // will store last time the speaker was updated
unsigned long previousMillisLED = 0;  // will store last time LED was updated
unsigned long previousGoal = 0; // Stores the last time a goal was scored
int scoringStreak = 0; // Keeps track of the number of recent goals, e.g. a combo tracker


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // If the button is pressed blink the LED and play a melody
  currentMillis = millis(); // Store the current time

  buttonState = digitalRead(buttonPin); // Check if the button is pressed

  // When the button is pressed, reset and trigger the operation of the LED and speaker
  if (buttonState == HIGH) {
    int timeSinceGoal = currentMillis - previousGoal;
    // Resets scoring streak 
    if (timeSinceGoal < 200) {}
      
    else if (timeSinceGoal > 5000) {
      scoringStreak = 1;
      onScore();
    }
    else {
      scoringStreak += 1;
      onScore();
    }
  }
  

  // The following if cases should be redundant but the circuit behaves weirdly without them
  // If the LED has not completed its blinks, continue to blink
  if (activeLED) {
    ledBlink();
  }
  else { // Otherwise, turn it off
    digitalWrite(ledPin, LOW);
  }

    // If the note is not done playing, continue to play it
  if (activeNote) {
    playNote();
  }
  else { // Otherwise, turn it off
    noTone(speakerPin);
  } 

}

void onScore() {
  // Resets and enables the operation of the speaker and LED
  activeLED = 1;
  activeNote = 1;
  numBlinks = 0;
  previousGoal = currentMillis;
  previousMillisNote = currentMillis;

  
  // Depending on how many recent goals have happened, reward the player with progressively more ceremonious lights and noises
  // The note progression is custom, I labbed it out on piano and ported it over to the code  
  switch (scoringStreak) {
    case 1:
      maxBlinks = 3;
      blinkSpeed = 175;
      note = NOTE_D4;
      //playerScore += 100;
      break;
    case 2:
      maxBlinks = 4;
      blinkSpeed -= 20; // Blink faster with each goal, up to a point
      note = NOTE_E4;
      //playerScore += 125;
      break;
    case 3:
      maxBlinks = 5;
      blinkSpeed -= 20;
      note = NOTE_FS4;
      //playerScore += 150;
      break;
    case 4:
      maxBlinks = 6;
      blinkSpeed -= 20;
      note = NOTE_A4;
      //playerScore += 200;
      break;
    default: // Combo caps out at 5 
      maxBlinks = 7;
      note = NOTE_D5;
      //playerScore += 250;
      break;
  }

}

int ledBlink() {
  int timeSinceBlink = currentMillis - previousMillisLED; 
  // If a long time has passed, deactivate LEDs
  if (numBlinks >= maxBlinks) {
    activeLED = 0;
    ledState = LOW;
  }
  
  // If the button has been recently pushed, allow the LED to blink and play the melody
  if (activeLED) {
    //Blink the LED according to the LED speed (higher combo = faster blinks)
    if (timeSinceBlink >= blinkSpeed) {
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


int playNote() {
  int timeSinceNote = currentMillis - previousMillisNote; 

  // Play a note every time a goal is scored
  if (timeSinceNote <= 800) {
    tone(speakerPin, note);
  }
  else { // After the note is done being played, deactivate the speaker
    activeNote = 0;
    noTone(speakerPin);
  }  
}
