#ifndef API_H
#define API_H
#define JSONDOCSIZE 1024

void connectToWiFi();
void setupRoutes();

void _send_doors();
void _parseconst();
void _parse__MultiSeg();
void _parse_relay();

void _get_door_number();

#endif // API_H