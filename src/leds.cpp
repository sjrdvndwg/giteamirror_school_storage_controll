#include "main.h"

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