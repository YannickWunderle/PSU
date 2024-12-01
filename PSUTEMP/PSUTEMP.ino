
#include "SevSeg.h"
SevSeg sevseg;


unsigned long timer;
int CentSec=0;
int temp1;
int temp2;

void setup() {

  // sevseg.Begin(1,2,3,4,5,6,7,8,9,10,11,12,13);

  byte numDigits = 4;
  byte digitPins[] = {
    2, 3, 4,    };
  byte segmentPins[] = { 
    6, 7, 8, 9, 10, 11, 12, 13  };
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);

  timer=millis();
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  //Serial.begin(9600);

}

void loop() {
  // sevseg.PrintOutput();

  //Serial.println(temp);
      sevseg.refreshDisplay();

  unsigned long mils=millis();
  if (mils-timer>=1000) {
    timer=mils;
    CentSec++;

    temp1=(analogRead(0)*50000/1024);
    temp2=(analogRead(1)*50000/1024);

    if (temp1 > temp2) {
      sevseg.setNumber(temp1, 2);


    }
    if (temp2 >= temp1) {
      sevseg.setNumber(temp2, 2);

    }



  }



  if (temp1 > 5500){
    digitalWrite(A3, HIGH);
  }
  if (temp1 < 4500){
    digitalWrite(A3, LOW);
  }

  if (temp2 > 5500){
    digitalWrite(A4, HIGH);
  }
  if (temp2 < 4500){
    digitalWrite(A4, LOW);
  }
}
