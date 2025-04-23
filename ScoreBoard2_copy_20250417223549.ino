/*
  Final Pinball Scoring System with LCD + Audio/Visual Feedback
  Compatible with Arduino UNO and Arduino IDE
*/

#include <LiquidCrystal.h>
#include "pitches.h"  // Make sure this file is included in your sketch folder

// LCD setup (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Pin setup
const int speakerPin = 7;
const int ledPin = 6;
const int resetPin = 5;
const int holePin = A6;
const int goalPins[] = {A1, A2, A3, A4};
int numGoals = 4;

// State vars
bool goalSensors[] = {0, 0, 0, 0}; 
int previousGoals[] = {0, 0, 0, 0};

int playerScore = 0;
int scoringStreak = 0;
int lives = 3;
unsigned long comboTimeLimit = 5000;
unsigned long previousGoal = 0;

// LED/sound control
bool activeLED = 0;
bool activeNote = 0;
int ledState = LOW;
int blinkSpeed = 175;
int numBlinks = 0;
int maxBlinks = 3;
int note = NOTE_D4;

// Timing
unsigned long currentMillis = 0;
unsigned long previousMillisNote = 0;
unsigned long previousMillisLED = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(resetPin, INPUT);
  pinMode(holePin, INPUT);

  for (int i = 0; i < numGoals; i++) {
    pinMode(goalPins[i], INPUT);
  }

  lcd.begin(16, 2);
  lcd.print("Total: 0 Lives: 3");
}

void loop() {
  currentMillis = millis();

  for (int i = 0; i < numGoals; i++) {
    goalSensors[i] = analogRead(goalPins[i]) < 1000;

    if (goalSensors[i]) {
      int timeSinceGoal = currentMillis - previousGoal;
      if (timeSinceGoal > 200) {
        if (timeSinceGoal > comboTimeLimit) {
          scoringStreak = 1;
          comboTimeLimit = 5000;
        } else {
          scoringStreak++;
          comboTimeLimit += (250 + (i * 500));
        }
        onScore(i);
      }
    }
  }

  if (analogRead(holePin) < 1000) {
    lives--;
    if (lives <= 0) reset();
  }

  if (activeLED) ledBlink();
  else digitalWrite(ledPin, LOW);

  if (activeNote) playNote();
  else noTone(speakerPin);
}

void onScore(int goalID) {
  activeLED = true;
  activeNote = true;
  numBlinks = 0;
  previousGoal = currentMillis;
  previousMillisNote = currentMillis;

  int scoreAdd = 0;
  switch (goalID) {
    case 0: scoreAdd = 50; break;
    case 1: scoreAdd = 100; break;
    case 2: scoreAdd = 200; break;
    case 3: scoreAdd = 250; break;
  }
  playerScore += scoreAdd;

  // AV feedback
  switch (scoringStreak) {
    case 1: maxBlinks = 3; blinkSpeed = 175; note = NOTE_D4; break;
    case 2: maxBlinks = 4; blinkSpeed = 155; note = NOTE_E4; break;
    case 3: maxBlinks = 5; blinkSpeed = 135; note = NOTE_FS4; break;
    case 4: maxBlinks = 6; blinkSpeed = 115; note = NOTE_A4; break;
    default: maxBlinks = 7; blinkSpeed = 100; note = NOTE_D5; break;
  }

  showScore(scoreAdd);
}

void showScore(int added) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("+" + String(added) + " pts!");

  if (scoringStreak > 1) {
    lcd.setCursor(0, 1);
    lcd.print("COMBO x" + String(scoringStreak));
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Lives: " + String(lives));
  }

  delay(1200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total: " + String(playerScore));
  lcd.setCursor(0, 1);
  lcd.print("Lives: " + String(lives));
}

void ledBlink() {
  if (numBlinks >= maxBlinks) {
    activeLED = false;
    digitalWrite(ledPin, LOW);
    return;
  }

  if (currentMillis - previousMillisLED >= blinkSpeed) {
    previousMillisLED = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    if (ledState == LOW) numBlinks++;
  }
}

void playNote() {
  if (currentMillis - previousMillisNote <= 800) {
    tone(speakerPin, note);
  } else {
    activeNote = false;
    noTone(speakerPin);
  }
}

void reset() {
  playerScore = 0;
  lives = 3;
  scoringStreak = 0;
  activeLED = false;
  activeNote = false;
  digitalWrite(ledPin, LOW);
  noTone(speakerPin);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(0, 1);
  lcd.print("Resetting...");
  delay(2000);

  lcd.clear();
  lcd.print("Total: 0 Lives: 3");
}
