#include "CommandParser.h"
#include "StringToEnumNumber.h"
#include <iterator>
#include <iostream>
#include <sstream>

PacketData CommandParser::Parse(const std::string input)
{
    PacketData res;
    std::vector<std::string> split = SplitString(input);
    int command = StringToEnumNumber::StringToCommandType(split[0]);
    if(command == -1)
    {
        res.type = MessageType::file;
    }
    else
    {
        res.type = MessageType::command;
        res.command = CommandType(command);
    }

    res.args = ExtractRest(split, 1);
    
    return res;
}

std::vector<std::string> CommandParser::SplitString(const std::string input)
{
    std::istringstream iss(input);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                    std::istream_iterator<std::string>());
    return results;
}

std::vector<std::string> CommandParser::ExtractRest(const std::vector<std::string> params, int start)
{
    std::vector<std::string>::const_iterator first = params.begin() + start;
    std::vector<std::string>::const_iterator last = params.end();
    return std::vector<std::string>(first, last);
}