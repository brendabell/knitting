/* Modified from Draw Texts - Demonstrate drawChar and drawString
/  Example to display sensor data on TFT screen
/  
/  For Arduino MEGA with Seeed V1 TFT Touch Shield
/  Circuit: Joystick, or Pot center pin connected to A8, A9, and A10.
/  pot outer pins connected to GND and 5V
/  
*/

#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>

#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 54   // can be a digital pin, this is A0
#define XP 57   // can be a digital pin, this is A3 


int sensor1Data;            // Data varable for JS1 pot 1
int sensor2Data;            // Data varable for JS1 pot 2
int sensor3Data;            // Data varable for JS2 pot 3
char sensor1Char[4];        // Charactor array for pot 1
char sensor2Char[4];        // Charactor array for pot 2
char sensor3Char[4];        // Charactor array for pot 3
long timerData;             // Data varable for timer
char timerChar[4];          // Charactor array for timer
void setup()
{

  Tft.init();  //init TFT library
  pinMode(A8, INPUT);         // JS1 input (pot 1 u/d)
  pinMode(A9, INPUT);         // JS1 input (pot 2 r/l)
  pinMode(A10, INPUT);        // JS2 input (pot 3 u/d)
  
  drawScreen();              // Draw info that does not change once
}

void loop()
{
  getSensor();                                  // Get Sensor Data 
  
      // Print Char to TFT //
  Tft.fillRectangle(140,40,50,15,BLACK);        // Clear old text
  Tft.drawString(timerChar,140,40,2,CYAN);      // Print time
  Tft.fillRectangle(140,70,60,15,BLACK);        // Clear old text
  Tft.drawString(sensor1Char,140,70,2,WHITE);   // Print Sensor 1
  Tft.fillRectangle(140,100,60,15,BLACK);       // Clear old text
  Tft.drawString(sensor2Char,140,100,2,WHITE);  // Print Sensor 2
  Tft.fillRectangle(140,130,60,15,BLACK);       // Clear old text
  Tft.drawString(sensor3Char,140,130,2,WHITE);  // Print Sensor 3
  
  delay(1000);                                  // delay to read screen

}

// Draw Screen Function //
// Draw all the text and objects that will not change //
void drawScreen(){                
  Tft.drawRectangle(0, 3, 238,30,BLUE);            // HEADER TITLE
  Tft.drawString("DISPLAY DATA",20,15,2,WHITE);    // header name
  Tft.drawString("Seconds:",2,40,2,CYAN);          
  Tft.drawString("Elevator:",2,70,2,WHITE);
  Tft.drawString("Rudder:",2,100,2,WHITE);
  Tft.drawString("Throttle:",2,130,2,WHITE);
}
  
// Get Sensor Function //
// Gets sensor data and converts to character //
void getSensor(){  
  timerData = millis()/1000;            // Read time
  int val= analogRead(A8);              // Read JS1 (pot 1)
  sensor1Data= map(val,0,1023,0,100);   // Map value from 0-100
  val= analogRead(A9);                  // Read JS1 (pot 2)
  sensor2Data= map(val,0,1023,0,100);   // Map value from 0-100
  val= analogRead(A10);                 // Read JS2 (pot 3)
  sensor3Data= map(val,0,1023,0,100);   // Map value from 0-100
      // Convert Data to Char //
  itoa (timerData, timerChar, 10);
  itoa(sensor1Data, sensor1Char, 10);  // convert sensor data to char
  itoa(sensor2Data, sensor2Char, 10);  // convert sensor data to char
  itoa(sensor3Data, sensor3Char, 10);  // convert sensor data to char
}
