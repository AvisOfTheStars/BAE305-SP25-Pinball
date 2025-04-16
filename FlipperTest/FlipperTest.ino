// Flipper test

const int buttonLeftPin = 5;
const int flipperLeftPin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonLeftPin, INPUT);
  pinMode(flipperLeftPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonLeftPin)) {
    digitalWrite(flipperLeftPin, HIGH);
  }
}
