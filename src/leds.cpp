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
volatile extern bool order;
uint16_t animinc = 0;

// extern animated_t animated_units;
// extern Anim_Offset_t offsett;
// extern unit_colors_t colors;
extern ledData_t leddata;

/** \addtogroup hardware control functions
 *
 * @{
 *
 */

/**
 * @deprecated no longer of use
 * @brief cycle through preselected colors to determin which are the best
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

bool setLed(int lednum, CRGB color)
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

void updateLeds()
{
  if (leddata.AnimBool.unit_0 != NONE)
  {
    if (leddata.AnimBool.unit_0 == Flash)
    {
      if (leddata.AnimOffset.offset_0 == 0)
      {
        Serial.println("on0");
        // if off turn on get color from var reset the offset
        setUnit(leddata.colors.unit0, 0);
        leddata.AnimOffset.offset_0 = 1;
      }
      else if (leddata.AnimOffset.offset_0 == 1)
      {
        Serial.println("off0");
        // if on turn off after storing the color
        leddata.colors.unit0 = leds[0];
        setUnit(CRGB::Black, 0);

        leddata.AnimOffset.offset_0 = 0;
      }
    }
    else if (leddata.AnimBool.unit_0 == Pulse)
    {
      // todo save current color and use CRGB::addto and subtract from to fade
      // it in and out
    }
  }
  else
  {
    setUnit(leddata.colors.unit0, 0);
  }

  if (leddata.AnimBool.unit_1 != NONE)
  {
    if (leddata.AnimBool.unit_1 == Flash)
    {
      if (leddata.AnimOffset.offset_1 == 0)
      {
        Serial.println("on1");
        setUnit(leddata.colors.unit1, 1);
        leddata.AnimOffset.offset_1 = 1;
      }
      else if (leddata.AnimOffset.offset_1 == 1)
      {
        Serial.println("off1");
        leddata.colors.unit1 = leds[(UNIT_AMOUNT * 1)];
        setUnit(CRGB::Black, 1);
        leddata.AnimOffset.offset_1 = 0;
      }
    }
    else if (leddata.AnimBool.unit_1 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit1, 1);
  }

  if (leddata.AnimBool.unit_2 != NONE)
  {
    if (leddata.AnimBool.unit_2 == Flash)
    {
      if (leddata.AnimOffset.offset_2 == 0)
      {
        Serial.println("on2");
        setUnit(leddata.colors.unit2, 2);
        leddata.AnimOffset.offset_2 = 1;
      }
      else if (leddata.AnimOffset.offset_2 == 1)
      {
        Serial.println("off2");
        leddata.colors.unit2 = leds[(UNIT_AMOUNT * 2)];
        setUnit(CRGB::Black, 2);
        leddata.AnimOffset.offset_2 = 0;
      }
    }
    else if (leddata.AnimBool.unit_2 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit2, 2);
  }

  if (leddata.AnimBool.unit_3 != NONE)
  {
    if (leddata.AnimBool.unit_3 == Flash)
    {
      if (leddata.AnimOffset.offset_3 == 0)
      {
        Serial.println("on3");
        setUnit(leddata.colors.unit3, 3);
        leddata.AnimOffset.offset_3 = 1;
      }
      else if (leddata.AnimOffset.offset_3 == 1)
      {
        Serial.println("off3");
        leddata.colors.unit3 = leds[(UNIT_AMOUNT * 3)];
        setUnit(CRGB::Black, 3);
        leddata.AnimOffset.offset_3 = 0;
      }
    }
    else if (leddata.AnimBool.unit_3 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit3, 3);
  }

  if (leddata.AnimBool.unit_4 != NONE)
  {
    if (leddata.AnimBool.unit_4 == Flash)
    {
      if (leddata.AnimOffset.offset_4 == 0)
      {
        Serial.println("on4");
        setUnit(leddata.colors.unit4, 4);
        leddata.AnimOffset.offset_4 = 1;
      }
      else if (leddata.AnimOffset.offset_4 == 1)
      {
        Serial.println("off4");

        leddata.colors.unit4 = leds[(UNIT_AMOUNT * 4)];
        setUnit(CRGB::Black, 4);
        leddata.AnimOffset.offset_4 = 0;
      }
    }
    else if (leddata.AnimBool.unit_4 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit4, 4);
  }

  if (leddata.AnimBool.unit_5 != NONE)
  {
    if (leddata.AnimBool.unit_5 == Flash)
    {
      if (leddata.AnimOffset.offset_5 == 0)
      {
        Serial.println("on5");
        setUnit(leddata.colors.unit5, 5);
        leddata.AnimOffset.offset_5 = 1;
      }
      else if (leddata.AnimOffset.offset_5 == 1)
      {
        Serial.println("off5");
        leddata.colors.unit5 = leds[(UNIT_AMOUNT * 5)];
        setUnit(CRGB::Black, 5);
        leddata.AnimOffset.offset_5 = 0;
      }
    }
    else if (leddata.AnimBool.unit_5 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit5, 5);
  }

  if (leddata.AnimBool.unit_6 != NONE)
  {
    if (leddata.AnimBool.unit_6 == Flash)
    {
      if (leddata.AnimOffset.offset_6 == 0)
      {
        Serial.println("on6");
        setUnit(leddata.colors.unit6, 6);
        leddata.AnimOffset.offset_6 = 1;
      }
      else if (leddata.AnimOffset.offset_6 == 1)
      {
        Serial.println("off6");
        leddata.colors.unit6 = leds[(UNIT_AMOUNT * 6)];
        setUnit(CRGB::Black, 6);
        leddata.AnimOffset.offset_6 = 0;
      }
    }
    else if (leddata.AnimBool.unit_6 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit6, 6);
  }

  if (leddata.AnimBool.unit_7 != NONE)
  {
    if (leddata.AnimBool.unit_7 == Flash)
    {
      if (leddata.AnimOffset.offset_7 == 0)
      {
        Serial.println("on7");
        setUnit(leddata.colors.unit7, 7);
        leddata.AnimOffset.offset_7 = 1;
      }
      else if (leddata.AnimOffset.offset_7 == 1)
      {
        Serial.println("off7");
        leddata.colors.unit7 = leds[(UNIT_AMOUNT * 7)];
        setUnit(CRGB::Black, 7);
        leddata.AnimOffset.offset_7 = 0;
      }
    }
    else if (leddata.AnimBool.unit_7 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit7, 7);
  }

  if (leddata.AnimBool.unit_8 != NONE)
  {
    if (leddata.AnimBool.unit_8 == Flash)
    {
      if (leddata.AnimOffset.offset_8 == 0)
      {
        Serial.println("on8");
        setUnit(leddata.colors.unit8, 8);
        leddata.AnimOffset.offset_8 = 1;
      }
      else if (leddata.AnimOffset.offset_8 == 1)
      {
        Serial.println("off8");
        leddata.colors.unit8 = leds[(UNIT_AMOUNT * 8)];
        setUnit(CRGB::Black, 8);
        leddata.AnimOffset.offset_8 = 0;
      }
    }
    else if (leddata.AnimBool.unit_8 == Pulse)
    {
    }
  }
  else
  {
    setUnit(leddata.colors.unit8, 8);
  }
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
bool setUnit(CRGB color, int unitnum)
{

  int offset = 0;
  offset = UNIT_AMOUNT * unitnum;
  // switch (unitnum)
  // {
  // case 0:
  //     offset = 0;
  //     break;
  // case 1:
  //     offset = UNIT_AMOUNT * 1;
  //     break;
  // case 2:
  //     offset = UNIT_AMOUNT * 2;
  //     break;
  // case 3:
  //     offset = UNIT_AMOUNT * 3;
  //     break;
  // case 4:
  //     offset = UNIT_AMOUNT * 4;
  //     break;
  // case 5:
  //     offset = UNIT_AMOUNT * 5;
  //     break;
  // case 6:
  //     offset = UNIT_AMOUNT * 6;
  //     break;
  // case 7:
  //     offset = UNIT_AMOUNT * 7;
  //     break;
  // case 8:
  //     offset = UNIT_AMOUNT * 8;
  //     break;
  // default:
  //     break;
  // }

  // offset the leds in the array by UNIT_AMOUNT*(unitnum-1) and set the leds to
  // the specified color int offset = UNIT_AMOUNT * (unitnum - 1);
  for (size_t i = offset; i < (offset + UNIT_AMOUNT); i++)
  {
    leds[i] = color;
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
bool setUnit(CRGB::HTMLColorCode color, int unitnum)
{

  int offset = 0;
  switch (unitnum)
  {
  case 0:
    offset = 0;
    break;
  case 1:
    offset = UNIT_AMOUNT * 1;
    break;
  case 2:
    offset = UNIT_AMOUNT * 2;
    break;
  case 3:
    offset = UNIT_AMOUNT * 3;
    break;
  case 4:
    offset = UNIT_AMOUNT * 4;
    break;
  case 5:
    offset = UNIT_AMOUNT * 5;
    break;
  case 6:
    offset = UNIT_AMOUNT * 6;
    break;
  case 7:
    offset = UNIT_AMOUNT * 7;
    break;
  case 8:
    offset = UNIT_AMOUNT * 8;
    break;
  default:
    break;
  }

  // if (unitnum == 0)
  // {
  //     offset = 0;
  // }
  // else
  // {
  //     offset = UNIT_AMOUNT * (unitnum - 1);
  // }

  // offset the leds in the array by UNIT_AMOUNT*(unitnum-1) and set the leds to
  // the specified color int offset = UNIT_AMOUNT * (unitnum - 1);
  for (size_t i = offset; i < (offset + UNIT_AMOUNT); i++)
  {
    leds[i] = color;
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
bool setAll(CRGB::HTMLColorCode color)
{
  try
  {
    // set all leds to the specified color
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = color;
    }
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
 * @param color
 *
 * @return success or fail
 */
bool setAll(CRGB color)
{
  try
  {
    // set all leds to the specified color
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = color;
    }
  }
  catch (const std::exception &e)
  {
    return false;
  }
  return true;
}
