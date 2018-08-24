#ifndef I_COMMAND_PARSER_H
#define I_COMMAND_PARSER_H

#include <string>
#include <vector>
#include "Packets.h"

class ICommandParser
{
public:
    virtual ParsingResult Parse(const std::string) = 0;
};

struct ParsingResult
{
    MessageType type;
    std::vector<std::string> rest;
};

#endif