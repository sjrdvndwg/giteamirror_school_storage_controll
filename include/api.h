#ifndef API_H
#define API_H

struct apidata_t{
    int Type = 0;
    int R = 0;
    int G = 0;
    int B = 0;
};

/**
 * @brief struct for wifi ssid's and corresponding passwords
 * @param ssid network ssid
 * @param pass is the password for the wifi net work
 * */
struct wifiCreds
{
    const char *ssid;
    const char *pass;
};

void connectToWiFi();
void setupRoutes();



void _parseconst();


#endif // API_H