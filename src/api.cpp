#include "main.h"

extern WebServer server;

const char *SSID = "maakhuis";
const char *PWD = "password";

apidata_t parseddata;
extern animated_t animated_units;
extern unit_colors_t colors;

StaticJsonDocument<512> jsonDocument;
// char buffer[512];

void connectToWiFi()
{
    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.begin(SSID, PWD);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
        // we can even make the ESP32 to sleep
    }

    Serial.print("Connected. IP: ");
    Serial.println(WiFi.localIP());
}

void setupRoutes()
{
    server.on("/constant", HTTP_POST, _parseconst);
}

void _parseconst()
{
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


    server.send(200, "application/json", "{}");
}