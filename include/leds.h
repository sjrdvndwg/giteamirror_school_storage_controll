#ifndef LEDS_H
#define LEDS_H

#include "main.h"



struct animated_t{
    bool unit_0 = false;
    bool unit_1 = true;
    bool unit_2 = true;
    bool unit_3 = false;
    bool unit_4 = false;
    bool unit_5 = false;
    bool unit_6 = false;
    bool unit_7 = false;
    bool unit_8 = false;
};

typedef enum pattern
{
    rainbow,
    pulse,
    cycle,
    noise
} Pattern;

typedef enum colorset
{
    Red,
    Blue,
    Green,
    Purple,
    Pink,
    Yellow,
    White,
    Orange
} ColorSet;

void led_rainbow();

void updateAnim();

void color(ColorSet CS);

bool setLed(int lednum, CRGB::HTMLColorCode color);

bool setUnit(CRGB::HTMLColorCode color,int unitnum);
bool setAll(CRGB::HTMLColorCode color);

bool setUnit(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern,int unitnum);
bool setAll(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT],Pattern pattern);

#endif
