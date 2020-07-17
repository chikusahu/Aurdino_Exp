/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#define joyX A0
#define joyY A1

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin
int xValue,yValue;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(100);
}

void loop() {

  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  
  yValue = map(yValue, 0, 1023, 0, 80);     // scale it to use it with the servo (value between 0 and 180)
  delay(1);
  myservo.write(yValue);                  // sets the servo position according to the scaled value
  delay(1);                           // waits for the servo to get there
}
