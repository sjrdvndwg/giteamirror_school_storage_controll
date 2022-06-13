#ifndef LEDS_H
#define LEDS_H

#include "main.h"

void color(ColorSet CS);

bool setLed(int lednum, CRGB::HTMLColorCode color);
bool setLed(int lednum, CRGB color);

void updateLeds();

bool setUnit(CRGB color, int unitnum);
bool setUnit(CRGB::HTMLColorCode color, int unitnum);
// bool setUnit(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern,int unitnum);

bool setAll(CRGB::HTMLColorCode color);
bool setAll(CRGB color);
// bool setAll(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT],Pattern pattern);

#endif
