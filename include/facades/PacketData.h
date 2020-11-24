#pragma once

#include "Packet.h"
#include "CommandPacket.h"
#include "vector"
#include "string"

struct PacketData
{
    MessageType type;
    CommandType command;
    std::vector<std::string> args;
};

#endif