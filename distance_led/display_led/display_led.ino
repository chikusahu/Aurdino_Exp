#include <LiquidCrystal.h>

#define echoPin 6
#define trigPin 7 

long duration; 
int distance; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Distance");

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" CM");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); 

}
