#include <LiquidCrystal.h>
int RED = 8,BLUE=10,GREEN=9;
int Power=12; 
int inPin = A0;
int sendSignal=11;
int val = 0;
int pumpPin=13;   
int period = 3000;
unsigned long time_now = 0;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
lcd.begin(16, 2);
pinMode(sendSignal,OUTPUT);
pinMode(RED, OUTPUT);
pinMode(BLUE,OUTPUT);
pinMode(GREEN,OUTPUT);  
pinMode(inPin, INPUT);
Serial.begin(9600);
digitalWrite(sendSignal,LOW);
pinMode(pumpPin,OUTPUT);


}
void flash(){
  digitalWrite(Power,HIGH);
  delayMicroseconds(10000);
  digitalWrite(Power,LOW);
  delayMicroseconds(10000);
}
void noFlash(){
  digitalWrite(Power,HIGH);
}
void detection(){
     digitalWrite(GREEN,LOW);         
     digitalWrite(RED,HIGH);
     lcd.setCursor(2,0);
     lcd.print("FIRE DETECTED!");
     lcd.setCursor(1,1);
     lcd.print("Sending message");
     delay(500);
     lcd.clear();
}
void safe(){
     digitalWrite(RED,LOW);
     digitalWrite(GREEN,HIGH);
     lcd.setCursor(1,0);
     lcd.print("HOUSE IS SAFE");
     lcd.setCursor(2,1);
     lcd.print("No Detection");
     delay(500);
     lcd.clear();
}

void loop(){
  val = analogRead(inPin);  
  Serial.println(val);
  time_now = millis();
  if (val >=900 ) {
    while(millis()< time_now + period){
        detection();
        flash();
        digitalWrite(pumpPin,LOW);
    }
     
     
  } 
  else  {
     noFlash();
     safe();
     digitalWrite(pumpPin,HIGH);
     
     
  }
  
}
