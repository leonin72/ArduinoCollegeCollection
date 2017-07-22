#include <LiquidCrystal.h>   
#include <math.h>
//Variable for Gas
float Rs = 0;
float Ro = 0;
float a = 0;
float b = 0;
double result = 0;
float volt = 0;
float GasValue = 0;
float ratio = 0;   
//Variable for Temp               
float tempC = 1;                                                 // Variable for holding Celcius temp (floating for decimal points precision)
float tempf = 1;                                                 // variable for holding Fareghneit temp
int tempPin = 1;                                                 // Declaring the Analog input to be 1 (A1) of Arduino boarzd.
float samples[8];                                                // Array to hold 8 samples for Average temp calculation

int i;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                          



void setup()
{
Serial.begin(9600);                                           // Opens serial port and sets data rate to 9600 bps

lcd.begin(16, 2);                                            // Set up the LCD's number of columns and rows:
lcd.setCursor(2, 0);                                         // Set LCD cursor position (column, row)
lcd.print("Ian Ratio");                                      // Print text to LCD
lcd.setCursor(0, 1);                                            // Set LCD cursor position (column,row) 
lcd.print("Paolo Paraiso");                                       // Print text to LCD
delay(3000);                                   
lcd.clear();                                                 // Clear the display
lcd.setCursor(2, 0);                                            // Set LCD cursor position (column, row)
lcd.print("Thermometer");                                     // Print text to LCD
lcd.setCursor(1, 1);                                            // Set LCD cursor position (column, row) 
lcd.print(" Gas Sensor ");                                   // Print text to LCD                                                                                                                                                                                                                                                                                                                                                                                                                       
delay(3000);                                                    // Delay to read text
lcd.clear();                                                    // Clear LCD

 for (i=0;i<50;i++)
  {
    lcd.setCursor(2, 0);                                           
    lcd.print("Calibrating"); 
    a = analogRead(GasValue);
  
    Ro += 12*(1023-a)/a;
    delay(500);
  }
  
  Ro = Ro/50;
  Ro = Ro/9.5;
  lcd.clear();
  Serial.print("Ro:");
  Serial.print(Ro);
  Serial.println("");
}



void loop()
{
Serial.println("New measurement:");
b = analogRead(GasValue);
Rs = 12*(1023-b)/b;

float preResult = (((((log10(Rs/Ro)) - 0.47)/(-0.37))) + 2.30);

result = pow(10.0, preResult);
ratio = log10(Rs/Ro);
lcd.setCursor(0, 1);
lcd.print("Gas: ");
lcd.print(result);
lcd.print("PPM ");
volt = (5*b)/1023;

Serial.print("Gas Value = " );  
Serial.print(result); 
Serial.print("PPM");  
Serial.println("");
Serial.println(""); 
Serial.print("Rs");     
Serial.print(Rs);
Serial.print("Kohms");  
Serial.println("");  
Serial.print("log(Rs/Ro):");
Serial.print(ratio);  
Serial.println(""); 
Serial.print("Voltage at load:");
Serial.print(volt);
Serial.print( "V");
Serial.println("");  
Serial.print("PreResult:");
Serial.print(preResult);  
Serial.println(""); 
Serial.println("");   
delay(200);    


  

Serial.print("LM35 Raw data: ");                               
Serial.println(analogRead(tempPin));                           // Displays on serial monitor the sampled value before conversion to real Temperature reading
 
                                                               
for(i = 0;i<=7;i++){                                           // gets 8 samples of temperature
samples[i] = ( 4.4 * analogRead(tempPin) * 100.0) / 1024.0;    // conversion math of LM35 sample to readable temperature and stores result to samples array. 
delay(20);
                                                               // 5v is the supply volts of LM35. Change appropriatelly to have correct measurement. My case is 4.4Volts.
                                                               // If powered from USB then use value 4.4v to 4.6v. If power is 7v< to the Arduino then use 4.9v to 5.1v                                                                
                                                               // The voltage is critical for accurate readings
Serial.println(samples[i]);                                    // Print samples [i] to serial monitor                                            
                                                                                                                        
                                                               
tempC += samples[i];                                    // do the addition for average temperature

}                                                            

Serial.println("");                                            // Blank line for spacing in the serial monitor

tempC = tempC/8.0;                                             // calculated the averare of 8 samples in Celcius

tempf = (tempC * 9)/ 5 + 32;                                   // converts to fahrenheit



                                                               

Serial.print("Average Temperature in Celcius is " );          
Serial.println(tempC);                                        
Serial.print("Average Temperature in Farenhiet is " );         
Serial.println(tempf);                                         
Serial.println("");                                         
Serial.println("");   


 lcd.setCursor(0, 0);                                           // Set LCD cursor position (column 0, row 0)
 lcd.print(tempC);                                         // print current Temp sample to LCD
 lcd.setCursor(5, 0);                                           // Set LCD cursor position (column 0, row 0)
 lcd.print("C");                                         // print current Temp sample to LCD
  
 lcd.setCursor(9, 0);                                           // Set LCD cursor position (column 0, row 0)
 lcd.print(tempf);                                       // print current Temp sample to LCD
 lcd.setCursor(15, 0);                                  // Set LCD cursor position (column 0, row 0)
 lcd.print("F");                                       // print current Temp sample to LCD
 delay(500);                                          // Send the data to the LCD
  
 tempC = 0;                                         // Set tempC to 0 so calculations can be done again
 
}
