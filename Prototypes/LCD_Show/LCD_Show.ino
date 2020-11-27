#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

#include <Servo.h>
#include <Wire.h>

int y = 0;
int receive = 0;

int tonePin = 2;

Servo myservo;
Servo myservo2;

void setup()
{

  myservo.attach(6);
  myservo2.attach(5);// attaches the servo on pin 9 to the servo object
  Wire.begin(9);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);
  Config_Init();
  LCD_Init();
  LCD_Clear(WHITE);
  LCD_SetBackLight(80);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
  Paint_SetRotate(0);
  //Paint_DrawString_EN(30, 10, "123", &Font24, YELLOW, RED);
  //Paint_DrawString_EN(30, 34, "ABC", &Font24, BLUE, CYAN);
  //Paint_DrawString_CN(50,180, "微雪电子",  &Font24CN, WHITE, RED);
  //Paint_DrawRectangle(125, 10, 225, 58, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  //Paint_DrawLine(125, 10, 225, 58, MAGENTA, LINE_STYLE_SOLID, DOT_PIXEL_2X2);
  //Paint_DrawLine(225, 10, 125, 58, MAGENTA, LINE_STYLE_SOLID, DOT_PIXEL_2X2);
  
  //Paint_DrawCircle(150,100, 25, BLUE,  DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  //Paint_DrawCircle(180,100, 25, BLACK,    DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  //Paint_DrawCircle(210,100, 25, RED, DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  //Paint_DrawCircle(165,125, 25, YELLOW,   DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  //Paint_DrawCircle(195,125, 25, GREEN,   DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
  //Paint_DrawImage(gImage_70X70, 20, 80, 70, 70); 

}

void receiveEvent(int bytes) {
  receive = Wire.read();
 
}

void loop()
{


    myservo.write(90);
    myservo2.write(90);

    Serial.begin(receive);


    
    
    if(receive == 1 ) {

      myservo.write(95); 
      myservo2.write(85);
      
      
    }

    if(receive == 1) {
     y = 225;
    tone(tonePin, y, 225.0);
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    delay(250.0);
    Paint_Clear(WHITE);
    y = 100;
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
    
    tone(tonePin, y, 225.0);
    delay(250);
    Paint_Clear(WHITE);

    delay(10000);
    }

    if(receive == 0) {
      myservo.write(90);
      myservo2.write(90);
      delay(200);
    }

    if(receive == 2) {
      myservo.write(90);
      myservo2.write(85);
      delay(200);
    }

    if(receive == 2) {
     y = 100;
    tone(tonePin, y, 225.0);
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    delay(250.0);
    Paint_Clear(WHITE);
    y = 177;
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
    
    tone(tonePin, y, 225.0);
    delay(250);
    Paint_Clear(WHITE);

    delay(10000);
    }

    if(receive == 3) {
      myservo.write(95);
      myservo2.write(90);
      delay(200);
    }

    if(receive == 3) {
     y = 232;
    tone(tonePin, y, 225.0);
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    delay(250.0);
    Paint_Clear(WHITE);
    y = 140;
    Paint_DrawRectangle(220, 10, 150, y, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
    
    tone(tonePin, y, 225.0);
    delay(250);
    Paint_Clear(WHITE);

    delay(10000);
 }
  
   
}

void speechControl() {
  

}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
