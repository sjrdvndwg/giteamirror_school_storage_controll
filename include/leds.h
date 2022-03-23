#ifndef LEDS_H
#define LEDS_H

#include "main.h"

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

void color(CRGB arrled[NUM_LEDS], ColorSet CS);

bool setLed(CRGB arrled[NUM_LEDS], int lednum, CRGB::HTMLColorCode color);

bool setUnit(CRGB arrled[NUM_LEDS], int unitnum, CRGB::HTMLColorCode color);
bool setAll(CRGB arrled[NUM_LEDS], CRGB::HTMLColorCode color);

bool setUnit(CRGB arrled[NUM_LEDS], int unitnum, CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern);
bool setAll(CRGB arrled[NUM_LEDS], CRGB::HTMLColorCode colorlst[UNIT_AMOUNT],Pattern pattern);

#endif
