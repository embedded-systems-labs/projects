#include "mbed.h"


SPI ser_port(p11, p12, p13); //mosi, miso, sclk
char switch_word; //word we will send
// main() runs in its own thread in the OS
int main()
{
    ser_port.format(8, 0);
    ser_port.frequency(1000000);
    while(1){
        switch_word = 0xA1;
        ser_port.write(switch_word);
        wait_us(50);
    }
}

