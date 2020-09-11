#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin=9;
const int echoPin=10;
float distance;
boolean c=0;
int duration,x;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
lcd.print("NULL LENGTH: ");
lcd.setCursor(0, 1);
lcd.print("HEIGHT: ");
}

void loop() {

digitalWrite(trigPin,LOW);
delay(10);
digitalWrite(trigPin,HIGH);
delay(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=duration*0.034/2;
if(!c)
{
 x=distance;
 // x=Serial.println(distance);
 Serial.println(distance);
  delay(2000);
  c = 1;
  lcd.setCursor(12, 0);
  lcd.print(x);
}
else
{
  
  lcd.setCursor(8, 1); 
  if (distance >= x)
  lcd.print(x);
  else
  lcd.print(x-distance);
 }
 delay(1000);
}
