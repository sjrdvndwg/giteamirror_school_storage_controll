#ifndef __STRUCTS_H__
#define __STRUCTS_H__
#include "main.h"

/**
 * \struct animation patterns
 * \relates ledData_t
 */
struct animated_t
{
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
/**
 * \struct animation offset (unused)
 * \relates ledData_t
 */
struct Anim_Offset_t
{
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
/**
 * \struct colors for each of the unit lockers
 * \relates ledData_t
 */
struct unit_colors_t
{
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
/**
 * \struct a struct to combine all led related structs
 *
 */
struct ledData_t
{
    unit_colors_t colors;
    Anim_Offset_t AnimOffset;
    animated_t AnimBool;
};

/**
 * \struct
 * \brief a struct to keep track of which of the doors should have a lunchbox behind them, and to which order the lunchbox belongs
 */
struct Storage_t
{
    bool haslunch[8];
    char *OrderId[8][4];
};

struct apidata_t
{
    int Type = 0;
    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;
};

#endif // __STRUCTS_H__
