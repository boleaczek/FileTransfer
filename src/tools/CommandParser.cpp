#include "CommandParser.h"
#include "MessageTypeToString.h"
#include "Packets.h"
#include <iterator>
#include <iostream>
#include <sstream>

ParsingResult CommandParser::Parse(const std::string input)
{
    ParsingResult res;
    std::vector<std::string> split = SplitString(input);
    res.type = GetMessageType(split[0]);
    res.rest = ExtractRest(split);

    return res;
}

MessageType CommandParser::GetMessageType(const std::string type_string)
{
    return MessageType(
        MessageTypeToString::Convert(type_string));
}

std::vector<std::string> CommandParser::SplitString(const std::string input)
{
    std::istringstream iss(input);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                    std::istream_iterator<std::string>());
    return results;
}

std::vector<std::string> CommandParser::ExtractRest(const std::vector<std::string> params)
{
    std::vector<std::string>::const_iterator first = params.begin() + 1;
    std::vector<std::string>::const_iterator last = params.end();
    return std::vector<std::string>(first, last);
}