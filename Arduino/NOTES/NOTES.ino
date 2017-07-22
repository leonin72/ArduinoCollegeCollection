// Buzzer example function for the CEM-1203 buzzer (Sparkfun's part #COM-07950).
// by Rob Faludi
// http://www.faludi.com

// Additions by Christopher Stevens
// http://www.christopherstevens.cc

void setup() {
    pinMode(4, OUTPUT); // set a pin for buzzer output
}

void loop() {
    buzz(4, 996, 1000); //pin, note frequency, play length in miliseconds
    buzz(4, 1050, 1000);
    buzz(4, 1110, 1000);
    buzz(4, 1180, 1000);
    buzz(4, 1250, 1000);
    buzz(4, 1320, 1000);
    buzz(4, 1400, 1000);
    buzz(4, 1490, 1000);
    buzz(4, 1580, 1000);
    buzz(4, 1670, 1000);
    buzz(4, 1770, 1000);
    buzz(4, 1870, 1000);
    delay(1000); // wait a bit between buzzes
}

void buzz(int targetPin, long frequency, long length) {
    long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
    //// 1 second's worth of microseconds, divided by the frequency, then split in half since
    //// there are two phases to each cycle
    long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
    //// multiply frequency, which is really cycles per second, by the number of seconds to 
    //// get the total number of cycles to produce
    for (long i=0; i < numCycles; i++){ // for the calculated length of time...
        digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
        delayMicroseconds(delayValue); // wait for the calculated delay value
        digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
        delayMicroseconds(delayValue); // wait againf or the calculated delay value
    }
}
