#ifndef MAIN_H
#define MAIN_H

// How many leds in your strip?
#define NUM_LEDS 27
#define UNIT_AMOUNT 3
#define TOTAL_AMOUNT 9 * UNIT_AMOUNT
#define LED_BRIGHTNESS 16 // TODO turn this value up for final;
#define ANIMINC_MAX 16667 // 60 update orders a second at clock speed 240MHZ

#include <Arduino.h>
#include <FastLED.h>

#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <ESPTelnet.h>
#include <ModbusClientTCPasync.h>

#include "leds.h"
#include "api.h"
#include "debug.h"
#include "relay.h"
#include "modbus.h"

#define DATA_PIN 23
#endif