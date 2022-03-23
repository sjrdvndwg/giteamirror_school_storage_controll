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


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(32);
}

void loop()
{

  // leds[0] = CRGB::DarkOrchid;
  // leds[1] = CRGB::Amethyst;
  // leds[2] = CRGB::BlueViolet;
  // leds[3] = CRGB::CornflowerBlue;
  // leds[4] = CRGB::LightSkyBlue;
  // leds[5] = CRGB::DarkTurquoise;
  // leds[6] = CRGB::MediumTurquoise;
  // leds[7] = CRGB::PaleGreen;
  // leds[8] = CRGB::Chartreuse;
  // leds[9] = CRGB::FairyLight;

  color(leds, ColorSet::Red);
  delay(5000);
  color(leds, ColorSet::Blue);
  delay(5000);
  color(leds, ColorSet::Green);
  delay(5000);
  color(leds, ColorSet::Purple);
  delay(5000);
  color(leds, ColorSet::Pink);
  delay(5000);
  color(leds, ColorSet::Yellow);
  delay(5000);
  color(leds, ColorSet::White);
  delay(5000);
  color(leds, ColorSet::Orange);
  delay(5000);


}

// void test(CRGB arrled[NUM_LEDS], ){
// }