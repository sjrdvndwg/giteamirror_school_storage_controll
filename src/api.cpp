#include "main.h"

extern WebServer server;
extern CRGB leds[NUM_LEDS];
const char *SSID = "VoorhuisGuest";
const char *PWD = "voorhuiswlangast";

apidata_t parseddata;
extern animated_t animated_units;
extern unit_colors_t colors;
extern volatile bool order;
extern CRGB allcolor;

// wifiCreds auth= {"Robot", "Robot-pass"};

// IP Address details
// IPAddress local_ip(192, 168, 1  , 1);
// IPAddress gateway(192, 168, 1, 1);
// IPAddress subnet(255, 255, 255, 0);

StaticJsonDocument<512> jsonDocument;
// char buffer[512];

void connectToWiFi()
{

    // WiFi.softAP(auth.ssid, auth.pass);
    // WiFi.softAPConfig(local_ip, gateway, subnet);
    // WiFi.hostname("ROBOT");

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
    setupRoutes();
}

void setupRoutes()
{
    server.on("/", HTTP_POST, _parseconst);
    server.begin();
}

uint32_t rgbtohex(uint8_t r,uint8_t g,uint8_t b){

    uint32_t returnval = 0;

    returnval = (r << 16 | g << 8 | b);
    return returnval;
}

void _parseconst()
{
    server.send(200, "application/json", "{}");

    Serial.println("parsing");
    if (server.hasArg("plain") == false)
        return;

    String body = server.arg("plain");
    Serial.println(body);
    deserializeJson(jsonDocument, body);
    int segment = jsonDocument["Segment"];
    parseddata.Type = jsonDocument["Type"]; // 0 solid 1 blink 2 pulse
    parseddata.R = jsonDocument["R"];
    parseddata.G = jsonDocument["G"];
    parseddata.B = jsonDocument["B"];
    uint32_t thing = rgbtohex(parseddata.R, parseddata.G, parseddata.B);
    allcolor = rgbtohex(parseddata.R, parseddata.G, parseddata.B);
    Serial.println(parseddata.R);
    Serial.println(parseddata.G);
    Serial.println(parseddata.B);
    // Serial.println(CRGB(parseddata.R, parseddata.G, parseddata.B));
    Serial.println(rgbtohex(parseddata.R, parseddata.G, parseddata.B));
    switch (segment)
    {
    case 0:
        colors.unit0 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_0 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_0 = Flash;
        }
        else
        {
            animated_units.unit_0 = NONE;
        }
        break;
    case 1:
        colors.unit1 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_1 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_1 = Flash;
        }
        else
        {
            animated_units.unit_1 = NONE;
        }
        break;
    case 2:
        colors.unit2 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_2 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_2 = Flash;
        }
        else
        {
            animated_units.unit_2 = NONE;
        }
        break;
    case 3:
        colors.unit3 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_3 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_3 = Flash;
        }
        else
        {
            animated_units.unit_3 = NONE;
        }
        break;
    case 4:
        colors.unit4 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_4 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_4 = Flash;
        }
        else
        {
            animated_units.unit_4 = NONE;
        }
        break;
    case 5:
        colors.unit5 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_5 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_5 = Flash;
        }
        else
        {
            animated_units.unit_5 = NONE;
        }
        break;
    case 6:
        colors.unit6 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_6 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_6 = Flash;
        }
        else
        {
            animated_units.unit_6 = NONE;
        }
        break;
    case 7:
        colors.unit7 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_7 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_7 = Flash;
        }
        else
        {
            animated_units.unit_7 = NONE;
        }
        break;
    case 8:
        colors.unit8 = thing;
        if (parseddata.Type == 2)
        {
            animated_units.unit_8 = Pulse;
        }
        else if (parseddata.Type == 1)
        {
            animated_units.unit_8 = Flash;
        }
        else
        {
            animated_units.unit_8 = NONE;
        }
        break;

    default:
        break;
    }

    order = true;
}