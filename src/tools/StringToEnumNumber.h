#ifndef STRING_TO_ENUM_NUMBER
#define STRING_TO_ENUM_NUMBER

#include <string>
#include "Packet.h"

class StringToEnumNumber
{
public:
    static int StringToMessageType(const std::string);
    static int StringToCommandType(const std::string);
    static std::string CommandTypeToString(const int);
    static std::string MessageTypeToString(const int);
private:
    static int GetEnum(const std::string, const std::string[], int);

    static std::string message_type_array[2];
    static std::string command_type_array[7];
    static const int command_types_n = 7;
    static const int message_types_n = 2;
};

#endif