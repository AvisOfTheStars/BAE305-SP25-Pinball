/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/analog/AnalogInput/
*/

int sensorPin = A1;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorLimit = 910;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  calibrate();

}

void loop() {
  // read the value from the sensor:
  int data=analogRead(sensorPin);
  Serial.print("ldr reading=");
  Serial.println(data);
  if (abs(data - sensorLimit) > 75)
  {
    digitalWrite(ledPin, HIGH);
    delay(5000);
  }
  else
   digitalWrite(ledPin, LOW);
  delay(10);
}

void calibrate() {
  int calibTotal = 0;
  for (int i = 0; i < 5000; i++) {
    calibTotal += i;
  }
  sensorLimit = (calibTotal / 5000);
}
