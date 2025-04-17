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

// Declaration for score sensor (laser gates) identification
bool goalSensors[] = {0, 0, 0, 0}; 
const int goalPins[] = {A1, A2, A3, A4}; // Arranged in order of difficulty
int numGoals = 4; 
bool activeGoal = 0;
int previousGoals[] = {0, 0, 0, 0};

// Declaration of score tracking variables
int playerScore = 0;
int scoringStreak = 0; // Keeps track of the number of recent goals, e.g. a combo tracker
int comboTimeLimit = 5000; // The upper limit on how long a combo can be sustained without a new goal. Modified by the difficulty of each goal.

// Declaration for sound variables
#include "pitches.h"
const int speakerPin = 8;

int note = NOTE_D4;
bool activeNote = 0;

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

// Declaration of reset/lives variables
const int resetPin = 7;
const int holePin = A6;
int lives = 3;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // Initialize laser gate pins as inputs
  for (int i = 0; i < numGoals; i++) {
    pinMode(goalPins[i], INPUT);
  }
}

void loop() {
  // If any goal sensors are tripped, provide the user with audiovisual feedback (LEDs and piezo buzzer) while incrementing the player's score
  
  currentMillis = millis(); // Store the current time to reference with "last activation" times

  // Checks if any laser gates have been tripped and stores the identity of any activated gates
  for (int i = 0; i < numGoals; i++) {
    goalSensors[i] = analogRead(goalPins[i]);

    if (goalSensors[i] < 1000) {
      previousGoals[i] = currentMillis;
      int timeSinceGoal = currentMillis - previousGoal;
      
      // Resets scoring streak 
      if (timeSinceGoal < 200) {} // Prevents one goal from being counted twice
        
      else if (timeSinceGoal > comboTimeLimit) { // If the combo has expired, reset combo tracking variables and start a new combo
        scoringStreak = 1;
        comboTimeLimit = 5000;
        onScore(i);
      }
      else { // Scoring a goal during an active combo increases the combo and extends the time limit
        scoringStreak += 1;
        comboTimeLimit += (250 + (i * 500)); // Time extension is increased based on goal difficulty
        onScore(i);
      }
    }
  }

  if (analogRead(holePin) < 1000) {
    lives--;
    if (lives <= 0)
      reset();
  }

  // When the button is pressed, reset and trigger the operation of the LED and speaker  

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

int onScore(int goalID) {
  // Resets and enables the operation of the speaker and LED
  activeLED = 1;
  activeNote = 1;
  numBlinks = 0;
  previousGoal = currentMillis;
  previousMillisNote = currentMillis;

  switch (goalID) {
    case 0:
      playerScore += 50;
      break;
    case 1:
      playerScore += 100;
      break;
    case 2:
      playerScore += 200;
      break;
    case 3:
      playerScore += 250;
      break;
  }
  
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

void reset() {
  // Reset the player's score and tracking variables to their starting values.
  scoringStreak = 0;
  previousGoal = 0;
  previousMillisLED = 0;
  previousMillisNote = 0;

  playerScore = 0;
  lives = 3;

  // Disable AV systems
  noTone(speakerPin);
  ledState = LOW;
  digitalWrite(ledPin, ledState);

}
