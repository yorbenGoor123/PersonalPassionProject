/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;
Servo myservo2;
Servo myservo3;// create servo object to control a servo
// twelve servo objects can be created on most boards

int ledPinServo1 = 11;
int ledPinServo2 = 12;
int ledPinServo3 = 7;



void setup() {
  Serial.begin(19200);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(8);
  myservo3.attach(10);
  pinMode(ledPinServo1, OUTPUT);
  pinMode(ledPinServo2, OUTPUT);
  pinMode(ledPinServo3, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
   int randomNumber = random(0,3);
   //Serial.print(randomChoice);
   
    myservo.write(0);
    myservo2.write(0);
    myservo3.write(0);

    if(randomNumber == 0) {
      digitalWrite(ledPinServo1, HIGH);
      delay(1500);
      myservo.write(180);
      delay(1000);
      myservo.write(0);
      digitalWrite(ledPinServo1, LOW);
    }

    if(randomNumber == 1) {
      digitalWrite(ledPinServo2, HIGH);
      delay(1500);
      myservo2.write(180);
      delay(1000);
      myservo2.write(0);
      digitalWrite(ledPinServo2, LOW);
    }

    
    if(randomNumber == 2) {
      digitalWrite(ledPinServo3, HIGH);
      delay(1500);
      myservo3.write(180);
      delay(1000);
      myservo3.write(0);
      digitalWrite(ledPinServo3, LOW);
    }
    

}
