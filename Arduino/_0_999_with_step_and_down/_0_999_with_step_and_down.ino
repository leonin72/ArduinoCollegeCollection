


const byte numeral[10]=
{          //a b c d e f g/dp
B11111100,//0
B01100000,//1
B11011010,//2
B11110010,//3
B01100110,//4
B10110110,//5
B00111111,//6
B11100000,//7
B11111110,//8
B11100110,//9
};
  const int segmentPins[]={18,17,16,15,14,13,12,11};
  const int nbrDigits=3;
  const int digitPins[nbrDigits]={10,8,7};
  signed int counter = 0;
 
  void setup()
  {
    for(int i=0;i<8;i++)
    pinMode(segmentPins[i],OUTPUT);
    
    for(int i=0;i<nbrDigits;i++)
    pinMode(digitPins[i],OUTPUT);
    attachInterrupt(0,s1_press,RISING);
    attachInterrupt(1,s2_press,RISING);
  }
  void loop()
  {
   int x;
   x = showNumber(counter);
  }
  void s1_press()
  {
    counter++;
  }
  void s2_press()
  {
    counter--;
  }
  int showNumber(int number)
  {
  if(number==0)
  
  showDigit(0,nbrDigits-1);
  
  else
  {
    for(int digit=nbrDigits-1;digit>=0;digit--)
    {
    if(number>0)
    {
      showDigit(number%10,digit);
      number=number/10;
    }
    }
  }
  }

  void showDigit(int number, int digit)
  
  {
    digitalWrite(digitPins[digit],HIGH);
    for(int segment = 1;segment<8;segment++)
    {
      boolean isBitSet =  bitRead(numeral[number],segment);
      digitalWrite(segmentPins[segment],isBitSet);
    }
    delay(5);
    digitalWrite(digitPins[digit],LOW);
  }
