int RP=5;
int GP=6;
int BP=9;

void setup()                      // run once, when the sketch starts
{
  pinMode(RP, OUTPUT);        // sets the digital pin as output
  pinMode(GP, OUTPUT);  // sets the digital pin as output
  pinMode(BP, OUTPUT);
}
void loop()                       // run over and over again
{
  digitalWrite(RP, HIGH);     // sets the Red LED on
  digitalWrite(GP, HIGH);  // sets the Green LED on
  digitalWrite(BP, HIGH);
  delay(500);                     // waits for half a second
  digitalWrite(RP, LOW);      // sets the Red LED off
  digitalWrite(GP, LOW);  // sets the Green LED off
  digitalWrite(BP, LOW);
  delay(500);                     // waits for half a second
}

