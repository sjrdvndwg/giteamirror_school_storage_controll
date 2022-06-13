#ifndef MODBUS_H
#define MODBUS_H

#include "main.h"

// function protos
void _handleData(ModbusMessage response, uint32_t token);
void _handleError(Error error, uint32_t token);



#endif //MODBUS_H