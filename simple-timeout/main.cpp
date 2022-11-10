#include "mbed.h"

Timeout Response;

DigitalOut led1(D3);

void blink(){
    led1 = 1;
    wait_us(1000);
}

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        Response.attach(&blink,2s);
    }
}

