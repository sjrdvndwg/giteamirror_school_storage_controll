/**
 * @file leds.cpp
 * @author Sjoerd van de Wege (svdwege@xs4all.nl)
 * @brief 
 * @version 0.1
 * @date 23-03-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "main.h"


/**
 * @brief cycle through preselected colors to determin which are the best
 * 
 * @param arrled 
 * @param CS 
 */
void color(CRGB arrled[NUM_LEDS], ColorSet CS)
{
    if (CS == ColorSet::Red)
    {
        arrled[1] = CRGB::Crimson;
        arrled[2] = CRGB::DarkRed;
        arrled[3] = CRGB::Maroon;
        arrled[4] = CRGB::Red;
        arrled[5] = CRGB::Tomato;
        FastLED.show();
    }
    else if (CS == ColorSet::Blue)
    {
        arrled[0] = CRGB::Navy;
        arrled[1] = CRGB::MidnightBlue;
        arrled[2] = CRGB::RoyalBlue;
        arrled[3] = CRGB::SteelBlue;
        arrled[4] = CRGB::MediumBlue;
        arrled[5] = CRGB::DodgerBlue;
        arrled[6] = CRGB::DeepSkyBlue;
        arrled[7] = CRGB::Cyan;
        arrled[8] = CRGB::DarkBlue;
        arrled[9] = CRGB::Blue;
        FastLED.show();
    }
    else if (CS == ColorSet::Green)
    {
        arrled[0] = CRGB::Chartreuse;
        arrled[1] = CRGB::Green;
        arrled[2] = CRGB::GreenYellow;
        arrled[3] = CRGB::LawnGreen;
        arrled[4] = CRGB::Lime;
        arrled[5] = CRGB::LimeGreen;
        arrled[6] = CRGB::LightGreen;
        arrled[7] = CRGB::MediumSpringGreen;
        arrled[8] = CRGB::SpringGreen;
        arrled[9] = CRGB::YellowGreen;
        FastLED.show();
    }
    else if (CS == ColorSet::Purple)
    {
        arrled[0] = CRGB::Amethyst;
        arrled[1] = CRGB::BlueViolet;
        arrled[2] = CRGB::DarkMagenta;
        arrled[3] = CRGB::DarkOrchid;
        arrled[4] = CRGB::DarkViolet;
        arrled[5] = CRGB::Indigo;
        arrled[6] = CRGB::MediumOrchid;
        arrled[7] = CRGB::MediumPurple;
        arrled[8] = CRGB::Orchid;
        arrled[9] = CRGB::Purple;
        FastLED.show();
    }
    else if (CS == ColorSet::Pink)
    {
        arrled[0] = CRGB::Fuchsia;
        arrled[1] = CRGB::HotPink;
        arrled[2] = CRGB::Magenta;
        FastLED.show();
    }
    else if (CS == ColorSet::Yellow)
    {
        arrled[0] = CRGB::Yellow;
        arrled[1] = CRGB::YellowGreen;
        FastLED.show();
    }
    else if (CS == ColorSet::White)
    {
        arrled[0] = CRGB::White;
        arrled[1] = CRGB::WhiteSmoke;
        arrled[2] = CRGB::Snow;
        arrled[3] = CRGB::Seashell;
        arrled[4] = CRGB::PapayaWhip;
        arrled[5] = CRGB::Silver;
        arrled[6] = CRGB::GhostWhite;
        FastLED.show();
    }
    else if (CS == ColorSet::Orange)
    {
        arrled[0] = CRGB::Orange;
        arrled[1] = CRGB::DarkOrange;
        FastLED.show();
    }
    else
    {
        arrled[0] = CRGB::Black;
        arrled[1] = CRGB::Black;
        arrled[2] = CRGB::Black;
        arrled[3] = CRGB::Black;
        arrled[4] = CRGB::Black;
        arrled[5] = CRGB::Black;
        arrled[6] = CRGB::Black;
        arrled[7] = CRGB::Black;
        arrled[8] = CRGB::Black;
        arrled[9] = CRGB::Black;
        FastLED.show();
    }
}

/**
 * @brief Set the Led to color
 *
 * @param arrled
 * @param lednum
 * @param color
 */
bool setLed(CRGB arrled[NUM_LEDS], int lednum, CRGB::HTMLColorCode color)
{
    try
    {
        arrled[lednum] = color;
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

/**
 * @brief Set the Unit to color
 *
 * @param arrled
 * @param lednum
 * @param color
 *
 * @return success or fail
 */
bool setUnit(CRGB arrled[NUM_LEDS], int unitnum, CRGB::HTMLColorCode color)
{
    try
    {
        // Code to execute here
        // offset the leds in the array by UNIT_AMOUNT*(unitnum-1) and set the leds to the specified color
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

/**
 * @brief Set the All leds to color
 *
 * @param arrled
 * @param color
 *
 * @return success or fail
 */
bool setAll(CRGB arrled[NUM_LEDS], CRGB::HTMLColorCode color)
{
    try
    {

        // Code to execute here
        // set all leds to the specified color
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

/**
 * @brief Set the Unit to display pattern with colors
 *
 * @param arrled
 * @param lednum
 * @param colorarr
 * @param pattern
 *
 * @return success or fail
 */
bool setUnit(CRGB arrled[NUM_LEDS], int unitnum, CRGB::HTMLColorCode colorarr[UNIT_AMOUNT], Pattern pattern)
{
    try
    {
        // Code to execute here
        // offset the leds in the array by UNIT_AMOUNT*(unitnum-1)
        // set the units leds to display the pattern
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

/**
 * @brief Set the All leds to display pattern with colors
 *
 * @param arrled
 * @param colorlst
 * @param pattern
 *
 * @return success or fail
 */
bool setAll(CRGB arrled[NUM_LEDS], CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern)
{
    try
    {
        // Code to execute here

        // set all leds to display the pattern given
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}