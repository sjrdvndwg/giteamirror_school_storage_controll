#ifndef API_H
#define API_H
#define JSONDOCSIZE 1024
struct apidata_t{
    int Type = 0;
    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;
};

void connectToWiFi();
void setupRoutes();

void _parseconst();
void _parse__MultiSeg();

#endif // API_H