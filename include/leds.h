#ifndef LEDS_H
#define LEDS_H

#include "main.h"



typedef enum pattern
{
    NONE,
    Flash,
    Pulse,

} Pattern;
    // Cycle,
    // Noise
struct animated_t{
    Pattern unit_0 = NONE;
    Pattern unit_1 = NONE;
    Pattern unit_2 = NONE;
    Pattern unit_3 = NONE;
    Pattern unit_4 = NONE;
    Pattern unit_5 = NONE;
    Pattern unit_6 = NONE;
    Pattern unit_7 = NONE;
    Pattern unit_8 = NONE;
};
struct Anim_Offset_t{
    int offset_0 = 0;
    int offset_1 = 0;
    int offset_2 = 0;
    int offset_3 = 0;
    int offset_4 = 0;
    int offset_5 = 0;
    int offset_6 = 0;
    int offset_7 = 0;
    int offset_8 = 0;
};


struct unit_colors_t {
    CRGB unit0;
    CRGB unit1;
    CRGB unit2;
    CRGB unit3;
    CRGB unit4;
    CRGB unit5;
    CRGB unit6;
    CRGB unit7;
    CRGB unit8;
};

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

void color(ColorSet CS);

bool setLed(int lednum, CRGB::HTMLColorCode color);

void updateLeds();

bool setUnit(CRGB color, int unitnum);
bool setUnit(CRGB::HTMLColorCode color, int unitnum);
// bool setUnit(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern,int unitnum);

bool setAll(CRGB::HTMLColorCode color);
bool setAll(CRGB color);
// bool setAll(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT],Pattern pattern);

#endif
