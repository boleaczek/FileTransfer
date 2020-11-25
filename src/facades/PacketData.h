#pragma once

#include "CommandPacket.h"
#include "Packet.h"
#include "string"
#include "vector"

struct PacketData
{
    MessageType type;
    CommandType command;
    std::vector<std::string> args;
};