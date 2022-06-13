#include "main.h"
#include <String>
#include <vector>
using namespace std;

extern ESPTelnet telnet;
extern bool is_Debugging;
char **printqueue; 
uint8_t printqueue_pos = 0;

inline void _display_prompt(){
  telnet.print("\n>>");
}


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
        const char *tmp = data.c_str();
        telnet.println(tmp);
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

inline bool __compare(const char * str1, const char *str2, int lenght){
    if(strncmp(str1,str2,lenght) == 0){
        return true;
    }
    else{
        return false;
    }
}

void _parse_CMD(String data){//TODO fix this function the sub values for the led and for the color arn't seperated
    String secdata = data;

    Serial.println(data.indexOf(' ', 0));
    int end1 = data.indexOf(' ', 0);
    int end2 = data.indexOf(' ', end1+1);
    // int end3 = data.indexOf(' ', end2+1);
    Serial.print(end1);
    Serial.print(end2);
    // Serial.print(end3);


    if (__compare("set-led", data.c_str(), 8))
    {

        String led_index=secdata.substring(8,9);
        print_debug(data);
        String color = data.substring(10);
        int led_indexval=led_index.toInt();
        if (led_indexval >27)
        {
            led_indexval = 27;
        }else if (led_indexval<0)
        {
            led_indexval = 0;
        }
        print_debug(led_index);
        print_debug(color);

        long colorval =color.toInt();
        setLed(led_indexval,CRGB(colorval));
        _display_prompt();
    }
    else if (__compare("set-unit 0 12345678", data.c_str(),9))
    {
        
        String unit_index=data.substring(8,9);
        String color = data.substring(10);
        int unit_indexval=unit_index.toInt();
        if (unit_indexval >9)
        {
            unit_indexval = 9;
        }else if (unit_indexval<0)
        {
            unit_indexval = 0;
        }
        print_debug(unit_index);
        print_debug(color);

        long colorval =color.toInt();
        setLed(unit_indexval,CRGB(colorval));
        _display_prompt();

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
  telnet.println(data);
  _parse_CMD(data);
  telnet.print(">>");
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
