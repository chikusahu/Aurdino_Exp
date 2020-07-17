#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
String keyinput="";

byte rowPins[ROWS] = {A5, A4, A3, A2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A0, 6, 7}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Enter No + A");
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
    if (key=='A'){
      keyinput="";
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }else{
      keyinput=keyinput+key;
    }
  }
  lcd.setCursor(0, 1);
  lcd.print(keyinput);
}
