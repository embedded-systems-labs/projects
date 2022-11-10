#include "mbed.h"
#include "Servo.h"
#include "USBSerial.h"
#include "ultrasonic.h"
#define HIGH 1
#define LOW 0



void forward();
void backward();
void right();
void left();
void stop();
void loop();

int distance; // Variable to store distance from an object
int checkRight;
int checkLeft;
int function =
    1; // Variable to store function of robot: '1' running or '0' stoped. By
int pos = 90;

USBSerial pc(USBTX, USBRX);
PwmOut servo(D6);

ultrasonic::ultrasonic(A4, A5);

// Variables

int main() {

  while (1) {
    loop();
  }
}

void forward() {

  pc.printf("fwd");
  DigitalOut(D13, 0);
  DigitalOut(D12, 1);
  DigitalOut(D9, 1);
  DigitalOut(D8, 0);
}

void backward() {
  DigitalOut(D13, 1);
  DigitalOut(D12, 0);
  DigitalOut(D9, 0);
  DigitalOut(D8, 1);
}

void right()

{

  DigitalOut(D13, 0);
  DigitalOut(D12, 1);
  DigitalOut(D9, 0);
  DigitalOut(D8, 1);
}

void left()

{

  DigitalOut(D13, 1);
  DigitalOut(D12, 0);
  DigitalOut(D9, 1);
  DigitalOut(D8, 0);
}

void stop()

{

  DigitalOut(D13, 0);
  DigitalOut(D12, 0);
  DigitalOut(D9, 0);
  DigitalOut(D8, 0);
}

void loop()

{

  servo.period(0.020);
  usensor.start();
  wait_us(500);
  distance =usensor.get_dist_cm(); // Tip: Use 'CM' for centimeters or 'INC' for inches
  pc.printf("Dist: %d ", distance);
  // Check for objects...
  if (distance > 10) {
    pc.printf(" No Object \n");
    forward(); // All clear, move forward!
    // noTone(buzzer);
    // digitalOut LED(0);
  } else if (distance <= 10) {
    pc.printf("Halt - Object on the Way \n");
    stop();

    for (float offset = 0.0016; offset <= 0.0027;
         offset += 0.0001) // turning RIGHT

    {

      pc.printf("Turning Right");

      servo.pulsewidth(
          offset); // servo position determined by a pulsewidth between

      wait(0.10);
    }

    wait(2); // stopping at RIGHTMOST position for 2 seconds

    usensor.start();

    wait_ms(500);

    checkRight = usensor.get_dist_cm(); // Take distance from the left side

    pc.printf("DistL: %d ", checkLeft);

    for (float offset = 0.0027;
         offset >= 0.0016;) // turning back to theCENTER position
    {
      pc.printf("Turning Center");

      servo.pulsewidth(
          offset); // servo position determined by a pulsewidth between

      wait(0.10);
      offset = offset - 0.0001;
    }

    wait(2);

    for (float offset = 0.0016; offset >= 0.0009;
         offset = offset - 0.0001) // Turning towards LEFT

    {

      pc.printf("Turning Left");
      servo.pulsewidth(
          offset); // servo position determined by a pulsewidth between

      wait(0.10);
    }

    wait(2); // stopping at LEFTMOST position for 2

    usensor.start();

    wait_ms(500);

    checkLeft = usensor.get_dist_cm();

    pc.printf("DistR: %d ", checkRight);

    for (float offset = 0.0009; offset <= 0.0016; offset = offset + 0.0001)

    {
      pc.printf("Turning Center");

      servo.pulsewidth(
          offset); // servo position determined by a pulsewidth between

      wait(0.10);
    }

    // Finally, take the right decision, turn left or right?

    if (checkLeft < checkRight) {

      left();

      wait_ms(400);

      // wait_ms, change value if necessary to make robot turn.
      forward();
    }

    else if (checkLeft > checkRight) {

      right();

      wait_ms(400);
      forward();
      // wait_ms, change value if necessary to make robot turn.

    }

    else if (checkLeft <= 10 && checkRight <= 10) {

      backward(); // The road is closed... go back and then left ;)

      left();
      forward();
    }
  }
}