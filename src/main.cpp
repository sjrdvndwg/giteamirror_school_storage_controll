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
volatile bool order = false;

bool is_Debugging;

animated_t animated_units;
Anim_Offset_t offsett;
unit_colors_t colors;


CRGB leds[NUM_LEDS];
CRGB allcolor;

WebServer server(80);
ESPTelnet telnet;

void setup()
{
  Serial.begin(115200);

  connectToWiFi();
  setupTelnet();
  setup_relays();
  
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);

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
