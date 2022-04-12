#include "main.h"



extern WebServer server;

// const char *SSID = "MAAKHUIS";
// const char *PWD = "123456789";

apidata_t parseddata;
extern animated_t animated_units;
extern unit_colors_t colors;

wifiCreds auth= {"Robot", "Robot-pass"};

// IP Address details
IPAddress local_ip(192, 168, 1  , 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

StaticJsonDocument<512> jsonDocument;
// char buffer[512];

void connectToWiFi()
{

    WiFi.softAP(auth.ssid, auth.pass);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    WiFi.hostname("ROBOT");


    // Serial.print("Connecting to ");
    // Serial.println(SSID);

    // WiFi.begin(SSID, PWD);

    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     Serial.print(".");
    //     delay(500);
    //     // we can even make the ESP32 to sleep
    // }

    // Serial.print("Connected. IP: ");
    // Serial.println(WiFi.localIP());
    setupRoutes();
}

void setupRoutes()
{
    server.on("/", HTTP_POST, _parseconst);
    server.begin();
    
}

void _parseconst()
{
    server.send(200, "application/json", "{}");

    Serial.println("parsing");
    if (server.hasArg("plain") == false)
        return;

    String body = server.arg("plain");
    deserializeJson(jsonDocument, body);
    int segment = jsonDocument["Segment"];
    parseddata.Type = jsonDocument["Type"]; // 0 solid 1 blink 2 pulse
    parseddata.R = jsonDocument["r"];
    parseddata.G = jsonDocument["g"];
    parseddata.B = jsonDocument["b"];
    auto thing = CRGB(parseddata.R, parseddata.G, parseddata.B);
 
    switch (segment)
    {
    case 0:
        colors.unit0 = thing;
        break;
    case 1:
        colors.unit0 = thing;
        break;
    case 2:
        colors.unit0 = thing;
        break;
    case 3:
        colors.unit0 = thing;
        break;
    case 4:
        colors.unit0 = thing;
        break;
    case 5:
        colors.unit0 = thing;
        break;
    case 6:
        colors.unit0 = thing;
        break;
    case 7:
        colors.unit0 = thing;
        break;
    case 8:
        colors.unit0 = thing;
        break;
    default:

        break;
    }


}