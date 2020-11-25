#ifndef STRING_TO_ENUM_NUMBER
#define STRING_TO_ENUM_NUMBER

#include <map>
#include <string>

#include "CommandPacket.h"
#include "Packet.h"

class StringToEnumNumber
{
public:
    static MessageType StringToMessageType(const std::string &);
    static CommandType StringToCommandType(const std::string &);
    static std::string CommandTypeToString(const CommandType);
    static std::string MessageTypeToString(const MessageType);
private:
    static int GetEnum(const std::string, const std::string[], int);

    static std::map<MessageType, std::string> message_type_array;
    static std::map<CommandType, std::string> command_type_array;
    static const int command_types_n = 7;
    static const int message_types_n = 2;
};

#endif