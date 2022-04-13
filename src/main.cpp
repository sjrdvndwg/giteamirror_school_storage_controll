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
bool is_Debugging;

// Define the array of leds
CRGB leds[NUM_LEDS];
hw_timer_t *animtimer = NULL;

// TaskHandle_t MAIN_LOOP;
// TaskHandle_t update_LOOP;
CRGB allcolor;
WebServer server(80);
ESPTelnet telnet;

void setup()
{
  Serial.begin(115200);

  connectToWiFi();
  setupTelnet();
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  Serial.println("post led setup");
}
void loop()
{
  server.handleClient();
  telnet.loop();
  if (order)
  {
    updateLeds();
    print_debug("updated leds");

    FastLED.show();
    print_debug("displaying leds");
    order = false;
  }
}
