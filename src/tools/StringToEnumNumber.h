#pragma once

#include <map>
#include <string>

#include "CommandPacket.h"
#include "Packet.h"

using CommandType = communication::packets::CommandType;
using MessageType = communication::packets::MessageType;

class StringToEnumNumber
{
public:
    static MessageType StringToMessageType(const std::string&);
    static CommandType StringToCommandType(const std::string&);
    static std::string CommandTypeToString(const CommandType commandType);
    static std::string MessageTypeToString(const MessageType messageType);
private:
    template<typename T>
    static std::string enumVariantToString(T enumVariant, const std::map<std::string, T>& valuesMap);

    static std::map<std::string, CommandType> command_type_map;
    static std::map<std::string, MessageType> message_type_map;
};