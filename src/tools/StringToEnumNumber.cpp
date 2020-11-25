#include <algorithm>

#include "StringToEnumNumber.h"

std::map<MessageType, std::string> StringToEnumNumber::message_type_array = {{MessageType::file, "file"}, {MessageType::command, "command"}};
std::map<CommandType, std::string> StringToEnumNumber::command_type_array = 
{
    {CommandType::remove_file, "remove_file"},
    {CommandType::move, "move"},
    {CommandType::list, "list"},
    {CommandType::ping, "ping"},
    {CommandType::response, "response"},
    {CommandType::end_connection, "end_connection"},
    {CommandType::get, "get"}
};

MessageType StringToEnumNumber::StringToMessageType(const std::string & message_string)
{
    auto commandNumber = std::find_if(message_type_array.cbegin(), message_type_array.cend(),
        [message_string](auto keyVal) -> bool {
            return keyVal.second == message_string;
        });
    return commandNumber->first;
}

CommandType StringToEnumNumber::StringToCommandType(const std::string & message_string)
{
    auto commandNumber = std::find_if(command_type_array.cbegin(), command_type_array.cend(),
        [message_string](auto keyVal) -> bool {
            return keyVal.second == message_string;
        });
    return commandNumber->first;
}

std::string StringToEnumNumber::MessageTypeToString(const MessageType type)
{
    return message_type_array[type];
}

std::string StringToEnumNumber::CommandTypeToString(const CommandType type)
{
    return command_type_array[type];
}