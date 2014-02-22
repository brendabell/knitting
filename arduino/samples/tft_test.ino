#include <stdint.h>
#include <TouchScreen.h>
#include <TFT.h>

long count;
char countStr[8];

int pos;
char posStr[4];

long time;
char timeStr[8];

int dir;
char dirStr[6];

void setup()
{
  Tft.init();
  count = 0;
  pos = 0;
  drawScreen();
}

void loop()
{
  getData();

  Tft.fillRectangle(140,40,50,15,BLACK);
  Tft.drawString(timerChar,140,40,2,CYAN);
  Tft.fillRectangle(140,70,60,15,BLACK);
  Tft.drawString(
}

void initScreen()
{
void drawScreen(){                
  Tft.drawRectangle(0, 3, 238,30,BLUE);            // HEADER TITLE
  Tft.drawString("DISPLAY DATA",20,15,2,WHITE);    // header name
  Tft.drawString("Seconds:",2,40,2,CYAN);          
  Tft.drawString("Count:",2,70,2,WHITE);
  Tft.drawString("Direction:",2,100,2,WHITE);
  Tft.drawString("Position:",2,130,2,WHITE);
}  

void getData()
{
 time = millis() / 1000;
 count++;
 if (pos >= 50)
 {
   x = ~x;
   pos--;
 }
 else
 {
   pos++;
 }
}

