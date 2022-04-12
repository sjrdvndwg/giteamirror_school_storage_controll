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

TaskHandle_t MAIN_LOOP;
TaskHandle_t update_LOOP;

WebServer server(80);
void test(){
  Serial.println("test");
}
void setup()
{
  Serial.begin(115200);
  connectToWiFi();
  // setupRoutes();
  unsigned short clkdiv = 2;

  animtimer = timerBegin(0, clkdiv, true);
  timerAttachInterrupt(animtimer, test, false);
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  // xTaskCreatePinnedToCore(_Main_Loop, "Mainloop", 10000, NULL, 0, &MAIN_LOOP, 0);
  xTaskCreatePinnedToCore(_update_Loop, "updateloop", 10000, NULL, 0, &update_LOOP, 1);
}
void loop() {
  sei();
  Serial.println("mainlp");
  for (;;)
  {

    if (!order)
    {
      FastLED.show();
      server.handleClient();

    }
    else
    {
      
    }
  }}

void _Main_Loop(void *parameter)
{
  sei();
  Serial.println("mainlp");
  for (;;)
  {

    if (!order)
    {
      FastLED.show();
      server.handleClient();

    }
    else
    {
      
    }
  }
}

void _update_Loop(void *parameters)
{
  sei();
  Serial.println("auxlp");
  for (;;)
  {
    if (order)
    {
      if (animated_units.unit_0 != NONE)
      {
        if (animated_units.unit_0 == Flash)
        {
          if (offsett.offset_0 == 0)
          {
            setUnit(colors.unit0, 0);
            offsett.offset_0 = 1;
          }
          else if (offsett.offset_0 == 1)
          {
            colors.unit0 = leds[0];

            offsett.offset_0 = 0;
          }

          order = false;
        }
        else if (animated_units.unit_0 == Pulse)
        {
          //todo save current color and use CRGB::addto and subtract from to fade it in and out 

          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_1 != NONE)
      {
        if (animated_units.unit_1 == Flash)
        {
          if (offsett.offset_1 == 0)
          {
            setUnit(colors.unit1, 1);
            offsett.offset_1 = 1;
          }
          else if (offsett.offset_1 == 1)
          {
            colors.unit1 = leds[(UNIT_AMOUNT * 1)];
            setUnit(CRGB::Black, 1);
            offsett.offset_1 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_1 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_2 != NONE)
      {
        if (animated_units.unit_2 == Flash)
        {
          if (offsett.offset_2 == 0)
          {
            setUnit(colors.unit2, 2);
            offsett.offset_2 = 1;
          }
          else if (offsett.offset_2 == 1)
          {
            colors.unit2 = leds[(UNIT_AMOUNT * 2)];
            setUnit(CRGB::Black, 2);
            offsett.offset_2 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_2 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_3 != NONE)
      {
        if (animated_units.unit_3 == Flash)
        {
          if (offsett.offset_3 == 0)
          {
            setUnit(colors.unit3, 3);
            offsett.offset_3 = 1;
          }
          else if (offsett.offset_3 == 1)
          {
            colors.unit3 = leds[(UNIT_AMOUNT * 3)];
            setUnit(CRGB::Black, 3);
            offsett.offset_3 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_3 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_4 != NONE)
      {
        if (animated_units.unit_4 == Flash)
        {
          if (offsett.offset_4 == 0)
          {
            setUnit(colors.unit4, 4);
            offsett.offset_4 = 1;
          }
          else if (offsett.offset_4 == 1)
          {
            colors.unit4 = leds[(UNIT_AMOUNT * 4)];
            setUnit(CRGB::Black, 4);
            offsett.offset_4 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_4 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_5 != NONE)
      {
        if (animated_units.unit_5 == Flash)
        {
          if (offsett.offset_5 == 0)
          {
            setUnit(colors.unit5, 5);
            offsett.offset_5 = 1;
          }
          else if (offsett.offset_5 == 1)
          {
            colors.unit5 = leds[(UNIT_AMOUNT * 5)];
            setUnit(CRGB::Black, 5);
            offsett.offset_5 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_5 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_6 != NONE)
      {
        if (animated_units.unit_6 == Flash)
        {
          if (offsett.offset_6 == 0)
          {
            setUnit(colors.unit6, 6);
            offsett.offset_6 = 1;
          }
          else if (offsett.offset_6 == 1)
          {
            colors.unit6 = leds[(UNIT_AMOUNT * 6)];
            setUnit(CRGB::Black, 6);
            offsett.offset_6 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_6 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_7 != NONE)
      {
        if (animated_units.unit_7 == Flash)
        {
          if (offsett.offset_7 == 0)
          {
            setUnit(colors.unit7, 7);
            offsett.offset_7 = 1;
          }
          else if (offsett.offset_7 == 1)
          {
            colors.unit7 = leds[(UNIT_AMOUNT * 7)];
            setUnit(CRGB::Black, 7);
            offsett.offset_7 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_7 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }

      if (animated_units.unit_8 != NONE)
      {
        if (animated_units.unit_8 == Flash)
        {
          if (offsett.offset_8 == 0)
          {
            setUnit(colors.unit8, 8);
            offsett.offset_8 = 1;
          }
          else if (offsett.offset_8 == 1)
          {
            colors.unit8 = leds[(UNIT_AMOUNT * 8)];
            setUnit(CRGB::Black, 8);
            offsett.offset_8 = 0;
          }
          order = false;
        }
        else if (animated_units.unit_8 == Pulse)
        {
          order = false;
        }
        else
        {
          order = false;
        }
        order = false;
      }
    }
  }
}
