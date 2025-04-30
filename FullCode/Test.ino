#include <LiquidCrystal.h>

// LCD wiring: RS=D12, E=D11, D4=D10, D5=D9, D6=D8, D7=D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Pin Assignments
const int leftFlipperPin = 2;
const int rightFlipperPin = 3;
const int leftButtonPin = 4;
const int rightButtonPin = 5;
const int resetButtonPin = 6;

// Scoring Sensors
const int scorePins[] = {A1, A2, A3, A4};
const int numScorePins = sizeof(scorePins) / sizeof(scorePins[0]);
const int scoreThresholds[] = {400, 800, 500, 800}; // Individual thresholds

// Game Over Sensor
const int gameOverSensorPin = A5;

// Game Logic
int score = 0;
bool gameOver = false;
unsigned long lastBounceTime = 0;
const int debounceDelay = 200;

void setup() {
  Serial.begin(9600);

  // LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Pinball Machine");
  lcd.setCursor(0, 1);
  lcd.print("Score: 0");

  // Pins
  pinMode(leftFlipperPin, OUTPUT);
  pinMode(rightFlipperPin, OUTPUT);
  digitalWrite(leftFlipperPin, HIGH);
  digitalWrite(rightFlipperPin, HIGH);

  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);

  // No pullup needed for analog read
  pinMode(gameOverSensorPin, INPUT);
}

void loop() {
  if (!gameOver) {
    handleScoring();
    handleFlippers();
    checkGameOverSensor();
  } else {
    handleReset();
  }
}

void handleScoring() {
  for (int i = 0; i < numScorePins; i++) {
    int sensorValue = analogRead(scorePins[i]);
    Serial.print("A");
    Serial.print(i + 1);
    Serial.print(" value: ");
    Serial.println(sensorValue);

    if (sensorValue < scoreThresholds[i] && (millis() - lastBounceTime > debounceDelay)) {
      score += 10;
      lastBounceTime = millis();
      updateDisplay();
      Serial.print("Sensor A");
      Serial.print(i + 1);
      Serial.println(" triggered and scored");
    }
  }
}

void handleFlippers() {
  digitalWrite(leftFlipperPin, digitalRead(leftButtonPin) == LOW ? LOW : HIGH);
  digitalWrite(rightFlipperPin, digitalRead(rightButtonPin) == LOW ? LOW : HIGH);
}

void checkGameOverSensor() {
  int gameOverValue = analogRead(gameOverSensorPin);
  Serial.print("A5 value: ");
  Serial.println(gameOverValue);

  if (gameOverValue < 700) {
    gameOver = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over");
    lcd.setCursor(0, 1);
    lcd.print("Press Reset Btn");
    Serial.println("GAME OVER - Sensor Triggered");
  }
}
}

void handleReset() {
  if (digitalRead(resetButtonPin) == LOW) {
    delay(200); // debounce
    score = 0;
    gameOver = false;
    updateDisplay();
    Serial.println("Game Reset");
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pinball Machine");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
}
