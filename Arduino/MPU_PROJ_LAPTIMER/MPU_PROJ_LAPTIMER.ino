/*
A timer that records the number of Laps, the averageLaptime, the LapTime and the totalTime all in seconds.
It counts from 0 to infinity well actually it counts as long as the millis() doesnt overlflow in which case the total time returns to zero in 50 days.
It has a sensitivity, meaning that the car must be fast enough so that it escape the vicinity of the laser within that sensivity and slow enough to 
give the sensitivy time to come back from the loop.


*/



unsigned long startTime=0;
unsigned long lapTime=0;
unsigned long totalTime=0;
unsigned long lastTime=0;
int lapCount,theTime,theLap;
int counter=0;
float aveLap;
float Sum,x;
boolean FT=true;
void setup(){
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
  }
  FT=false;
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
