#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,4);
int input;

void setup(){
 mySerial.begin(9600);
 int WLed = 0;
 int BLed = 1;
 pinMode(WLed, OUTPUT);
 pinMode(BLed, OUTPUT); 

}

void loop(){
  int WLed = 1;
  int BLed= 0;
  if (mySerial.available()){
    input = mySerial.read();
  }
    
    if (input == '1'){ //hot hot hot
      analogWrite(BLed, 0);
      for (int fade = 0; fade < 255; fade++){ 
      analogWrite(WLed,fade);
      delay(4);
      }
      for (int fade = 255; fade > 0; fade--){ 
      analogWrite(WLed,fade);
      delay(4);
      }
      
     }
     
     if (input == '2'){ //warm
      analogWrite(BLed, 0);
      analogWrite(WLed,255);
      }
     
     if (input == '3'){ //cold 
      analogWrite(WLed, 0);
      for (int fade = 0; fade < 255; fade++){ 
      analogWrite(BLed,fade);
      delay(2);
      }
      for (int fade = 255; fade > 0; fade--){ 
      analogWrite(BLed,fade);
      delay(2);
      }
     }
 
     if (input == '4'){ //cool
      analogWrite(WLed, 0);
      analogWrite(BLed,255);
      }
     
     if (input == '5'){ //warm windy
      analogWrite(BLed, 0);
      int fade = random(0,255);
      analogWrite(WLed,fade);
      int del = random(5,50);
      delay(del);
      }
      
      if (input == '6'){ //warm windy
      analogWrite(WLed, 0);
      int fade = random(0,255);
      analogWrite(BLed,fade);
      int del = random(5,50);
      delay(del);
      }
    }     
 


