/**
 * @file main.cpp
 * @author Sjoerd van de Wege (svdwege@xs4all.nl)
 * @brief 
 * @version 0.1
 * @date 23-03-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "main.h"

volatile int interruptcounter;
animated_t animated_units;
// Define the array of leds
CRGB leds[NUM_LEDS];
hw_timer_t *animtimer = NULL;

void setup()
{
  animtimer = timerBegin(0, 80, true);
  timerAttachInterrupt(animtimer,&updateAnim,true);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(16);
}

void loop()
{
  // led_rainbow();

  leds[0] = CRGB::DarkOrchid;
  leds[1] = CRGB::Amethyst;
  leds[2] = CRGB::BlueViolet;
  leds[3] = CRGB::CornflowerBlue;
  leds[4] = CRGB::LightSkyBlue;
  leds[5] = CRGB::DarkTurquoise;
  leds[6] = CRGB::MediumTurquoise;
  leds[7] = CRGB::PaleGreen;
  leds[8] = CRGB::Chartreuse;
  leds[9] = CRGB::FairyLight;
  delay(5000);
  FastLED.show();
}



