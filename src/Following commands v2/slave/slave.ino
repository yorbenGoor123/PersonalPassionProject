/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

#include <Wire.h>

int x = 0;

Servo myservo;
Servo myservo2;
// create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(9);
  myservo2.attach(8);// attaches the servo on pin 9 to the servo object
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent(int bytes) {
  x = Wire.read();
 // read one character from the I2C
}

void loop() {

  Serial.print(x);
    
    myservo.write(90);
    myservo2.write(90);
    

    if(x == 1 ) {
      myservo.write(92); 
      myservo2.write(88);
    }

    if(x == 0) {
      myservo.write(90);
      myservo2.write(90);
    }

    if(x == 2) {
      myservo.write(90);
      myservo2.write(88);
    }

    if(x == 3) {
      myservo.write(92);
      myservo2.write(90);
    }
    
}
