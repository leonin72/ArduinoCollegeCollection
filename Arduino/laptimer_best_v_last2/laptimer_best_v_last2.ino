/* Single lane slot car timer
Written by TheInsanityUnleashed @ Youtube
http://www.youtube.com/watch?v=SzaPZO4XQIs
----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin A0 o----------
 
 
 Pin 9 ------Piezo-----gnd
 
 
 Sensitivity Pot --------- Pin A1
 
----------------------------------------------------
*/

#include <LiquidCrystal.h>
int lap1;
int lap2;
int lap3;
int aveLap;
int lapCounter;
//variables
const byte lightPin = 0;  
const byte speakerPin = 9;
int lightSensor = 0;
unsigned long lapMillis = 0;
unsigned long startMillis; 
unsigned long bestMillis = 9999999;
float lapTime = 0.00;
float bestLap = 0.00;
boolean firstTrigger = true;
boolean newBest = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Start!           ");
    Serial.begin(9600); 
    pinMode(speakerPin, OUTPUT);
    digitalWrite(speakerPin, LOW);
}

void loop()
{
//reading from light sensor
lightSensor = analogRead(lightPin);
  //If car detected
  //if(lightSensor < analogRead(1)){
    if(lightSensor > 0){    
    //determine lap time in milliseconds
    lapMillis = millis() - startMillis;
    startMillis = millis();
    
   // lapTime = lapMillis / 1000.00;
   // lapTime = lapMillis / 1000.00;
    
    //if firs trigger print race started
    if (firstTrigger == true){
      lcd.setCursor(0, 0);
      lcd.print("Race Started!    ");
    }
    
    //print if not first trigger
    if (firstTrigger != true){
     // Serial.print("lapTime: ");
     // Serial.println(lapTime);
      Serial.print("lapMillis: ");
      Serial.println(lapMillis);
      //print lap time
      lcd.setCursor(0, 0);
      lcd.print("Last: ");
      lcd.print(lapTime);
      lcd.print("       ");   
    }
   
   /*     
    //if last lap is better than best lap
    if(lapMillis < bestMillis && firstTrigger != true)
    {
      bestMillis = lapMillis;
      bestLap = lapTime;
      Serial.print("bestLap: ");
      Serial.println(bestLap);
      //print best lap time
      lcd.setCursor(0, 1);
      lcd.print("Best: ");
      lcd.print(bestLap);
      lcd.print("      ");
      newBest = true;
    }
       firstTrigger = false;
    Serial.println("----------------"); 
  */
}
}
    /*
    //beep piezo
    if(newBest == true)
    {
      digitalWrite(speakerPin, HIGH);
      delay(25);
      digitalWrite(speakerPin, LOW);
      delay(25);
      digitalWrite(speakerPin, HIGH);
      delay(25);
      digitalWrite(speakerPin, LOW);
      delay(25);
      digitalWrite(speakerPin, HIGH);
      delay(25);
      digitalWrite(speakerPin, LOW);
      delay(25);
      digitalWrite(speakerPin, HIGH);
      delay(25);
      digitalWrite(speakerPin, LOW);    
      newBest = false;
    } 
    else
    {
      digitalWrite(speakerPin, HIGH);
      delay(150);
      digitalWrite(speakerPin, LOW);
    }
    */
 
