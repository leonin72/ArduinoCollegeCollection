unsigned long startTime=0;
unsigned long lapTime=0;
unsigned long totalTime=0;
unsigned long lastTime=0;
int lapCount;
int counter=0;
float aveLap;
float Sum;
boolean FT=true;
void setup(){
Serial.begin(9600);
pinMode(A0,INPUT);
}


void loop(){
 Serial.println(totalTime);
  
    
if(analogRead(A0)>300){
 
 
  if ( FT == true){
Serial.println("START");
  }
  if( FT!=true){
  totalTime=millis();
 
  lapTime=millis()-startTime;
  startTime=millis();
   Serial.println(lapTime);
LapFunction();
AveFunction();
  }
  FT=false;
}

delay(1000);
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
