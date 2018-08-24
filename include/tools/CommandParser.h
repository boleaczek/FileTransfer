#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
#include <Packets.h>
#include "ICommandParser.h"

class CommandParser : ICommandParser
{
public:
    virtual ParsingResult Parse(const std::string) override;
private:
    std::vector<std::string> SplitString(const std::string);
    MessageType GetMessageType(const std::string);
    std::vector<std::string> ExtractRest(const std::vector<std::string>);
};

#endif