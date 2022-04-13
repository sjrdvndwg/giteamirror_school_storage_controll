#ifndef DEBUG_H
#define DEBUG_H 1
// #include <string.h>

void print_debug(const char *data);
void connectedClient(String ip);
void connect_attempt_Client(String ip);
void reconnectedClient(String ip);
void disconnectedClient(String ip);
void debugdata(String data);
void setupTelnet();
#endif