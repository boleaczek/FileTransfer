#pragma once

#include <string>
#include <vector>

#include "PacketData.h"

class ICommandParser
{
public:
    virtual PacketData Parse(const std::string) = 0;
};