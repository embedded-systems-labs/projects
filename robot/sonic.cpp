#include "mbed.h"
//VCC must have 5 volts
//GND must connect to ground
//Trigger recieves 1 or 0 from output
//Echo returns value based on time to recieve sound

//Echo can be either Digital or Analog
//Trigger must be activated for 10 us
//Echo must have around 1 or 2 milliseconds to recieve
//If Echo does not recieve appropriate time returned data will be off
//L476rg can handle 5 volt input(from what I have tested and read)

DigitalOut trigger(D7);
DigitalIn echo(D6);
DigitalOut led_Close(D4);
DigitalOut led_Far(D3);
int main()
{
    trigger = 0;
    while (1) {
        trigger = 1;
        wait_us(10);
        trigger = 0;
        wait_us(1000);
        if (echo.read() == 1) {
        led_Close = 1;
        led_Far = 0;
        }
        else {
        led_Far = 1;
        led_Close = 0;
        }
        wait_us(100000);
    }
}