#include "main.h"
#include <String>
#include <vector>

extern ESPTelnet telnet;
extern bool is_Debugging;

/**
 * @brief Telnet debugging fuction
 *
 * @param data
 */
void print_debug(const char *data)
{
    if (is_Debugging)
    {
        telnet.println(data);
    }
}

/**
 * @brief Telnet debugging fuction
 *
 * @param data
 */
void print_debug(const String data)
{
    if (is_Debugging)
    {
        // const char *tmp = data.c_str();
        telnet.println(data.c_str());
    }
}

inline bool __compare(const char *str1, const char *str2, int lenght)
{
    if (strncmp(str1, str2, lenght) == 0)
    {
        return true;
    }
    else
    {
        return false;
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
