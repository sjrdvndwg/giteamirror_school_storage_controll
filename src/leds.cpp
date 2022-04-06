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

extern CRGB leds[NUM_LEDS];
extern animated_t animated_units;
int ghue = 0;
void led_rainbow()
{
//todo copy current led state
//todo  add check to set all the un animated sectors to their previous state
//! remove this
 
   if (animated_units.unit_0)
   {
       fill_rainbow(leds, UNIT_AMOUNT, ghue);
   }
   if (animated_units.unit_1)
   {
       fill_rainbow(leds, UNIT_AMOUNT*2, ghue);
   }
   if (animated_units.unit_2)
   {
       fill_rainbow(leds, UNIT_AMOUNT*3, ghue);
   }
   if (animated_units.unit_3)
   {
       fill_rainbow(leds, UNIT_AMOUNT*4, ghue);
   }
   if (animated_units.unit_4)
   {
       fill_rainbow(leds, UNIT_AMOUNT*5, ghue);
   }
   if (animated_units.unit_5)
   {
       fill_rainbow(leds, UNIT_AMOUNT*6, ghue);
   }
   if (animated_units.unit_6)
   {
       fill_rainbow(leds, UNIT_AMOUNT*7, ghue);
   }
    if (animated_units.unit_7)
   {
       fill_rainbow(leds, UNIT_AMOUNT*8, ghue);
   }
    if (animated_units.unit_8)
   {
       fill_rainbow(leds, UNIT_AMOUNT*9, ghue);
   }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // fill_rainbow(leds, UNIT_AMOUNT * unitnumber, ghue);
    // int unitnum = unitnumber - 1;
    // for (size_t i = 0; i < UNIT_AMOUNT *unitnum; i++)
    // {
    //     leds[i] = CRGB::Black;
    // }
    
}


void updateAnim(){
    ghue++;
    led_rainbow();
}


/**
 * @brief cycle through preselected colors to determin which are the best
 * 
 * @param leds 
 * @param CS 
 */
void color(ColorSet CS)
{
    if (CS == ColorSet::Red)
    {
        leds[1] = CRGB::Crimson;
        leds[2] = CRGB::DarkRed;
        leds[3] = CRGB::Maroon;
        leds[4] = CRGB::Red;
        leds[5] = CRGB::Tomato;
        leds[6] = CRGB::Black;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
    else if (CS == ColorSet::Blue)
    {
        leds[0] = CRGB::Navy;
        leds[1] = CRGB::MidnightBlue;
        leds[2] = CRGB::RoyalBlue;
        leds[3] = CRGB::SteelBlue;
        leds[4] = CRGB::MediumBlue;
        leds[5] = CRGB::DodgerBlue;
        leds[6] = CRGB::DeepSkyBlue;
        leds[7] = CRGB::Cyan;
        leds[8] = CRGB::DarkBlue;
        leds[9] = CRGB::Blue;
        FastLED.show();
    }
    else if (CS == ColorSet::Green)
    {
        leds[0] = CRGB::Chartreuse;
        leds[1] = CRGB::Green;
        leds[2] = CRGB::GreenYellow;
        leds[3] = CRGB::LawnGreen;
        leds[4] = CRGB::Lime;
        leds[5] = CRGB::LimeGreen;
        leds[6] = CRGB::LightGreen;
        leds[7] = CRGB::MediumSpringGreen;
        leds[8] = CRGB::SpringGreen;
        leds[9] = CRGB::YellowGreen;
        FastLED.show();
    }
    else if (CS == ColorSet::Purple)
    {
        leds[0] = CRGB::Amethyst;
        leds[1] = CRGB::BlueViolet;
        leds[2] = CRGB::DarkMagenta;
        leds[3] = CRGB::DarkOrchid;
        leds[4] = CRGB::DarkViolet;
        leds[5] = CRGB::Indigo;
        leds[6] = CRGB::MediumOrchid;
        leds[7] = CRGB::MediumPurple;
        leds[8] = CRGB::Orchid;
        leds[9] = CRGB::Purple;
        FastLED.show();
    }
    else if (CS == ColorSet::Pink)
    {
        leds[0] = CRGB::Fuchsia;
        leds[1] = CRGB::HotPink;
        leds[2] = CRGB::Magenta;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black;
        leds[5] = CRGB::Black;
        leds[6] = CRGB::Black;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
    else if (CS == ColorSet::Yellow)
    {
        leds[0] = CRGB::Yellow;
        leds[1] = CRGB::YellowGreen;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black;
        leds[5] = CRGB::Black;
        leds[6] = CRGB::Black;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
    else if (CS == ColorSet::White)
    {
        leds[0] = CRGB::White;
        leds[1] = CRGB::WhiteSmoke;
        leds[2] = CRGB::Snow;
        leds[3] = CRGB::Seashell;
        leds[4] = CRGB::PapayaWhip;
        leds[5] = CRGB::Silver;
        leds[6] = CRGB::GhostWhite;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
    else if (CS == ColorSet::Orange)
    {
        leds[0] = CRGB::Orange;
        leds[1] = CRGB::DarkOrange;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black;
        leds[5] = CRGB::Black;
        leds[6] = CRGB::Black;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
    else
    {
        leds[0] = CRGB::Black;
        leds[1] = CRGB::Black;
        leds[2] = CRGB::Black;
        leds[3] = CRGB::Black;
        leds[4] = CRGB::Black;
        leds[5] = CRGB::Black;
        leds[6] = CRGB::Black;
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
        leds[9] = CRGB::Black;
        FastLED.show();
    }
}

/**
 * @brief Set the Led to color
 *
 * @param leds
 * @param lednum
 * @param color
 */
bool setLed(int lednum, CRGB::HTMLColorCode color)
{
    try
    {
        leds[lednum] = color;
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
 * @param leds
 * @param lednum
 * @param color
 *
 * @return success or fail
 */
bool setUnit(int unitnum, CRGB::HTMLColorCode color)
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
bool setAll(CRGB::HTMLColorCode color){
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
bool setUnit(int unitnum, CRGB::HTMLColorCode color, Pattern pattern)
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
bool setAll(CRGB::HTMLColorCode colorlst[UNIT_AMOUNT], Pattern pattern)
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