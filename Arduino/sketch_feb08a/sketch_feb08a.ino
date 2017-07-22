#include <LEDDisplay.h>
//a b c d e f g /dp
//B11111100,0
//B01100000,1
//B11011010,2
//B11110010,3
//B01100110,4
//B10110110,5
//B00111111,6
//B11100000,7
//B11111110,8
//B11100110,9

LEDDisplay *led;  
int millisecondsPerCount;  
int timer;  
unsigned long lastUpdate;

void setup()  
{
 millisecondsPerCount = 1000;
 int driverPins[] = {11, 12}; //sets the output flagpins
 int Pins[] = {2, 3, 4, 5 ,6 ,7 ,8, 9};
 int decimalPointPin = 9;
 led = new LEDDisplay(2, driverPins, Pins, decimalPointPin);
}

void loop()  
{
 unsigned long now = millis();
 if (now - lastUpdate > millisecondsPerCount)
{
 lastUpdate = now;
 timer++;
 if (timer == 100)
{
 timer = 0;
}
}

 int number = timer;
 for(int x = 0; x < 2; x++)
{
 led->displayNumber(number % 10, x);
 delay(2);
 number = number / 10;
}
}
