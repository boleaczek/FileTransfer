#include "StringToEnumNumber.h"
#include "CommandPacket.h"

std::string StringToEnumNumber::message_type_array[2] = {"file","command"};
std::string StringToEnumNumber::command_type_array[3] = {"remove","move","list"};

const int message_types_n = 4;

int StringToEnumNumber::StringToMessageType(const std::string message_string)
{
    return GetEnum(message_string, message_type_array, 2);
}

int StringToEnumNumber::StringToCommandType(const std::string message_string)
{
    return GetEnum(message_string, command_type_array, 3);
}

int StringToEnumNumber::GetEnum(const std::string message_string, const std::string type_array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(type_array[i] == message_string)
        {
            return i;
        }
    }
    return -1;
}