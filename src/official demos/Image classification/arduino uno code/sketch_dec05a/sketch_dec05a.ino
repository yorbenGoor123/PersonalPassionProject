
#include <Wire.h>
#define BAUD_RATE 19200
#define CHAR_BUF 128
#include <Servo.h>

int ledPin = 11;
bool isGreen = false;

Servo servo_1;  
Servo servo_2;

void setup() {

   pinMode(ledPin, OUTPUT);
 servo_1.attach(6);
 servo_2.attach(5);
 Serial.begin(BAUD_RATE);
 Serial.print("Test");
 Wire.begin();

 delay(1000);
 

}

void loop() {

 int32_t temp = 0;
 char buff[CHAR_BUF] = {0};

  servo_1.write(90);
  servo_2.write(90);

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
  isGreen = false;
  servo_1.write(90);
  servo_2.write(90);
  delay(200); 
  
     
 }

 if (mystring.startsWith("g"))
 {
  Serial.print("it's green!"); 
      isGreen = true;
      if(isGreen == true) {
        servo_1.write(95); 
        servo_2.write(85);
      }
      delay(200);  
 }
}
