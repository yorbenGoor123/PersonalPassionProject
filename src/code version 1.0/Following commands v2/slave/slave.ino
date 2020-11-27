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
int tonePin = 2;
int delaySong = 300;
int delayChoice = 300;
int bopItChoice;


Servo myservo;
Servo myservo2;
// create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(6);
  myservo2.attach(5);// attaches the servo on pin 9 to the servo object
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void receiveEvent(int bytes) {
  x = Wire.read();
 // read one character from the I2C
}

void loop() {

  myservo.write(90);
  myservo2.write(90);

    int randomChoice = random(10,12);
    //Serial.print(randomChoice);
 

    if(randomChoice == 10) {
      //Serial.print("left and right");
      leftRight();
       
       
    }

    if(randomChoice == 11) {
      //Serial.print("Up and down"); 
      upDown();
       
    }

    delay(200);

    backgroundSong(); 

    delay(200);
    

    if(randomChoice == x) {
      Serial.print("you win!");
      delaySong = delaySong - 20;
    }else {
      Serial.print("you lose!");
      delaySong = 300;
    }
    
}

void backgroundSong() {
tone(tonePin, 329, 225.0);
    delay(delaySong);
    tone(tonePin, 220, 225.0);
    delay(delaySong);
    tone(tonePin, 261, 112.5);
    delay(delaySong);
    tone(tonePin, 293, 112.5);
    delay(delaySong);
    tone(tonePin, 329, 225.0);
    delay(delaySong);
    tone(tonePin, 220, 225.0);
    delay(delaySong);
    tone(tonePin, 261, 112.5);
    delay(delaySong);
    tone(tonePin, 293, 112.5);
    delay(delaySong);
    tone(tonePin, 329, 225.0);
    delay(delaySong);
    tone(tonePin, 220, 225.0);
    delay(delaySong);
    tone(tonePin, 261, 112.5);
    delay(delaySong);
    tone(tonePin, 293, 112.5);
    delay(delaySong);
    tone(tonePin, 329, 225.0);
    delay(delaySong);
    tone(tonePin, 220, 225.0);
    delay(delaySong);
    tone(tonePin, 261, 112.5);
    delay(delaySong);
    tone(tonePin, 293, 112.5);
    delay(delaySong);
    tone(tonePin, 329, 225.0);
    delay(delaySong);
}

void leftRight() {
    tone(tonePin, 115, 225.0);
    delay(delayChoice);
    tone(tonePin, 240, 225.0);
    delay(delayChoice);
}

void upDown() {
    tone(tonePin, 300, 225.0);
    delay(delayChoice);
    tone(tonePin, 143, 225.0);
    delay(delayChoice);
}
