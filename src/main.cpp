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
Anim_Offset_t offsett;
unit_colors_t colors;
volatile bool order = false;

// Define the array of leds
CRGB leds[NUM_LEDS];
hw_timer_t *animtimer = NULL;

// TaskHandle_t MAIN_LOOP;
// TaskHandle_t update_LOOP;
CRGB allcolor;
WebServer server(80);
void test()
{
  Serial.println("test");
}
void setup()
{
  Serial.begin(115200);
  Serial.println("sreia");
  connectToWiFi();
  // Serial.println(getCpuFrequencyMhz());
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  Serial.println("post led setup");

}
void loop()
{
  // Serial.println("loop");
  server.handleClient();
  // setAll(1);
  if (order)
  {
    // setUnit(CRGB::Amethyst, 1);
    // updateLeds();
    setAll(allcolor);
    FastLED.show();
    Serial.print("log\n");
    order = false;
  }
  
 
}
