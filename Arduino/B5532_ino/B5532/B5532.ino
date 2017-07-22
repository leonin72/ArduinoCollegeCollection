
 long lastTime, millisTime, deltaTime = 0;//
const byte numeral[10]=                   //if commmon cathode just complement
{          //a b c d e f g/dp             
B00000011,//0B00000011
B10011111,//1B10011111
B00100101,//2B00100101
B00001101,//3B00001101
B10011001,//4B10011001
B01001001,//5B01001001
B11000000,//6B11000000
B00011111,//7B00011111
B00000001,//8B00000001
B00011001,//9B00011001
};
  const int segmentPins[]={A4,A3,A2,A1,A0,13,12,11};// sets the segment pins
  const int nbrDigits=2;                            // set the number the number of digits
  const int digitPins[nbrDigits]={8,7};             // indicates the pins used for the digits
  unsigned int counter = 0;                           // sets the counter to 0
 
  void setup()
  {
    Serial.begin(9600);
    for(int i=0;i<8;i++)                            // i starts at 0, if i is less than 8, counts up
    pinMode(segmentPins[i],OUTPUT);                 // set the segment pins to outputs
  
    for(int i=0;i<nbrDigits;i++)                    //i starts at 0. if i is less than nbrdigits, i integrates
    pinMode(digitPins[i],OUTPUT);
   }
  void loop()
  {
 
                                            // intrdocuces x
    showNumber(counter);                         // sets x as the 
  millisTime = millis();   // millisTime=millis()
 
      deltaTime = millisTime-lastTime;              // sets value of Delta
      if (deltaTime>1000)                          // if delta reaches a certain value it counts, this as the delay for counting, in this case 1 second
       {
         counter++;                                // increments 
         lastTime = millisTime;                    //records LastTime to millis
       }  
  }  


  void showNumber(int number)                      // program for show the number
  { 
  
  if(number<10)
  {
  showDigit(0,0);            // shows 00-09
  showDigit(number,1);
  }
  else
  {
    for(int digit=nbrDigits-1;digit>=0;digit--) // display the value corresponding to each digit
                                                // leftmost digit is 0, rightmost is one less than the number of places
    {
    if(number>0)                              
    {
      showDigit(number%10,digit);
      number=number/10;
    }
   
  }
 
  }
 
 
}

  void showDigit(int number, int digit)            // program for multiplexing, shows which digit should be on for a specific number
  
  {
    digitalWrite(digitPins[digit],HIGH);
    for(int segment = 1;segment<8;segment++)
    {
      boolean isBitSet =  bitRead(numeral[number],segment);
      digitalWrite(segmentPins[segment],isBitSet);
    }
    delay(5);                                    // multiplexing technique used, set the delay of the multiplexing, the higher the number of more stable however risks reducing POV effect.
    digitalWrite(digitPins[digit],LOW);
   
  }
 

