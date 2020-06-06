#include "Particle.h"
#include "dct.h"
#include <Wire.h>
#define Address 0x05


int Val;
int LedBlue = A2;
int LedRed = A0;


void setup() {

    pinMode(LedBlue, OUTPUT);

    pinMode(LedRed, OUTPUT);


    Wire.begin(Address);
    Wire.onReceive(DataRec);

}




 void DataRec(int Val){

    Val = Wire.read();
}


void loop() {

    Val = Wire.read();

    if (Val == 0){



        Particle.publish("Temp", "is perfect");
        digitalWrite(LedBlue, HIGH);
             delay(4000);
        digitalWrite(LedBlue, LOW);
            delay(900);


    }
    else if (Val == 1)
    {

        Particle.publish("Temp", "is not perfect");
       digitalWrite(LedRed, HIGH);
            delay(4000);
       digitalWrite(LedRed, LOW);
            delay(900);

    }

   delay(5000);
}
