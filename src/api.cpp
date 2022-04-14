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



StaticJsonDocument<JSONDOCSIZE> jsonDocument;

/**
 * @brief setup wifi connections
 * 
 */
void connectToWiFi()
{
    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.begin(SSID, PWD);

    while (!WiFi.isConnected())
    {
        Serial.print(".");
        delay(100);
    }

    Serial.print("Connected. IP: ");
    Serial.println(WiFi.localIP());
    setupRoutes();
}

/**
 * @brief setup routes
 * 
 */
void setupRoutes()
{
    server.on("/", HTTP_POST, _parseconst);
    server.on("/multiseg/", HTTP_POST, _parse__MultiSeg);
    server.begin();
}

/**
 * @brief create proper uint24 value from r, g and b component
 * 
 * @param r 
 * @param g 
 * @param b 
 * @return uint32_t 
 */
uint32_t _rgbtohex(uint8_t r, uint8_t g, uint8_t b)
{

    uint32_t returnval = 0;

    returnval = (r << 16 | g << 8 | b);
    return returnval;
}

/**
 * @brief get anim type from number
 * 
 * @param animnumger 
 * @return Pattern 
 */
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


/**
 * @brief parse single segment
 * 
 */
void _parseconst()
{
    server.send(200, "application/json", "{}");

    print_debug("parsing singel segment");
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
    uint32_t thing = _rgbtohex(parseddata.R, parseddata.G, parseddata.B);
    allcolor = _rgbtohex(parseddata.R, parseddata.G, parseddata.B);
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

/**
 * @brief set all segments to the specified color in the json doc
 * 
 */
void _parse__MultiSeg()
{
    server.send(200, "application/json", "{}");
    print_debug("parsing multisegment data");

    if (server.hasArg("plain") == false)
    {
        return;
    }

    String body = server.arg("plain");
    print_debug(body);
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

    colors.unit0 = _rgbtohex(jsonDocument["seg0r"], jsonDocument["seg0g"], jsonDocument["seg0b"]);
    colors.unit1 = _rgbtohex(jsonDocument["seg1r"], jsonDocument["seg1g"], jsonDocument["seg1b"]);
    colors.unit2 = _rgbtohex(jsonDocument["seg2r"], jsonDocument["seg2g"], jsonDocument["seg2b"]);
    colors.unit3 = _rgbtohex(jsonDocument["seg3r"], jsonDocument["seg3g"], jsonDocument["seg3b"]);
    colors.unit4 = _rgbtohex(jsonDocument["seg4r"], jsonDocument["seg4g"], jsonDocument["seg4b"]);
    colors.unit5 = _rgbtohex(jsonDocument["seg5r"], jsonDocument["seg5g"], jsonDocument["seg5b"]);
    colors.unit6 = _rgbtohex(jsonDocument["seg6r"], jsonDocument["seg6g"], jsonDocument["seg6b"]);
    colors.unit7 = _rgbtohex(jsonDocument["seg7r"], jsonDocument["seg7g"], jsonDocument["seg7b"]);
    colors.unit8 = _rgbtohex(jsonDocument["seg8r"], jsonDocument["seg8g"], jsonDocument["seg8b"]);

    order = true;
}
