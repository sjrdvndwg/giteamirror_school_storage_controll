#include "main.h"

/**
 * @brief Set the up relay pins as output and write them high to not activate the relayo
 *
 */
void setup_relays()
{
    pinMode(RELAY_0, OUTPUT);
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    pinMode(RELAY_4, OUTPUT);
    pinMode(RELAY_5, OUTPUT);
    pinMode(RELAY_6, OUTPUT);
    pinMode(RELAY_7, OUTPUT);
    pinMode(RELAY_8, OUTPUT);
    digitalWrite(RELAY_0, HIGH);
    digitalWrite(RELAY_1, HIGH);
    digitalWrite(RELAY_2, HIGH);
    digitalWrite(RELAY_3, HIGH);
    digitalWrite(RELAY_4, HIGH);
    digitalWrite(RELAY_5, HIGH);
    digitalWrite(RELAY_6, HIGH);
    digitalWrite(RELAY_7, HIGH);
    digitalWrite(RELAY_8, HIGH);
}

/**
 * @brief set the passed pin low then high
 *
 * @param relay_pin
 */
void ctl_relay(int relay_pin)
{
    digitalWrite(relay_pin, LOW);
    delay(150);
    digitalWrite(relay_pin, HIGH);
}
