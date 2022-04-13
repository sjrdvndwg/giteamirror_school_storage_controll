#include "main.h"

extern ESPTelnet telnet;
extern bool is_Debugging;

void print_debug(const char *data)
{
    if (is_Debugging)
    {
        telnet.println(data);
    }
}


void connectedClient(String ip)
{
    is_Debugging = true;
}

void connect_attempt_Client(String ip)
{
}

void reconnectedClient(String ip)
{

    is_Debugging = true;
}

void disconnectedClient(String ip)
{

    is_Debugging = false;
}

void debugdata(String data)
{
}

void setupTelnet()
{
    telnet.onConnect(connectedClient);
    telnet.onConnectionAttempt(connect_attempt_Client);
    telnet.onReconnect(reconnectedClient);
    telnet.onDisconnect(disconnectedClient);
    telnet.onInputReceived(debugdata);

    if (telnet.begin(23))
    {
        Serial.println("telnet Running");
    }
    else
    {
        Serial.println("Error.");
    }
}
