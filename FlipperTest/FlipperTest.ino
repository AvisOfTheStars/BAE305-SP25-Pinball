// Flipper test

const int buttonLeftPin = 4;
const int flipperLeftPin = 2;

const int buttonRightPin = 6;
const int flipperRightPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonLeftPin, INPUT);
  pinMode(flipperLeftPin, OUTPUT);
  pinMode(buttonRightPin, INPUT);
  pinMode(flipperRightPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if (digitalRead(buttonLeftPin)) {
  //  digitalWrite(flipperLeftPin, HIGH);
  //}
  int buttonStateLeft = digitalRead(buttonLeftPin);
  int buttonStateRight = digitalRead(buttonRightPin);

  if (buttonStateLeft == HIGH) {
    // turn LED on:
    digitalWrite(flipperLeftPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(flipperLeftPin, LOW);
  }

  if (buttonStateRight == HIGH) {
    // turn LED on:
    digitalWrite(flipperRightPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(flipperRightPin, LOW);
  }

  delay(10);
}
