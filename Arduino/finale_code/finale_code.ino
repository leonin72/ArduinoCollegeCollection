
/*
          MPU PROJECT
          LAPTIMER(AVERAGE LAP, SUM of LAPS, NUMBER OF LAPS, TIME OF EACH LAP) 
          CODED BY LEO ARGOSO
          FABRICATED AND DESIGNED BY ROEMER TIMBRE
          REQUIRED BY DEAN STEPHEN RUIZ
          


A timer that records the number of Laps, the averageLaptime, the LapTime and the totalTime all in seconds.
It counts from 0 to infinity well actually it counts as long as the millis() doesnt overlflow in which case the total time returns to zero in 50 days.
It has a sensitivity, meaning that the car must be fast enough so that it escape the vicinity of the laser within that sensivity and slow enough to 
give the sensitivy time to come back from the loop.

MANUAL:
First set up the race track, make sure that the laser hits the phototransist horizontally, it has a 30 degree angle range horizontally
Second Power the Arduino ON
Third Read the following characters shown, if you are a proffessor make sure to Grade the names given at full credit and wait for the Start character to emerge
Fourth After the Start emerges put your auto-mobile and let it run, when it trips teh laser the first time, it will show the all the values needed at 0, dont be alarmed this indicates that
the race has started
Fifth Sit back relaxed and enjoy the show

NOTE:
since the our race track is a simple CIRCUIT, most likely it will have the same speed almost all the time. that is to be expected since the car runs the same distance at the same speed.
If the car is too fast or too slow, simlply adjust the sensitivity by adjusting the delay at the loop.
The Lap will continue to count, unless reset or after 50 days based from the millis function
REMEMBER to TEST IF THE LASER HITS THE SENSOR PROPERLY
THIS CODE WAS MADE BY VARIOUS RESEARCH ON VARIOUS RESOURCES, it is fundamentally very different from other Laptimers

RECOMMENDATIONS:
BY ADDING MORE SENSORS YOU CAN ADD ACCURACY, OR ADD CHECKPOINTS OR CAN EVEN PLAY IN MULTIPLAYER DEPENDING ON YOUR DESIGN
A BETTER CAR AND TRACK IS OFCOURSE ADVICED

*/


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//digital Pins used in the aceduino to connect to the LCD
// unsigned long used so that the following variables can contain a large amount of values
unsigned long startTime=0;// stores the value of starting time of which the program is initiated
unsigned long lapTime=0;// stores the value of the lapTime in milliseconds
unsigned long totalTime=0;//stores the value of the total time the the program is initiated in milliseconds, can run upto 50 days based from the millis() function(must not be confused with Sum of total laps
unsigned long lastTime=0;// stores the value of the lastTime the laser was tripped
// int only shows the integers of the following values,it doesnt round off its values, instead it removes its decimal values and reatains its integers
int lapCount,theTime,theLap,y;// lapCount= number of Laps, theTime=totalTime in seconds, theLap=lapTime in seconds
int counter=0;// starts the counter at 0
// enables the variables below to contain decimal points
float aveLap;// store the average lap made by the car
float Sum,x;//Stores the total LapTime made by the car in seconds
// boolean function enables us to use true or false. where true is 1 and false is 0
boolean FT=true;// sets the preliminary value of FT to true
int buzzer=9;// sets the Pin of the buzzer
void setup(){
lcd.begin(16,2);// indicates the number of columns and rows found on the lcd
Serial.begin(9600);//enables Serial funtion at a rate of 9600(baud rate)
lcd.setCursor(0,0);//Sets Cursor to follwing columns and rows
lcd.print("MPU PROJECT");//Prints the characters on the LCD
lcd.setCursor(0,1);// set the Cursor
lcd.print("MADE BY");// prints the characters on the LCD
delay(1000);// wait for 1 second
lcd.setCursor(0,0);// sets cursor
lcd.print("ROEMER TIMBRE");// prints characters
lcd.setCursor(0,1);//sets cursor
lcd.print("LEO ARGOSO");//prints characters
delay(1000);//wait for 1 sec
lcd.clear();//clears the lcd
lcd.setCursor(0,0);// set the cursor
lcd.print("START");//prints the character
pinMode(buzzer,OUTPUT);// sets the buzzer at output

pinMode(A0,INPUT);// sets the A0 at as input
}


void loop(){

  //shows totaltime, used to check if totalLaps by reffering to the totalTime
  if((FT!=true)&&(counter>=0)){
  totalTime=millis();
  theTime=totalTime/1000;
   Serial.print("theTime");
  Serial.println(theTime);
}    
// whenever the laser is tripped voltage goes down, initiates if the following function if condtion is achieved
if(analogRead(A0)<300){//Reads value of A0, if condition is achieved, continue if not skip
 
//used to check if lap starts recording after the first trigger 
  if ( FT == true){
Serial.println("START");


  }
  // if first trigger is already finished starts counting the lapCount,theLap,aveLAp,Sum
  if( FT!=true){
 // code used to store the value of lapTime
    lapTime=millis()-startTime;
  x=lapTime/1000;
  theLap=x+0.5;
  startTime=millis();
  Serial.print("theLap:");// used to check
  Serial.println(theLap);// used to check
LapFunction();// funtion to compute for lapCount and theLap
AveFunction();// used to compute for aveLap and Sum
y=1;// set value to 1, used as a condition later to values to lcd
//buzzer beeps everytime the laser wire is tripped, used to indicate that laser wire is tripped, used to check how many times the laser wire is tripped
digitalWrite(buzzer,HIGH);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
digitalWrite(buzzer,LOW);
  }
FT=false;// sets the value of FT to false, so that FT is only true once
// if condition is met enables the showLcd funtion
if(y=1){
showLcd();// funtion to show the values needed by the user
}
}

delay(200);// delays the previous programs by 60 milliseconds, may be used to adjust the sensitivity of the phototransistor( if too low, may count to fast, too high may not recognizer other laps)
}
//funtion for lap0(start) to lap00(infinity) note---> infinity refers to the limit of the LCD and 328p a valid output.
void LapFunction(){
counter++;// increments the count
lapCount=counter;/ sets lapCount as the counter value
Serial.print("Lap:");// used to check
Serial.println(lapCount);// used to check
}
//Function to calculate averageLap run by the car and the Sum Total of the Time run by the car
void AveFunction(){
Sum=(lapTime+lastTime)/1000;//adds the lapTime and lastTime the car run. where lapTime is the current time ran, and the lastTime is the previous time in seconds
  aveLap=Sum/lapCount;// divdes the Sum by the corresponding lapCOunt, shows the average lap in seconds
Serial.print("aveLap");// used to check
Serial.println(aveLap);// used to check
lastTime=Sum*1000;// records the calue of lastTime in milliseconds
}
// shows the values needed on the lcd
void showLcd(){
lcd.clear();// clears the lcd to get ready for the new values
lcd.setCursor(0,0);//set cursor
lcd.print("Lap");//prints character
lcd.print(lapCount);// shows value of lapCount
lcd.setCursor(8,0);//set cursor
lcd.print(lapTime);// shows the value of the ran by the car in milliseconds on the lcd
lcd.print("ms");//prints ms for milliseconds
lcd.setCursor(0,1);//set cursor
lcd.print("Ave");//prints Ave
lcd.print(aveLap);//shows Value of the the averageLap in seconds
lcd.setCursor(8,1);//set Cursor
lcd.print("Sum");//prints character
lcd.print(Sum); //shows value of SUM


}


