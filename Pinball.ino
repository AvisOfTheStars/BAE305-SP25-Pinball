// Instantiate global variables and constants
int score = 0;
// Instantiate pin numbers  
int pinLEDs[] = {1,2,3};

/*
int pinServoL = 
int pinServoR =

int pinPS = {} //Photosensor

int pinSound = 
*/

void setup() {
  // put your setup code here, to run once:

  // Reset position of all motors

  // Flash LEDs to confirm functionality
  
  for (int i : pinLEDS) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(100);                      // wait for a 1/10 second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(100);                      // wait for 1/10 second
  }

  // Instantiate global tracking variables
  //int score = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  // If button pushed activate corresponding flipper

  // If ball in hole (photosensor tripped) score a point
  /*for (int i : pinPS) {
    if (digitalRead(i) == "HIGH") {

      goal();
    }
  }*/

}

void goal(){
  // When a goal is scored update the scoreboard, flash the LEDs, and play a sound
  score++;

}

void reset() {
  // Reset the machine to the starting conditions

  score = 0;

  // Update scoreboard

}
