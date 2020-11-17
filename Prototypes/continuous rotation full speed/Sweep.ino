/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;
//Servo myservo2;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(9);
  //myservo2.attach(8)// attaches the servo on pin 9 to the servo object
}

void loop() {
  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(180);
   

}
