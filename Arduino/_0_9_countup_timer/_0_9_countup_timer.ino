/*
    Project Title: 0-9 counter using 7 segment display
    Link: www.newtechandme.com
    Uses e-gizmo's development board

    Connection
    Arduino pin    7 segment
        2              a
        3              b
        4              c
        5              d
        6              e
        7              f
        8              g
        9              dp(dot pin)
        10             digit 0
        11             digit 1
*/

//initialize the pins
byte digit0 = 10;   //           a
byte digit1 = 8;   //        =======
byte dotPin = 18;    //      ||       ||
byte a = 11;         //    f ||       || b
byte b = 12;         //      ||   g   ||
byte c = 13;         //        =======
byte d = 14;         //      ||       ||
byte e = 15;         //    e ||       || c
byte f = 16;         //      ||   d   ||
byte g = 17;         //        =======
int x;
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(digit0, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(dotPin, OUTPUT);

  digitalWrite(dotPin, LOW); //disable dotpin
  digitalWrite(digit1, LOW); //disable digit1
}

void loop()
{
 digitalWrite(digit1, HIGH); //enable the first digit
 //write the numbers by sending a low signal to the segments
 // write '0'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, HIGH);
 digitalWrite(f, HIGH);
 digitalWrite(g, LOW);
 delay(1000); //put 1 second delay before the next number

 // write '1'
 digitalWrite(a, LOW);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, LOW);
 digitalWrite(e, LOW);
 digitalWrite(f, LOW);
 digitalWrite(g, LOW);
 delay(1000);

 // write '2'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, LOW);
 digitalWrite(d, HIGH);
 digitalWrite(e, HIGH);
 digitalWrite(f, LOW);
 digitalWrite(g, HIGH);
 delay(1000);

 // write '3'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, LOW);
 digitalWrite(f, LOW);
 digitalWrite(g, HIGH);
 delay(1000);

 // write '4'
 digitalWrite(a, LOW);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, LOW);
 digitalWrite(e, LOW);
 digitalWrite(f, HIGH);
 digitalWrite(g, HIGH);
 delay(1000);

 // write '5'
 digitalWrite(a, HIGH);
 digitalWrite(b, LOW);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, LOW);
 digitalWrite(f, HIGH);
 digitalWrite(g, HIGH);
 delay(1000);

 // write '6'
 digitalWrite(a, HIGH);
 digitalWrite(b, LOW);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, HIGH);
 digitalWrite(f, HIGH);
 digitalWrite(g, HIGH);
 delay(1000);

// write '7'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, LOW);
 digitalWrite(e, LOW);
 digitalWrite(f, LOW);
 digitalWrite(g, LOW);
 delay(1000);

 // write '8'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, HIGH);
 digitalWrite(f, HIGH);
 digitalWrite(g, HIGH);
 delay(1000);

 // write '9'
 digitalWrite(a, HIGH);
 digitalWrite(b, HIGH);
 digitalWrite(c, HIGH);
 digitalWrite(d, HIGH);
 digitalWrite(e, LOW);
 digitalWrite(f, HIGH);
 digitalWrite(g, HIGH);
 delay(1000);
}
