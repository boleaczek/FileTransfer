#ifndef I_COMMAND_PARSER_H
#define I_COMMAND_PARSER_H

#include <string>
#include <vector>
#include "PacketData.h"

class ICommandParser
{
public:
    virtual PacketData Parse(const std::string) = 0;
};

#endif