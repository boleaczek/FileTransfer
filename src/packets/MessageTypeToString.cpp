#include "MessageTypeToString.h"

std::string MessageTypeToString::MessageTypeArray[4] = {"file","remove","move","list"};

const int message_types_n = 4;

int MessageTypeToString::Convert(const std::string message_string)
{
    for(int i = 0; i < message_types_n; i++)
    {
        if(MessageTypeArray[i] == message_string)
        {
            return MessageType(i);
        }
    }
    return -1;
}