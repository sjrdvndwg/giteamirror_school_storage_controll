#include "main.h"

extern WebServer server;
extern CRGB leds[NUM_LEDS];

const char *SSID = "MAAKHUIS"; //! change for production
const char *PWD = "123456789"; //! change for production

extern ledData_t leddata;
extern volatile bool order;
extern Storage_t storage;
extern CRGB allcolor;

StaticJsonDocument<JSONDOCSIZE> jsonDocument;

/**
 * @brief setup wifi connections
 *
 */
void connectToWiFi()
{
  // TODO set to proper ipaddr subnet and gateway
  //  Set your Static IP address
  IPAddress local_IP(192, 168, 137, 110);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 137, 1);
  IPAddress subnet(255, 255, 255, 0);

  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.config(local_IP, gateway, subnet);
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
  // direct pin control
  server.on("/", HTTP_POST, _parseconst);
  server.on("/multiseg", HTTP_POST, _parse__MultiSeg);
  server.on("/relay", HTTP_POST, _parse_relay);

  // query data
  server.on("/get_door_number", HTTP_POST, _get_door_number);
  server.on("/set_door_and_order", HTTP_POST, _set_door);

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
  apidata_t parseddata;

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
    leddata.colors.unit0 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_0 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_0 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_0 = NONE;
    }
    break;
  case 1:
    leddata.colors.unit1 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_1 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_1 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_1 = NONE;
    }
    break;
  case 2:
    leddata.colors.unit2 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_2 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_2 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_2 = NONE;
    }
    break;
  case 3:
    leddata.colors.unit3 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_3 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_3 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_3 = NONE;
    }
    break;
  case 4:
    leddata.colors.unit4 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_4 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_4 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_4 = NONE;
    }
    break;
  case 5:
    leddata.colors.unit5 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_5 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_5 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_5 = NONE;
    }
    break;
  case 6:
    leddata.colors.unit6 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_6 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_6 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_6 = NONE;
    }
    break;
  case 7:
    leddata.colors.unit7 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_7 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_7 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_7 = NONE;
    }
    break;
  case 8:
    leddata.colors.unit8 = thing;
    if (parseddata.Type == 2)
    {
      leddata.AnimBool.unit_8 = Pulse;
    }
    else if (parseddata.Type == 1)
    {
      leddata.AnimBool.unit_8 = Flash;
    }
    else
    {
      leddata.AnimBool.unit_8 = NONE;
    }
    break;

  default:
    break;
  }

  order = true;
  server.send(200, "application/json", "{}");
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

  leddata.AnimBool.unit_0 = _get_Anim(jsonDocument["seg0T"]);
  leddata.AnimBool.unit_1 = _get_Anim(jsonDocument["seg1T"]);
  leddata.AnimBool.unit_2 = _get_Anim(jsonDocument["seg2T"]);
  leddata.AnimBool.unit_3 = _get_Anim(jsonDocument["seg3T"]);
  leddata.AnimBool.unit_4 = _get_Anim(jsonDocument["seg4T"]);
  leddata.AnimBool.unit_5 = _get_Anim(jsonDocument["seg5T"]);
  leddata.AnimBool.unit_6 = _get_Anim(jsonDocument["seg6T"]);
  leddata.AnimBool.unit_7 = _get_Anim(jsonDocument["seg7T"]);
  leddata.AnimBool.unit_8 = _get_Anim(jsonDocument["seg8T"]);

  leddata.colors.unit0 = _rgbtohex(jsonDocument["seg0r"], jsonDocument["seg0g"],
                                   jsonDocument["seg0b"]);
  leddata.colors.unit1 = _rgbtohex(jsonDocument["seg1r"], jsonDocument["seg1g"],
                                   jsonDocument["seg1b"]);
  leddata.colors.unit2 = _rgbtohex(jsonDocument["seg2r"], jsonDocument["seg2g"],
                                   jsonDocument["seg2b"]);
  leddata.colors.unit3 = _rgbtohex(jsonDocument["seg3r"], jsonDocument["seg3g"],
                                   jsonDocument["seg3b"]);
  leddata.colors.unit4 = _rgbtohex(jsonDocument["seg4r"], jsonDocument["seg4g"],
                                   jsonDocument["seg4b"]);
  leddata.colors.unit5 = _rgbtohex(jsonDocument["seg5r"], jsonDocument["seg5g"],
                                   jsonDocument["seg5b"]);
  leddata.colors.unit6 = _rgbtohex(jsonDocument["seg6r"], jsonDocument["seg6g"],
                                   jsonDocument["seg6b"]);
  leddata.colors.unit7 = _rgbtohex(jsonDocument["seg7r"], jsonDocument["seg7g"],
                                   jsonDocument["seg7b"]);
  leddata.colors.unit8 = _rgbtohex(jsonDocument["seg8r"], jsonDocument["seg8g"],
                                   jsonDocument["seg8b"]);

  order = true;
}

/**
 * @brief parse the http Post request to open the proper relay
 *
 */
void _parse_relay()
{
  server.send(200, "application/json", "{}");

  print_debug("parsing singel segment");
  if (server.hasArg("plain") == false)
    return;

  String body = server.arg("plain");
  print_debug(body);
  deserializeJson(jsonDocument, body);

  int relay = jsonDocument["relay"];
  switch (relay)
  {
  case 0:
    print_debug("printsetting relay");
    ctl_relay(RELAY_0);
    break;
  case 1:
    ctl_relay(RELAY_1);
    break;
  case 2:
    ctl_relay(RELAY_0);
    break;
  case 3:
    ctl_relay(RELAY_3);
    break;
  case 4:
    ctl_relay(RELAY_4);
    break;
  case 5:
    ctl_relay(RELAY_5);
    break;
  case 6:
    ctl_relay(RELAY_6);
    break;
  case 7:
    ctl_relay(RELAY_7);
    break;
  case 8:
    ctl_relay(RELAY_8);
    break;
  default:
    break;
  }
}

// query data
/** \addtogroup api data query functions
 *
 * @{
 *
 */
int _findfreedoor()
{
  for (int i = 0; i < 9; i++)
  {
    if (!storage.haslunch[i])
    {
      return i;
    }
  }
  return 99;
}

/**
 * @brief takes a door index and sets the storage.haslunch[door index] to false to allow a new lunchbox to be placed there
 *
 * @param doorindex
 */
void clear_door(int doorindex)
{
  storage.haslunch[doorindex] = false;
}

/**
 * @brief query the esp32 for an empty storage door.
 *
 */
void _get_door_number()
{
  char returndata[30];
  int found_number = 0;

  found_number = _findfreedoor();

  sprintf(returndata, "{\"doorNR\":%d}", found_number);
  server.send(200, "application/json", returndata);
}

/**
 * \brief assigns given order id from post request to a door seding back the doornumber and corrsponding order id if succes full, sends back 418 if it failed
 *
 *
 */
void _set_door()
{
  char dest[256];

  print_debug("setting door");

  if (server.hasArg("plain") == false)
    return;
  String body = server.arg("plain");
  deserializeJson(jsonDocument, body);
  String orderid = jsonDocument["Order_id"];
  for (int i = 0; i < 9; i++)
  {
    if (!storage.haslunch[i])
    {
      strncpy(storage.OrderId[i], orderid.c_str(), 5);
      storage.haslunch[i] = true;

      sprintf(dest, "{\"door_number\":%d, \"orderid\": \"%s\"}", i, orderid.c_str());
      server.send(200, "application/json", dest);
      return;
    }
  }
  server.send(418, "application/json", "{\"teapot\":\"coffee\"}");
}
/** @} */