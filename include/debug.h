#ifndef DEBUG_H
#define DEBUG_H 1
#include <WString.h>

void print_debug(const char *data);
void print_debug(const String data);

void connectedClient(String ip);
void connect_attempt_Client(String ip);
void reconnectedClient(String ip);
void disconnectedClient(String ip);
void debugdata(String data);
bool setupTelnet(void);
#endif