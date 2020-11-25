#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
#include "ICommandParser.h"

class CommandParser : public ICommandParser
{
public:
    virtual PacketData Parse(const std::string) override;
private:
    std::vector<std::string> SplitString(const std::string);
    std::vector<std::string> ExtractRest(const std::vector<std::string>, int);
};

#endif