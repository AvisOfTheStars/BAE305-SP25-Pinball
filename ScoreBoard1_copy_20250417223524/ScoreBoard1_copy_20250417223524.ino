#include <LiquidCrystal.h>
#include "pitches.h"

// LCD setup: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Scoring and sensor system
const int goalPins[] = { A1 };  //, A2, A3, A4};
const int numGoals = 0;         //4;
int playerScore = 0;
int lastScore = 0;
int scoringStreak = 0;
int comboTimeLimit = 5000;
unsigned long previousGoal = 0;

int sensorLimit = 0;

int goalSensors[] = { 0, 0, 0, 0 };

// Lives
int lives = 3;
const int holePin = A5;

// Audio-visual feedback
const int speakerPin = 7;
const int ledPin = 6;
int note = NOTE_D4;
bool activeNote = false;
bool activeLED = false;
int ledState = LOW;
int numBlinks = 0;
int maxBlinks = 3;
int blinkSpeed = 175;

// Timing
unsigned long currentMillis = 0;
unsigned long previousMillisNote = 0;
unsigned long previousMillisLED = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  for (int i = 0; i < numGoals; i++) {
    pinMode(goalPins[i], INPUT);
  }
  //pinMode(holePin, INPUT);

  updateDisplay(0);

  Serial.begin(9600);
  calibrate();
}

void loop() {
  currentMillis = millis();

  Serial.println(analogRead(holePin));

  // Check for goal hits
  for (int i = 0; i < numGoals; i++) {
    //goalSensors[i] = (analogRead(goalPins[i]) < 1000);

    //if ((abs(analogRead(goalPins[i]) - sensorLimit) > 125)) {
    if (analogRead(goalPins[i]) < 920) {
      unsigned long timeSinceGoal = currentMillis - previousGoal;

      if (timeSinceGoal > 200) {
        if (timeSinceGoal > comboTimeLimit) {
          scoringStreak = 1;
          comboTimeLimit = 5000;
        } else {
          scoringStreak++;
          comboTimeLimit += (250 + (i * 500));
        }

        lastScore = getScoreForGoal(i);
        playerScore += lastScore;
        onScore(i);
        updateDisplay(lastScore);
        previousGoal = currentMillis;
      }
    }
  }

  // Life loss detection
  if (analogRead(holePin) < 980) {
    lives--;
    if (lives <= 0) {
      resetGame();
    } else {
      updateDisplay(0);
    }
    delay(500);  // debounce delay
  }


  // AV updates
  if (activeLED) {
    ledBlink();
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (activeNote) {
    playNote();
  } else {
    noTone(speakerPin);
  }
}

// --- Scoring Feedback Logic ---
void onScore(int goalID) {
  activeLED = true;
  activeNote = true;
  numBlinks = 0;
  previousMillisNote = currentMillis;

  switch (scoringStreak) {
    case 1:
      maxBlinks = 3;
      blinkSpeed = 175;
      note = NOTE_D4;
      break;
    case 2:
      maxBlinks = 4;
      blinkSpeed = 150;
      note = NOTE_E4;
      break;
    case 3:
      maxBlinks = 5;
      blinkSpeed = 130;
      note = NOTE_FS4;
      break;
    case 4:
      maxBlinks = 6;
      blinkSpeed = 110;
      note = NOTE_A4;
      break;
    default:
      maxBlinks = 7;
      note = NOTE_D5;
      break;
  }
}

int getScoreForGoal(int id) {
  switch (id) {
    case 0: return 50;
    case 1: return 100;
    case 2: return 200;
    case 3: return 250;
    default: return 0;
  }
}

// --- LCD Display ---
void updateDisplay(int recentScore) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("+" + String(recentScore));
  lcd.print(" Tot:" + String(playerScore));

  lcd.setCursor(0, 1);
  lcd.print("Lives: " + String(lives));
}

// --- LED Feedback ---
void ledBlink() {
  if (numBlinks >= maxBlinks) {
    activeLED = false;
    ledState = LOW;
    digitalWrite(ledPin, LOW);
    return;
  }

  if (currentMillis - previousMillisLED >= blinkSpeed) {
    previousMillisLED = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

    if (ledState == LOW) {
      numBlinks++;
    }
  }
}

// --- Sound Feedback ---
void playNote() {
  if (currentMillis - previousMillisNote <= 800) {
    tone(speakerPin, note);
  } else {
    activeNote = false;
    noTone(speakerPin);
  }
}

// --- Reset Function ---
void resetGame() {
  playerScore = 0;
  lastScore = 0;
  lives = 3;
  scoringStreak = 0;
  comboTimeLimit = 5000;
  previousGoal = 0;

  activeLED = false;
  activeNote = false;
  digitalWrite(ledPin, LOW);
  noTone(speakerPin);

  updateDisplay(0);
}

void calibrate() {
  int calibTotal = 0;
  for (int i = 0; i < 5000; i++) {
    calibTotal += i;
  }
  sensorLimit = (calibTotal / 5000);
}
