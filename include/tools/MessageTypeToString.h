#ifndef MESSAGE_TYPE_TO_STRING_H
#define MESSAGE_TYPE_TO_STRING_H

#include <string>
#include "Packets.h"

class MessageTypeToString
{
public:
    static int Convert(const std::string);
private:
    static std::string MessageTypeArray[4];
};

#endif