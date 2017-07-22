#include <LiquidCrystal.h>
int X;
int Y;
int Z;
int W;
int V;
int U;
int T;
int x = -1;
int button1 = 10;//orig 8
int button2 = 9;
int button3 = 8;//orig 10
int previouslyPressed1 = 0;
int previouslyPressed2 = 0;
int buzzer = 13;
int AA = 0;
int stopSecond = 0;
int stopMinuite = 0;
int theTime;
int Latch = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.clear();  
lcd.begin(16,2);  

W = 300;
U = 0;
T = 0;
lcd.print("Timer/Stopwatch");
delay(1000);
  lcd.clear();
}
  

void loop()
{
 
 while (x == -1){
lcd.setCursor(0,0);
   lcd.print("Timer - 1");
 lcd.setCursor(0,1);
 lcd.print("Stopwatch - 2");
if(digitalRead(button3) == HIGH)
  {x = 0;
  lcd.clear();}
    if(digitalRead(button2) == HIGH)
  {
     x = 5;
    lcd.clear();
    lcd.print("Stopwatch");
    delay(1000);
    lcd.clear();
  }

}
  
while (x == 0)
{
  while(AA == 0){
   lcd.print("Minuite Hand");
  delay(1000);
   AA = 1;
   lcd.clear();
  }
  
  if ( T < 0 )
  {
    T = 0;
lcd.clear();  
}
  if((digitalRead(button1) == HIGH)   &&  (previouslyPressed1 == 0)) {
    T = T + 1;
    previouslyPressed1 = 1;
    delay(50);
    lcd.clear();
  }
      if((digitalRead(button1) == LOW)   &&  (previouslyPressed1 == 1)) {
    previouslyPressed1 = 0;
    delay(50);
}
  if((digitalRead(button2) == HIGH)   &&  (previouslyPressed2 == 0)) {
    T = T - 1;
    previouslyPressed2 = 1;
    delay(50);
    lcd.clear();
  }
        if((digitalRead(button2) == LOW)   &&  (previouslyPressed2 == 1)) {
    previouslyPressed2 = 0;
    delay(50);
}
    
  lcd.setCursor(0,0);
lcd.print(T);
lcd.print(":");
if (U > 9){
lcd.print(U);
 
}
else{
  
 lcd.print("0");
 lcd.print(U);

}
  
  
  
  if (digitalRead(button3) == HIGH)
  {
   x = 1;
  V = (millis()/(1000));
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.clear();
 lcd.print("Second Hand"); 
 lcd.setCursor(0,1);
 lcd.print("(Hold to ignore)");
 lcd.setCursor(0,0);
  delay(1000);
  lcd.clear();
 
  }
  
}
 while (x == 1)
  {

    if ( U > 59 ){
    U = 0;}
    if(U < 0){
      U = 59;
    lcd.clear();}
  if((digitalRead(button1) == HIGH)   &&  (previouslyPressed1 == 0)) {
    U = U + 1;
    previouslyPressed1 = 1;
    delay(50);
    lcd.clear();
  }
      if((digitalRead(button1) == LOW)   &&  (previouslyPressed1 == 1)) {
    previouslyPressed1 = 0;
    delay(50);
}
  if((digitalRead(button2) == HIGH)   &&  (previouslyPressed2 == 0)) {
    U = U - 1;
    previouslyPressed2 = 1;
    delay(50);
    lcd.clear();
  }
        if((digitalRead(button2) == LOW)   &&  (previouslyPressed2 == 1)) {
    previouslyPressed2 = 0;
    delay(50);
}
    
  lcd.setCursor(0,0);
lcd.print(T);
lcd.print(":");
if (U > 9){
lcd.print(U);
 
}
else{
  
 lcd.print("0");
 lcd.print(U);

}
  
  
  
  if (digitalRead(button3) == HIGH)
  {
   x = 2;
   if (T > 0){
 W = (T*60) + U;}
else{
  W = U;}
  lcd.clear();
  lcd.setCursor(0,0);
  V = (millis()/1000);
}
  
}
  
  
   
X = (W - (millis()/(1000))) + V;
  
  //Here is the Second to Minute-second Conversion. X is the second input
Y = X/60; //Y is the minute output
Z = X - (60*Y); //Z is the second output



  // This is the display of the minutes
lcd.setCursor(0,0);

lcd.print(Y);
lcd.print(":");

if (Z > 9)
{
lcd.print(Z);
lcd.print("   ");
}
else
{
  lcd.print("0");
  lcd.print(Z);
  lcd.print("  ");
  

}
if((Y == 0) && (Z == 0))
{ 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Timer is over");
 while(digitalRead(button3) == LOW)
 {
   
   digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
  delay(100);
  
   
 }
 x = -1;
 delay(1000);
 lcd.clear();
 AA = 0;
}


while(x == 5){

if(stopSecond > 59)
{
  stopSecond = 0;
  stopMinuite = stopMinuite + 1;
   theTime = theTime + 60;
}
  
  
  
  lcd.setCursor(0,0);
lcd.print(stopMinuite);
lcd.print(":");
if (stopSecond > 9){
lcd.print(stopSecond);}
else{
  lcd.print("0");
  lcd.print(stopSecond);}


if((digitalRead(button3) == HIGH) && (Latch == 0))
{
   Latch = 1 ;
  theTime = (millis()/(1000));
    digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
  delay(100);
}

if( Latch == 1)
{

   stopSecond = (millis()/(1000)) - theTime ;  

}
//if(digitalRead(button2 == HIGH)){
//Latch = 0;}


if(digitalRead(button2) == HIGH)
{  
  Latch = 0; 
  digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
  delay(100);
 // stopSecond = 0;
 // stopMinuite = 0;
}


if(digitalRead(button1) == HIGH)
{  
x = -1;
}
}
}

