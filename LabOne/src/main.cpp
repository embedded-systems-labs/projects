// mbed code that outputs the values of a single digit internal counter i on a 7-segment display running on NUCLEO-F411RE

#include "mbed.h"

/*
Implement an mbed code that output the values of a single digit internal counter i on a 7-segment display.
Each value must remain on the display for 5 sec before moving to the next value.
Prior to displaying the counter values, your code should display the word “START” where
each character will be displayed on the 7-segemnt for 2 sec before moving to the next character.
After the word “START” is displayed your internal counter will start displaying on values on the 7-segment in order.
Finally, the word “STOP” will be outputted on the 7-segment display indicating the end of the counter.
*/
// Define the pins used for the 7-segment display
DigitalOut a(D7);
DigitalOut b(D8);
DigitalOut c(D2);
DigitalOut d(D3);
DigitalOut e(D4);
DigitalOut f(D5);
DigitalOut g(D6);

void start()
{
    // Display the word "START" on the 7-segment display
    // Each character will be displayed on the 7-segment for 2 sec before moving to the next character
    // Prior to displaying the counter values, your code should display the word “START” where
    // each character will be displayed on the 7-segemnt for 2 sec before moving to the next character.
    // Define the pins used for the 7-segment display

    // Display the letter S
    a = 1;
    b = 0;
    c = 1;
    d = 1;
    e = 0;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter T
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter A
    a = 1;
    b = 1;
    c = 1;
    d = 0;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter R
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 1;
    f = 0;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter T
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);
}
void count()
{
    // Display the values of a single digit internal counter i on a 7-segment display
    // Each value must remain on the display for 5 sec before moving to the next value.

    // Display the value 0
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 1;
    f = 1;
    g = 0;
    ThisThread::sleep_for(5000ms);

    // Display the value 1
    a = 0;
    b = 1;
    c = 1;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    ThisThread::sleep_for(5000ms);

    // Display the value 2
    a = 1;
    b = 1;
    c = 0;
    d = 1;
    e = 1;
    f = 0;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 3
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 0;
    f = 0;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 4
    a = 0;
    b = 1;
    c = 1;
    d = 0;
    e = 0;
    f = 1;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 5
    a = 1;
    b = 0;
    c = 1;
    d = 1;
    e = 0;
    f = 1;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 6
    a = 1;
    b = 0;
    c = 1;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 7
    a = 1;
    b = 1;
    c = 1;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    ThisThread::sleep_for(5000ms);

    // Display the value 8
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(5000ms);

    // Display the value 9
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 0;
    f = 1;
    g = 1;
    ThisThread::sleep_for(5000ms);
}
void stop()
{
    // Display the word "STOP" on the 7-segment display
    // Each character will be displayed on the 7-segment for 2 sec before moving to the next character
    // Define the pins used for the 7-segment display

    // Display the letter S
    a = 1;
    b = 0;
    c = 1;
    d = 1;
    e = 0;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter T
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);

    // Display the letter O
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 1;
    f = 1;
    g = 0;
    ThisThread::sleep_for(2000ms);

    // Display the letter P
    a = 1;
    b = 1;
    c = 0;
    d = 0;
    e = 1;
    f = 1;
    g = 1;
    ThisThread::sleep_for(2000ms);
}

// main() runs in its own thread in the OS
int main()
{
    while (true)
    {
        start();
        count();
        stop();
    }
}
