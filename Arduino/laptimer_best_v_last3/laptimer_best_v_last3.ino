int lap1, lap2, lap3;
int aveLap;
int lapCounter;

int sensorPin = A0;
int threshold = 0;
unsigned long startMillis;
unsigned long lapMillis;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
//  if(sensorPin > threshold) {
  if(digitalRead(A0)==HIGH) {
    lapMillis = (millis() - startMillis)/1000;
    startMillis = millis();
    recordLap();
    printOutputs();
  }
  delay(1000);
}

void recordLap() {
    switch(lapCounter) {
      case 1:
      lap1 = lapMillis;
      lapCounter++;
      break;
      
      case 2:
      lap2 = lapMillis;
      lapCounter++;
      break;
      
      case 3:
      lap3 = lapMillis;
      lapCounter++;
      break;
    }
}

void printOutputs() {
  Serial.print("lap1:");
  Serial.println(lap1);
  
  Serial.print("lap2:");
  Serial.println(lap2);
  
  Serial.print("lap3:");
  Serial.println(lap3);
  
  Serial.print("button:");
  Serial.println(digitalRead(A0));
}
    
