#include "main.h"

extern ESPTelnet telnet;
extern bool is_Debugging;
char printqueue[32][128];
uint8_t printqueue_pos = 0;

void print_debug(const char *data)
{
    if (is_Debugging)
    {
        telnet.println(data);
    }
}

void print_debug(const String data)
{
    if (is_Debugging)
    {
        telnet.println(data);
    }
}

void _sanitize_queue()
{
    for (size_t i = 0; i < printqueue_pos; i++)
    {
        memset(printqueue[printqueue_pos], 0x00, 128);
        // strcpy(printqueue[printqueue_pos], "");
        printqueue_pos = 0;
    }
}

void print_debug_queue(const char *data)
{
    strcpy(printqueue[printqueue_pos], data);
    printqueue_pos++;
    if (printqueue_pos == 32)
    {
        _sanitize_queue();
        
    }
    
}

/**
 * @brief calback func
 *
 * @param ip
 */
void connectedClient(String ip)
{
    is_Debugging = true;
    for (size_t i = 0; i < printqueue_pos; i++)
    {
        print_debug(printqueue[printqueue_pos]);
    }
    _sanitize_queue();
}

/**
 * @brief calback func
 *
 * @param ip
 */
void connect_attempt_Client(String ip)
{
}

/**
 * @brief calback func
 *
 * @param ip
 */
void reconnectedClient(String ip)
{

    is_Debugging = true;
}

/**
 * @brief calback func
 *
 * @param ip
 */
void disconnectedClient(String ip)
{

    is_Debugging = false;
}

/**
 * @brief calback on data recieved
 *
 * @param data
 */
void debugdata(String data)
{
    telnet.print("datais:");
    telnet.print(data);
    telnet.println(data.startsWith("bye"));
    if (strncmp("bye", data.c_str(), 3) == 0)
    {
        telnet.print("fuck you");
    }
}

/**
 * @brief setup Telnet connection for debugging purposes
 *
 */
bool setupTelnet()
{
    telnet.onConnect(connectedClient);
    telnet.onConnectionAttempt(connect_attempt_Client);
    telnet.onReconnect(reconnectedClient);
    telnet.onDisconnect(disconnectedClient);
    telnet.onInputReceived(debugdata);

    if (telnet.begin(23))
    {
        Serial.println("telnet Running");
        return true;
    }
    else
    {
        Serial.println("Error.");
        return false;
    }
}
