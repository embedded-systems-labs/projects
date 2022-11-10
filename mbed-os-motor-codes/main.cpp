#include "DigitalOut.h"
#include "PwmOut.h"
#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
    DigitalOut out1 (D2);
    DigitalOut out2 (D3);
    DigitalOut out3 (D4);
    DigitalOut out4 (D5);
    PwmOut ENA (D10);
    PwmOut ENB (D11);
    ENA.period(0.9);
    ENA = 0.9;
    ENB.period(0.9);
    ENB = 0.9;

    while (true) {
        out1 = 1; //left motor
        out2 = 0; //left motor
        out3 = 0; // right motor
        out4 = 1; // right motor
    }
}

