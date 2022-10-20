#include "mbed.h"
//mbed program that allows a user to control the speed of a servo via potentiometer.
//use PWM and analog pins to implement the circuit
// main() runs in its own thread in the OS

AnalogIn Ain(A5);
PwmOut PWM(D9);
// main() runs in its own thread in the OS
int main()
{
    PWM.period(200);
    while(1){
        PWM = Ain;
    }
}