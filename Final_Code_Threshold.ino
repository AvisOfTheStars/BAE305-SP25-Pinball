#include <LiquidCrystal.h>

// LCD wiring: RS=D12, E=D11, D4=D10, D5=D9, D6=D8, D7=D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Pin Assignments
const int leftFlipperPin = 2;
const int rightFlipperPin = 3;
const int leftButtonPin = 4;
const int rightButtonPin = 5;
const int resetButtonPin = 6;
const int piezoPin = A0; // Moved from D1 to A0 for safe tone + Serial

// Scoring Sensors
const int scorePins[] = {A1, A2, A3, A4};
const int numScorePins = sizeof(scorePins) / sizeof(scorePins[0]);
const int scoreThresholds[] = {800, 800, 800, 800}; // Individual thresholds

// Game Over Sensor
const int gameOverSensorPin = A5;
const int gameOverThreshold = 600;

int score = 0;
bool gameOver = false;
bool resetPressed = false;
unsigned long lastBounceTime = 0;
const int debounceDelay = 200;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Pinball Machine");
  lcd.setCursor(0, 1);
  lcd.print("Score: 0");

  pinMode(leftFlipperPin, OUTPUT);
  pinMode(rightFlipperPin, OUTPUT);
  digitalWrite(leftFlipperPin, HIGH);
  digitalWrite(rightFlipperPin, HIGH);

  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(gameOverSensorPin, INPUT);
}

void loop() {
  handleFlippers();

  // ✅ Print sensor values for A1–A4 every loop
  for (int i = 0; i < numScorePins; i++) {
    int value = analogRead(scorePins[i]);
    Serial.print("A");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print("  ");
  }
  Serial.println();

  if (!gameOver) {
    handleScoring();
    checkGameOverSensor();
  } else {
    handleReset();
  }

  delay(2); // Slow down Serial output slightly
}

void handleScoring() {
  for (int i = 0; i < numScorePins; i++) {
    int sensorValue = analogRead(scorePins[i]);

    if (sensorValue < scoreThresholds[i] && (millis() - lastBounceTime > debounceDelay)) {
      score += 10;
      playCoinSound(); // Play sound immediately after scoring
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

  if (gameOverValue < gameOverThreshold) {
    gameOver = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over");
    lcd.setCursor(0, 1);
    lcd.print("Press Reset Btn");
    Serial.println("GAME OVER - Sensor Triggered");
  }
}

void handleReset() {
  if (digitalRead(resetButtonPin) == LOW && !resetPressed) {
    resetPressed = true;
    delay(200); // debounce
    score = 0;
    gameOver = false;
    updateDisplay();
    Serial.println("Game Reset");
  } else if (digitalRead(resetButtonPin) == HIGH) {
    resetPressed = false; // re-arm
  }
}

void playCoinSound() {
  tone(piezoPin, 1318, 80); delay(90); // E6
  tone(piezoPin, 1568, 80); delay(90); // G6
  tone(piezoPin, 1760, 80); delay(90); // A6
  noTone(piezoPin);
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pinball Machine");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
}
