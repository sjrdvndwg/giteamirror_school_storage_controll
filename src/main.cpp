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
  

  FastLED.show();
  delay(500);

}

// void test(CRGB arrled[NUM_LEDS], ){
// }