#include "main.h"

IPAddress ip = {192, 168, 11, 77}; // IP address of modbus server
uint16_t port = 502;

ModbusClientTCPasync MB(ip, port);

// Define an onData handler function to receive the regular responses
// Arguments are Modbus server ID, the function code requested, the message data and length of it,
// plus a user-supplied token to identify the causing request
void _handleData(ModbusMessage response, uint32_t token)
{
    Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
    Serial.printf("byteamount is: %d \n", response[2]);
    for (auto &byte : response)
    {
        Serial.printf("%02X ", byte);
    }
    Serial.println("");
}

// Define an onError handler function to receive error responses
// Arguments are the error code returned and a user-supplied token to identify the causing request
void _handleError(Error error, uint32_t token)
{
    // ModbusError wraps the error code and provides a readable error message for it
    ModbusError me(error);
    char str[128];
    sprintf(str, "Error response: %02X - %s token: %d\n", (int)me, (const char *)me, token);
    print_debug(str);
}
void setup_Modbus(void)
{
    // Set up ModbusTCP client.
    // - provide onData handler function
    MB.onDataHandler(&_handleData);
    // - provide onError handler function
    MB.onErrorHandler(&_handleError);
    // Set message timeout to 2000ms and interval between requests to the same host to 200ms
    MB.setTimeout(10000);
    // Start ModbusTCP background task
    MB.setIdleTimeout(60000);
}
void MB_make_request()
{
    static unsigned long lastMillis = millis();
    char str[128];

    sprintf(str,"sending request with token %d\n", (uint32_t)lastMillis);
    print_debug(str);

    Error err;
    err = MB.addRequest((uint32_t)lastMillis, 1, READ_HOLD_REGISTER, 1, 4);
    if (err != SUCCESS)
    {
        ModbusError e(err);
        sprintf(str,"Error creating request: %02X - %s\n", (int)e, (const char *)e);
        print_debug(str);
    }
}