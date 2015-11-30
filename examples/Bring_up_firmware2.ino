#include <Arduino.h>
#include <avr/power.h>


#include "ZackeesFashionGlowJewelry_v1.h"



void setup() {
  ZackeesFashionGlowJewelry_Setup();
  pinMode(13, OUTPUT);                // user LED
}


void loop() {

  int r, g, b;
  r = g = b = 64;  // Max power is 255 each color.

  delay(5);                // Allow some time to power-up
  for (int i = 0;  i < g_pixelStrip.numPixels() - 2;  ++i) {
     ledRing().setPixelColor(i,     r, 0, 0);
     ledRing().setPixelColor(i + 1, 0, g, 0);
     ledRing().setPixelColor(i + 2, 0, 0, b);
     ledRing().show();
     delay(100);
     ledRing().setPixelColor(i,     0, 0, 0);
     ledRing().setPixelColor(i + 1, 0, 0, 0);
     ledRing().setPixelColor(i + 2, 0, 0, 0);
  }
  ledRing().show();
  
  Serial.println("X - Draw");

  Serial.print("Accel: ");
    Serial.print(
      g_accelerometer.readAcceleration(MMA7660::X));
    Serial.print(",");
    Serial.print(
      g_accelerometer.readAcceleration(MMA7660::Y));
    Serial.print(",");
    Serial.println(
      g_accelerometer.readAcceleration(MMA7660::Z));

  g_digitalPot.setWiper(0x7F);
  delay(200);
  g_digitalPot.setWiper(0x00);
    
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
}
