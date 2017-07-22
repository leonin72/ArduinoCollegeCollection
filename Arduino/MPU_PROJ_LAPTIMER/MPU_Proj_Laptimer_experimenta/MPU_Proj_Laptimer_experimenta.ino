
/*
A timer that records the number of Laps, the averageLaptime, the LapTime and the totalTime all in seconds.
It counts from 0 to infinity well actually it counts as long as the millis() doesnt overlflow in which case the total time returns to zero in 50 days.
It has a sensitivity, meaning that the car must be fast enough so that it escape the vicinity of the laser within that sensivity and slow enough to 
give the sensitivy time to come back from the loop.


*/


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned long startTime=0;
unsigned long lapTime=0;
unsigned long totalTime=0;
unsigned long lastTime=0;
int lapCount,theTime,theLap,y;
int counter=0;
float aveLap;
float Sum,x;
boolean FT=true;
void setup(){
lcd.begin(16,2);
Serial.begin(9600);
pinMode(A0,INPUT);
}


void loop(){

  
  if((FT!=true)&&(counter>=0)){
  totalTime=millis();
  theTime=totalTime/1000;
   Serial.print("theTime");
  Serial.println(theTime);
}    
if(analogRead(A0)>300){
 
 
  if ( FT == true){
Serial.println("START");
lcd.print("Race Started");
  }
  
  if( FT!=true){
 
    lapTime=millis()-startTime;
  x=lapTime/1000;
  theLap=x+0.5;
  startTime=millis();
  Serial.print("theLap:");
  Serial.println(theLap);
LapFunction();
AveFunction();
y=1;
  }
FT=false;
showLcd();
}

delay(500);
}
void LapFunction(){
counter++;
lapCount=counter;
Serial.print("Lap:");
Serial.println(lapCount);
}
void AveFunction(){
Sum=(lapTime+lastTime)/1000;
  aveLap=Sum/lapCount;
Serial.print("aveLap");
Serial.println(aveLap);
lastTime=Sum*1000;
}
void showLcd(){
while(y=1){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Lap ");
lcd.print(lapCount);
lcd.setCursor(8,0);
lcd.print("Time:");
lcd.print(theLap);
lcd.setCursor(0,1);
lcd.print("aveLap:");
lcd.print(aveLap);
delay(500);
y=2;
}
while(y==2){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("aveLap:");
lcd.print(aveLap);
lcd.setCursor(0,1);
lcd.print("Total Time:");
lcd.print(Sum);
}
}
