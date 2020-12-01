#include "CommandParser.h"
#include "StringToEnumNumber.h"
#include <iterator>
#include <sstream>
#include <iostream>

PacketData CommandParser::Parse(const std::string input)
{
    const std::string fileCommand = "file";

    PacketData res;
    std::vector<std::string> split = SplitString(input);

    if(split[0] == fileCommand)
    {
        res.type = MessageType::file;
    }
    else
    {
        auto command = StringToEnumNumber::StringToCommandType(split[0]);
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