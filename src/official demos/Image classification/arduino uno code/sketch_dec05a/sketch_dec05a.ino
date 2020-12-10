
#include <Wire.h>
#define BAUD_RATE 19200
#define CHAR_BUF 128
#include <Servo.h>

int ledPin = 11;
int IRSensor = 4; // connect ir sensor to arduino pin 2

Servo servo_1;  
Servo servo_2;

void setup() {

 pinMode(ledPin, OUTPUT);
 pinMode (IRSensor, INPUT); // sensor pin INPUT
 servo_1.attach(6);
 servo_2.attach(5);
 Serial.begin(BAUD_RATE);
 Serial.print("Test");
 Wire.begin();
 randomSeed(analogRead(0));

 delay(1000);
 

}

void loop() {


 int32_t temp = 0;
 char buff[CHAR_BUF] = {0};

  //servo_1.write(90);
  //servo_2.write(90);


Wire.requestFrom(0x12, 2);

 if(Wire.available() == 2) 
 { // got length?

   temp = Wire.read() | (Wire.read() << 8);
   delay(1); // Give some setup time...

   Wire.requestFrom(0x12, temp);
   if(Wire.available() == temp) 
   { // got full message?
     temp = 0;
     while(Wire.available()) buff[temp++] = Wire.read();

   } 
   
   else 
   {
     while(Wire.available()) Wire.read();
   }   
 }
 
 else 
 {
   while(Wire.available()) Wire.read(); 
 }

 String mystring(buff);
 if (mystring.startsWith("r")) 
 {
  Serial.print("it's red!");
  servo_1.write(90);
  servo_2.write(90);
  
  
     
 }


 if (mystring.startsWith("g"))
 {
  Serial.print("it's green!"); 
      servo_1.write(95); 
      servo_2.write(85);
      delay(200);  
 }

  if (mystring.startsWith("e"))
 {
  Serial.print("evading!"); 
      servo_1.write(90); 
      servo_2.write(85);
      delay(200);

 }


   if (mystring.startsWith("n"))
 {
  Serial.print("normal!"); 
    int statusSensor = digitalRead (IRSensor);
    int randomChoice = random(0,2);
  
  if (statusSensor == 1) {
      servo_1.write(95); 
      servo_2.write(85);
      delay(200);
  }
  else
  {
    if(randomChoice == 0) {
      servo_1.write(85); 
      servo_2.write(90);
      delay(1500);
     }

     if(randomChoice == 1) {
      servo_1.write(90); 
      servo_2.write(95);
      delay(1500);
     }
  }
      

 }

}
