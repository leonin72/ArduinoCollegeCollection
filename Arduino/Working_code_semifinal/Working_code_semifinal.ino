int lapCounter;

int sensorPin = A0;
int ledPin;
//float aveLap;
//int threshold = 0;

float lap1, lap2, lap3, aveLap;
unsigned long startMillis = millis();
unsigned long lapMillis = 0;
//float lapTime = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
//  if(sensorPin > threshold) {
  //unsigned long currentMillis = millis();
  if(analogRead(sensorPin) < 300) {
    lapMillis = millis() - startMillis;
    startMillis = millis();
    //lapTime = lapMillis/1000;
    digitalWrite(ledPin, HIGH);
    recordLap();
    //printOutputs();
    
    delay(500);
  }
 // Serial.print("Timer: ");
 // Serial.println(millis()/1000);
  
}

void recordLap() {
    switch(lapCounter) {
      case 0:
      Serial.println("Race Started");
      lapCounter++;
      break;
      
      case 1:
        lap1 = lapMillis;
        Serial.print("Lap 1: ");
        Serial.println(lap1);
        lapCounter++;
        break;
      
      case 2:
        lap2 = lapMillis;
        Serial.print("Lap 2: ");
        Serial.println(lap2);
        lapCounter++;
        break;
      
      case 3:
        lap3 = lapMillis;
        lapCounter = 0;
        aveLap = (lap1+lap2+lap3)/3;
    //    intAveLap = 0.5+aveLap/1000;
        Serial.print("Lap 3: ");
        Serial.println(lap3);
        Serial.print("Average Lap Time(s):");
        Serial.println(int(aveLap/1000 + 0.5));
        Serial.print("Average Lap Time(ms):");
        Serial.println(aveLap);
        Serial.println();
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
    

