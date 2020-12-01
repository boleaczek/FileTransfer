#include <algorithm>

#include "StringToEnumNumber.h"
#include "CommandPacket.h"

std::map<std::string, MessageType> StringToEnumNumber::message_type_map = {{"file", MessageType::file}, {"command", MessageType::command}};
std::map<std::string, CommandType> StringToEnumNumber::command_type_map = 
    {{"remove", CommandType::remove_file},
    {"move", CommandType::move},
    {"list", CommandType::list},
    {"ping", CommandType::ping},
    {"response", CommandType::response},
    {"exit", CommandType::end_connection},
    {"get", CommandType::get}};

MessageType StringToEnumNumber::StringToMessageType(const std::string& message_string)
{
    return message_type_map[message_string];
}

CommandType StringToEnumNumber::StringToCommandType(const std::string& command_string)
{
    return command_type_map[command_string];
}

std::string StringToEnumNumber::MessageTypeToString(MessageType messageType)
{
    return enumVariantToString(messageType, message_type_map);
}

std::string StringToEnumNumber::CommandTypeToString(CommandType commandType)
{
    return enumVariantToString(commandType, command_type_map);
}

template<typename T>
std::string StringToEnumNumber::enumVariantToString(T enumVariant, const std::map<std::string, T>& valuesMap)
{
    auto valueEnumVariant = std::find_if(valuesMap.cbegin(), valuesMap.cend(), [&enumVariant] (auto keyval) {
        return keyval.second == enumVariant;
    });

    return valueEnumVariant->first;
}