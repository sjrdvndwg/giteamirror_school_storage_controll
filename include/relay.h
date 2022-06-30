#ifndef RELAY_H
#define RELAY_H

#define RELAY_0 22
#define RELAY_1 19
#define RELAY_2 18
#define RELAY_3 5
#define RELAY_4 17
#define RELAY_5 16
#define RELAY_6 4
#define RELAY_7 0
#define RELAY_8 2

void setup_relays();
void ctl_relay(int relay_pin);

#endif