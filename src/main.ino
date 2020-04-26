/*
    Edited (C) 2020 André Geiger Giant LED Clock
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "userconfig.h"
#include <Arduino.h>
#include "wifi.h"
#include <Adafruit_NeoPixel.h>

// DEFINITIONS
// ===============================
Adafruit_NeoPixel led_segments(LED_COUNT, PIN_SEGMENTS, NEO_GRB + NEO_KHZ800);
WiFiUDP ntpUDP;
int secondblink = 0;
int PpSeg = 9;
int number0[] = {1,1,1,0,1,1,1};
int number1[] = {1,0,0,0,1,0,0};
int number2[] = {1,1,0,1,0,1,1};
int number3[] = {1,1,0,1,1,1,0};
int number4[] = {1,0,1,1,1,0,0};
int number5[] = {0,1,1,1,1,1,0};
int number6[] = {0,1,1,1,1,1,1};
int number7[] = {1,1,0,0,1,0,0};
int number8[] = {1,1,1,1,1,1,1};
int number9[] = {1,1,1,1,1,1,0};
int SegmentOffset[] = {0,9,27,36,45,54,72};
unsigned long timer1 = 0;
unsigned long timer2 = 0;
int hours;
int hour1;
int hour2;
int minutes;
int minutes1;
int minutes2;
int seconds;
int seconds1;
int seconds2;
// ===============================
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7200, 60000);

ESP8266WebServer server(80);

void setup(void) {
  Serial.begin(115200);
    // Wifi initialize
  wifiInit();

// START LED
// ===============================
  led_segments.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  led_segments.show();            // Turn OFF all pixels ASAP
  led_segments.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
// ===============================

  timeClient.begin();
}

void loop(void) {

// Refresh Time
// ===============================
 while(millis() >= timer1 + 100)
  {
  timeClient.update();
//    Serial.print("Actual time: ");
//    Serial.println(timeClient.getFormattedTime());
  hours = timeClient.getHours();
    hour1 = hours / 10;                   // left position hour
    hour2 = hours - (hour1 *10);          // right position hour
  minutes = timeClient.getMinutes();
    minutes1 = minutes / 10;              // left position minute
    minutes2 = minutes - (minutes1 *10);  // right position minute
  seconds = timeClient.getSeconds();
    seconds1 = seconds / 10;              // left position second
    seconds2 = seconds - (seconds1 *10);  // right position second
  timer1 = millis();
  }
// ===============================

// ===============================
// Seconds Blink
while(millis() >= timer2 + 1000)
  { 
  if (secondblink == 0)  
  {
  led_segments.setPixelColor(175, 255, 0, 0);
  led_segments.show();
  secondblink = 1;
  }
  else
  {
  led_segments.setPixelColor(175, 0, 0, 0);
  led_segments.show();
  secondblink = 0;
  }
  timer2 = millis();
  }

// ===============================

  setSegment(0, seconds2, 0, 0, 255);
  setSegment(90,seconds1, 0, 0, 255);
//  setSegment(180,minutes2, 0, 0, 255);
//  setSegment(270,minutes1, 0, 0, 255);
 
}

// ============================================================================================================================
// ============================================================================================================================
// Set Segments
// ===============================
void setSegment (int a, int number, int r, int g, int b)
{
   switch (number)
  {
    case 0:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1)
        {
          
          if (number0[y] == 1)
          {
              led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number0[y] == 0)
          {
              led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 1:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
          
          if (number1[y] == 1)
          {
              led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number1[y] == 0)
          {
              led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 2:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
      
          if (number2[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number2[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 3:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
      
          if (number3[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number3[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 4:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
      
          if (number4[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number4[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 5:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
      
          if (number5[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number5[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 6:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
      
          if (number6[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number6[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 7:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
          if (number7[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number7[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 8:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
          if (number8[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number8[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
    case 9:
      for(int y = 0; y<7; y += 1) 
      {
        for(int x = 0; x<PpSeg; x += 1) 
        {
          if (number9[y] == 1)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, r, g, b);
          }
          if (number9[y] == 0)
          {
          led_segments.setPixelColor(SegmentOffset[y]+x+a, 0, 0, 0);
          }
        }
      }
      led_segments.show();
      break;
  }
}