#ifndef __TYPES_H__
#define __TYPES_H__

#include "main.h"

/**
 * \typedef hold possible led animations
 * 
 */
typedef enum pattern
{
    NONE,
    Flash,
    Pulse,

} Pattern;

/**
 * \typedef hold the chosen colorset
 * 
 */
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



#endif // __TYPES_H__
