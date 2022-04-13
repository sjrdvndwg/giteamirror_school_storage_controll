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

StaticJsonDocument<JSONDOCSIZE> jsonDocument;
// char buffer[512];

void connectToWiFi()
{

    // WiFi.softAP(auth.ssid, auth.pass);
    // WiFi.softAPConfig(local_ip, gateway, subnet);
    // WiFi.hostname("ROBOT");

    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.begin(SSID, PWD);

    while (!WiFi.isConnected())
    {
        Serial.print(".");
        delay(50);
        // we can even make the ESP32 to sleep
    }

    Serial.print("Connected. IP: ");
    Serial.println(WiFi.localIP());
    setupRoutes();
}

void setupRoutes()
{
    server.on("/", HTTP_POST, _parseconst);
    server.on("/multiseg/", HTTP_POST, _parse__MultiSeg);
    server.begin();
}

uint32_t rgbtohex(uint8_t r, uint8_t g, uint8_t b)
{

    uint32_t returnval = 0;

    returnval = (r << 16 | g << 8 | b);
    return returnval;
}

Pattern _get_Anim(int animnumger)
{
    switch (animnumger)
    {
    case 0:
        return NONE;
        break;
    case 1:
        return Flash;
        break;
    case 2:
        return Pulse;
        break;

    default:
        return NONE;
        break;
    }
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
    // Serial.println(parseddata.R);
    // Serial.println(parseddata.G);
    // Serial.println(parseddata.B);
    // Serial.println(CRGB(parseddata.R, parseddata.G, parseddata.B));
    // Serial.println(rgbtohex(parseddata.R, parseddata.G, parseddata.B));
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

void _parse__MultiSeg()
{
    server.send(200, "application/json", "{}");
    Serial.println("MultiSeg");
    
    if (server.hasArg("plain") == false)
    {
        return;
    }

    String body = server.arg("plain");
    deserializeJson(jsonDocument, body);

    animated_units.unit_0 = _get_Anim(jsonDocument["seg0T"]);
    animated_units.unit_1 = _get_Anim(jsonDocument["seg1T"]);
    animated_units.unit_2 = _get_Anim(jsonDocument["seg2T"]);
    animated_units.unit_3 = _get_Anim(jsonDocument["seg3T"]);
    animated_units.unit_4 = _get_Anim(jsonDocument["seg4T"]);
    animated_units.unit_5 = _get_Anim(jsonDocument["seg5T"]);
    animated_units.unit_6 = _get_Anim(jsonDocument["seg6T"]);
    animated_units.unit_7 = _get_Anim(jsonDocument["seg7T"]);
    animated_units.unit_8 = _get_Anim(jsonDocument["seg8T"]);


    colors.unit0 = rgbtohex(jsonDocument["seg0r"], jsonDocument["seg0g"], jsonDocument["seg0b"]);
    colors.unit1 = rgbtohex(jsonDocument["seg1r"], jsonDocument["seg1g"], jsonDocument["seg1b"]);
    colors.unit2 = rgbtohex(jsonDocument["seg2r"], jsonDocument["seg2g"], jsonDocument["seg2b"]);
    colors.unit3 = rgbtohex(jsonDocument["seg3r"], jsonDocument["seg3g"], jsonDocument["seg3b"]);
    colors.unit4 = rgbtohex(jsonDocument["seg4r"], jsonDocument["seg4g"], jsonDocument["seg4b"]);
    colors.unit5 = rgbtohex(jsonDocument["seg5r"], jsonDocument["seg5g"], jsonDocument["seg5b"]);
    colors.unit6 = rgbtohex(jsonDocument["seg6r"], jsonDocument["seg6g"], jsonDocument["seg6b"]);
    colors.unit7 = rgbtohex(jsonDocument["seg7r"], jsonDocument["seg7g"], jsonDocument["seg7b"]);
    colors.unit8 = rgbtohex(jsonDocument["seg8r"], jsonDocument["seg8g"], jsonDocument["seg8b"]);


    order = true;
}