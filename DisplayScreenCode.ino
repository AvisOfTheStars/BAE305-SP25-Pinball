
int position = 0;
#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display


void setup() {
  
  lcd.begin(16, 2);
  lcd.print("Total Score: xxx");
  delay(1000);
}

void loop() {

  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(175);
  }

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(175);
  }

  lcd.begin(16, 2);
  lcd.setCursor(0, 0); 
  lcd.print("New Score:");
  delay(1000);

  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(200);
  }

  delay(300);

  lcd.begin(16, 2);
  lcd.setCursor(13, 0); 
  lcd.print("123");
  delay(500);

  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(200);
  }

  lcd.begin(16, 2);
  lcd.print("Total Score: 123");
  delay(5000);

}
