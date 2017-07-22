int a=11;
int b=12;
int c=13;
int d=14;
int e=15;
int f=16;
int g=17;
int x=10;
int y=8;
int z=7;
int del=125;

void setup()                      // run once, when the sketch starts
{
  pinMode(a, OUTPUT);        // sets the digital pin as output
  pinMode(b, OUTPUT);  // sets the digital pin as output
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);        // sets the digital pin as output
  pinMode(e, OUTPUT);  // sets the digital pin as output
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);        // sets the digital pin as output
  pinMode(x, OUTPUT);  // sets the digital pin as output
  pinMode(y, OUTPUT);
  pinMode(z, OUTPUT);        // sets the digital pin as output
}
void loop()                       // run over and over again
{digitalWrite(x,HIGH);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
digitalWrite(d,HIGH);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(g,LOW);
delay(del);
digitalWrite(x,LOW);
delay(del);
digitalWrite(y,HIGH);
digitalWrite(a,HIGH);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
digitalWrite(g,HIGH);
digitalWrite(d,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
delay(del);
digitalWrite(y,LOW);
delay(del);
digitalWrite(z,HIGH);
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
delay(del);
digitalWrite(z,LOW);
delay(del);
digitalWrite(x,HIGH);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
digitalWrite(d,HIGH);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(g,LOW);
delay(del);
digitalWrite(x,LOW);
delay(del);
digitalWrite(y,HIGH);
digitalWrite(a,HIGH);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
digitalWrite(g,HIGH);
digitalWrite(d,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
delay(del);
digitalWrite(y,LOW);
delay(del);
digitalWrite(z,HIGH);
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
delay(del);
digitalWrite(z,LOW);
delay(del);

digitalWrite(x,HIGH);
digitalWrite(f,LOW);
digitalWrite(e,HIGH);
digitalWrite(d,LOW);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(g,HIGH);
delay(del);
digitalWrite(x,LOW);
delay(del);
digitalWrite(y,HIGH);
digitalWrite(a,LOW);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
digitalWrite(g,LOW);
digitalWrite(d,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
delay(del);
digitalWrite(y,LOW);
delay(del);
digitalWrite(z,HIGH);
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
delay(del);
digitalWrite(z,LOW);
delay(del);
}

