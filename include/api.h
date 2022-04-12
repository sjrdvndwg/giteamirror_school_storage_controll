#ifndef API_H
#define API_H

struct apidata_t{
    int Type = 0;
    int R = 0;
    int G = 0;
    int B = 0;
};   

void connectToWiFi();
void setupRoutes();



void _parseconst();


#endif // API_H