#include <SPI.h>
#include <Servo.h>
#include <Wire.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"


int x = 0;
int tonePin =2;
int delaySong = 300;
int delayChoice = 300;
int bopItChoice;

int receivedValue = 0;


  Servo myservo;
  Servo myservo2;

void setup()
{
  myservo.attach(6);
  myservo2.attach(5);

  Serial.begin(115200);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  
  randomSeed(analogRead(0));
  Config_Init();
  LCD_Init();
  LCD_Clear(WHITE);
  LCD_SetBackLight(80);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
  Paint_SetRotate(90);
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
  receivedValue = Wire.read();
 // read one character from the I2C
}


void loop()
{
  //Serial.print(receivedValue);

    myservo.write(90);
    myservo2.write(90);


  if(receivedValue == 1 || receivedValue == 2 || receivedValue == 3 || receivedValue == 4 || receivedValue == 5 || receivedValue == 0 ){
     speechRecognition();
   }


  if(receivedValue == 10 || receivedValue == 11 || receivedValue == 12 || receivedValue == 13 || receivedValue == 14) {
    bopIt();  
  }

  
  
}


void speechRecognition () {

     if(receivedValue == 1 ) {
      myservo.write(95); 
      myservo2.write(85);
      delay(200);
    }

    if(receivedValue == 0) {
      myservo.write(90);
      myservo2.write(90);
      delay(200);
    }

    if(receivedValue == 2) {
      myservo.write(90);
      myservo2.write(85);
      delay(200);
    }

    if(receivedValue == 3) {
      myservo.write(95);
      myservo2.write(90);
      delay(200);
    }

    
    if(receivedValue == 1) {
      //Serial.print(receivedValue);
     x = 225;
    tone(tonePin, x, 225.0);
    Paint_DrawRectangle(220, 10, 150, x, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    Paint_Clear(WHITE);
    //Serial.print(receivedValue);
    }

    if(receivedValue == 2) {
      Serial.print(receivedValue);
     x = 130;
    tone(tonePin, x, 225.0);
    Paint_DrawRectangle(220, 10, 150, x, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    Paint_Clear(WHITE);
    //Serial.print(receivedValue);
    }

    if(receivedValue == 3) {
      //Serial.print(receivedValue);
     x = 185;
    tone(tonePin, x, 225.0);
    Paint_DrawRectangle(220, 10, 150, x, RED,DRAW_FILL_EMPTY, DOT_PIXEL_2X2);
  
    Paint_Clear(WHITE);
    //Serial.print(receivedValue);
    }
  

}


void bopIt() {
  
  //Serial.print("hello world");

   int randomChoice = random(10,14);
    Serial.print(randomChoice);
 
    Paint_Clear(WHITE);
    if(randomChoice == 10) {
      //Serial.print("backfroward");
     
       Paint_DrawString_EN(30, 34, "backnforward", &Font24, BLUE, CYAN);
       
    }

    if(randomChoice == 11) {
      //Serial.print("Up and down"); 
      
      Paint_DrawString_EN(30, 34, "upndown", &Font24, BLUE, CYAN);
       
    }


    if(randomChoice == 13) {
      //Serial.print("leftRight"); 
      
      Paint_DrawString_EN(30, 34, "leftnright", &Font24, BLUE, CYAN);
       
    }

    if(randomChoice == 12) {
      //Serial.print("leftRight"); 
      
      Paint_DrawString_EN(30, 34, "wave!", &Font24, BLUE, CYAN); 
    }

    delay(200);
   

    backgroundSong(); 

    delay(200);
    

    if(randomChoice == receivedValue) {
      Serial.print("you win!");
      if(delaySong == 0) {
        victory();
        Paint_DrawString_EN(30, 34, "VICTORY!", &Font24, BLUE, GREEN);
      }else {
       Paint_Clear(GREEN);
      delaySong = delaySong - 20;
      right();
      delay(300);
      }

    }else {
      Serial.print("you lose!");
      wrong();
      Paint_Clear(RED);
      delaySong = 300;
      delay(300);
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

void right() {
    tone(tonePin, 115, 225.0);
    delay(delayChoice);
    tone(tonePin, 300, 225.0);
    delay(delayChoice);
}

void wrong() {
    tone(tonePin, 300, 225.0);
    delay(delayChoice);
    tone(tonePin, 143, 225.0);
    delay(delayChoice);
}

void victory () {
   tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 220, 225.0);
    delay(250.0);
    tone(tonePin, 277, 112.5);
    delay(125.0);
    tone(tonePin, 293, 112.5);
    delay(125.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
}







/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
