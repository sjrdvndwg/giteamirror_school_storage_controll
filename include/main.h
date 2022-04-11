#ifndef MAIN_H
#define MAIN_H

// How many leds in your strip?
#define NUM_LEDS 27
#define UNIT_AMOUNT 5
#define TOTAL_AMOUNT 9*UNIT_AMOUNT
#define LED_BRIGHTNESS 16 // TODO turn this value up for final;
#define ANIMINC_MAX 16667 // 60 update orders a second at clock speed 240MHZ

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" 
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"


#include <Arduino.h>
#include <FastLED.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#include "leds.h"

void _Main_Loop(void *parameter);
void _update_Loop(void *parameters);

#define DATA_PIN 23
#endif