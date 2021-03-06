//Viktor Goleš 20.11.2020.

#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
Servo servo;

const int button = 2;

int lastButtonState;
int currentButtonState;

int choice;

void printChoice(int choice)
{
  if(choice == 1) {
    Serial.println("CUGAJ");
    lcd.print("CUGAS");
  } else {
     Serial.println("DIJELIS");
     lcd.print("DIJELIS");
      }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(button, INPUT_PULLUP);

  lcd.begin(16, 2);
  
  servo.attach(5);
  servo.write(0);
  
  currentButtonState = digitalRead(button);
  
  lcd.print("Kocka sudbine");
}

void loop() {
  
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(button);
 

  if(lastButtonState == HIGH && currentButtonState == LOW) {

    lcd.clear();

    servo.write(100);
    delay(700);
    servo.write(0);

    choice = random(2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kocka zeli da:");
    lcd.setCursor(0, 1);

    printChoice(choice);

       
  }
}

