/* Single lane 3 laps timer and average
written by Leo Argoso and Roember Timbre
MPU Project
4ECEB
----------------------------------------------------

      (collector)     PhotoTr (emitter)     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin A0 o----------
 
 
 Pin 9 ------Piezo-----gnd
 
 
 Sensitivity Pot --------- Pin A1
 
----------------------------------------------------
*/
#include <LiquidCrystal.h>
int lapCounter;                          //introduces lapcounter
int sensorPin = A0;                      // set A0 for phototransistor output
int ledPin;                              // pin for ledPin
int intAveLap;                           // introduces AveLap as integer
float f=0.5;                             // introduces and set f as 0.5, used for estimation
unsigned long lap1, lap2, lap3, aveLap;  // sets the following value for more counting capability
unsigned long startMillis = millis();    // set our starting counting time as milliseconds
unsigned long lapMillis = 0;            // sets lapmillis to 0
//float lapTime = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
boolean firstTrigger = true;
void setup() {
  Serial.begin(9600);                  // starts up serial function at a baudrate of 9600
  pinMode(sensorPin, INPUT);           // sets sensorPin as input
  lcd.begin(16, 2);                    // starts up  lcd function with 16 columns and 2 rows
  lcd.setCursor(0, 0);                // set the cursor at the first column
  lcd.print("Leo Argoso");           // prints at lcd
  lcd.setCursor(0, 1);                // sets cursor at 2nd column
  lcd.print("Roemer Timbre");        // printt at lcd
  delay (1000);
  lcd.clear();                       // clears lcd
 lcd.setCursor(0, 0);                // same thing as above
 lcd.print("MPU Project");
 lcd.setCursor(0, 0);
 lcd.print("Lap Timer");
 delay (1000);
  
}

void loop() {
// set up the loop
// if the sensorPin is lower than 300 starts the counting for laptimer
// also triggers laser trip sound
  if(analogRead(sensorPin) < 300) {
    lapMillis = millis() - startMillis;
    startMillis = millis();
    if (firstTrigger == true){
      lcd.setCursor(0, 0);
      lcd.print("Race Started!    ");
    }
    if (firstTrigger != true){
    digitalWrite(ledPin, HIGH);
    // tone for buzzer and duration
    tone(9,1500,1000);
    // uses case and switch function to record lap 1 lap 2 lap 3 and aveLap
    //prints output to LCD
    //lapcounter used to change switch from lap 1 to lap2 and so on and so forth
    recordLap();
    
    
    delay(500);
    } 
  }
 // plays at startup and waiting
 else
 
{tone(9,2500);}
 
 // Serial.print("Timer: ");
 // Serial.println(millis()/1000);
  
}

void recordLap() {
    switch(lapCounter) {
      case 0:
        lap1 = lapMillis;             // records lapMillis to lap1
        Serial.print("Lap 1: ");
        Serial.println(lap1);
         lcd.setCursor(0, 0);
      lcd.print("Last: ");
      lcd.print(lap1);              // prints value of lap1
      lcd.print("       ");   
        lapCounter++;              //counts to case 1
        break;
      
      case 1:
        lap2 = lapMillis;        // records value to lap2
        Serial.print("Lap 2: ");
        Serial.println(lap2);
           lcd.setCursor(0, 0);
      lcd.print("Last: ");
      lcd.print(lap2);          // prints value to lcd
      lcd.print("       ");   
        lapCounter++;          // swtich to case 2
        break;
      
      case 2:
        lap3 = lapMillis;        //records value to lap 3
        lapCounter = 0;          // resets lapcount to zero, switch back to case 0
        aveLap = (lap1+lap2+lap3)/3;     // average the the value of la
        intAveLap = f+aveLap/1000;        // estimates the aveLap and turns it to seconds only shows integer
        Serial.print("Lap 3: ");
        Serial.println(lap3);           
        Serial.print("Average Lap Time(s):");
        Serial.println(intAveLap);
        Serial.print("Average Lap Time(ms):");
        Serial.println(aveLap);
        Serial.println();
           lcd.setCursor(0, 0);
      lcd.print("Last: ");
      lcd.print(lap3);                  //prints lap 3
      lcd.print("       "); 
      lcd.setCursor(0, 1);
      lcd.print("intAveLap: ");
      lcd.print(intAveLap);             //prints intaveLap
      lcd.print("       "); 
        break;
    }
}



/*
void printOutputs() {
  
  if (lapCounter >= 0) {
    Serial.print("Lap 1: ");
    Serial.println(lap1/1000);
    }
  if (lapCounter >= 1) {
    Serial.print("Lap 2: ");
    Serial.println(lap2/1000);
    }
  if (lapCounter >= 2) {
    Serial.print("Lap 3: ");
    Serial.println(lap3/1000);
    Serial.print("Average Lap Time:");
    Serial.println(lapTime/1000);
    }  
  Serial.println();
  //Serial.print("button:");
  //Serial.println(digitalRead(A0));
  
  //Serial.print("lapMillis:");
  //Serial.println(lapMillis);
  
  //Serial.print("lapTime:");
  //Serial.println(lapTime);  
}
*/
    

