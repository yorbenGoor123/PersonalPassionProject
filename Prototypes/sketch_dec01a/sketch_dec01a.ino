#include <Wire.h>
#define BAUD_RATE 19200
#define CHAR_BUF 128
#include <Servo.h>

int ledPin = 11;      // select the pin for the LED

int pos_value_1 = 0;
int pos_value_2 = 0;
int pos_value_3 = 0;

int X_value = 0;  // center x
int Y_value = 0;  // center Y
int box_value = 0;  // Size box (distance)

int x_pos = 90;
int y_pos = 90;

Servo servo_x;  
Servo servo_y;  
 
void setup() {

 pinMode(ledPin, OUTPUT);
 servo_x.attach(5);
 servo_y.attach(6);
 Serial.begin(BAUD_RATE);
 Serial.print("Test");
 Wire.begin();
 
 delay(1000); // Give the OpenMV Cam time to bootup.
}

void loop() 
{

 servo_x.write(90);
 servo_y.write(90);
 int32_t temp = 0;
 char buff[CHAR_BUF] = {0};

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
     while(Wire.available()) Wire.read(); // Toss garbage bytes.
   }   
 }
 
 else 
 {
   while(Wire.available()) Wire.read(); // Toss garbage bytes.
 }

 


 String mystring(buff); // convert to string
  //---------------------------------------------------------------------------------------------- POS 1 (X)
 if (mystring.startsWith("POS_1"))  // check start of string
 {
  //Serial.println("POS 1 detected");   
  String pos1 = mystring.substring(8);  // substring of last part, from position 8
  pos_value_1 = pos1.toInt();           // substring to integer value
  //Serial.println(pos_value_1);
 }




 //***************************************************************************************************************************** X and Y

 X_value = pos_value_1 + (box_value / 2);
 Y_value = pos_value_2 + (box_value / 2);
 

 //*****************************************************************************************************************************************


  if (X_value >= 135)     // Head right
  {
    servo_x.write(180);
    //move_right();  // move right
    Serial.print(X_value);
    delay(15);
    
  }

  if (X_value <= 105)     // Head left
  {
    //move_left();  // move left
     //delay(15);
    //Serial.print("hello world");
    servo_x.write(180);
  }
 

}
//-------------------------------------------------------------------------------
void move_right()
{  
    servo_x.write(180);
}

void move_left()
{
    servo_x.write(0);
}
 
