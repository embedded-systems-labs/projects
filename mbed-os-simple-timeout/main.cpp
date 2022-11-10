#include "mbed.h"

#define TIME 1 // Time for toggle the LED (seconds)

DigitalOut led(D3); // Create the LED object and setup OFF
Timeout timeout;    // Create the Timeout object

void timer_interrupt()
{
    led = !led;                           // Toggle the LED state
    timeout.attach(&timer_interrupt, 2s); // Set again the timer timeout for next iterations
}

int main()
{
    timeout.attach(&timer_interrupt, 2s); // Set the timer interrupt service rutine (ISR) and the time for the timeout (in seconds)
    while (1)
        ; // Infinite loop
}