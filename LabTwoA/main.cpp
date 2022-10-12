#include "mbed.h"
//Pulse Width Modulators for each LED
PwmOut LEDA(D3);
PwmOut LEDB(D5);
PwmOut LEDC(D6);zsa

// main() runs in its own thread in the OS
int main()
{
    //set period for each PWM
    LEDA.period_ms(500);
    LEDA = 0.5;
    LEDB.period_ms(1000);
    LEDB = 0.5;
    LEDC.period_ms(2000);
    LEDC = 0.5;
}

