long previousMillis = 0;
 
//interval in milliseconds till the next loop
long interval = 500;
 
//initalizing the pin var
int pin[] = {LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW};
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}
 
void loop()
{
  //gets timing in milliseconds
  unsigned long currentMillis = millis();
 
  //tests if the time from the previous loop and this one have met requirements
  //of the specified time
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
 
    //first loop will go through 0 to 255
    for(int x=0; x<255; x++)
    {
      //makes the temp contain a binary version of the number x
       String temp = String(x,BIN);
      //this loop reads the characters in each element
      for(int y=0;y<8; y++)
      {
        //adds in the correct amount of zeros so that it will be a true
        //8-bit digit
        if (temp.length()<8)
        {
          for(int i=temp.length(); i<8; i++){
            //forces a 0 in front of temp
            temp="0"+temp;
          } 
        }
        //statment determining if the character is a 1 or 0 and sets pin 
        //accordingly
        if(temp.charAt(y)=='1')
        {
          pin[y]=HIGH;
        }
        else
        {
          pin[y]=LOW;
        }
        delay(10);
      }
      digitalWrite(2,pin[0]);
      digitalWrite(3,pin[1]);
      digitalWrite(4,pin[2]);
      digitalWrite(5,pin[3]);
      digitalWrite(6,pin[4]);
      digitalWrite(7,pin[5]);
      digitalWrite(8,pin[6]);
      digitalWrite(9,pin[7]);
    } 
  }
}
