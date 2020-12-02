#pragma once

#include "CommandPacket.h"
#include "Packet.h"
#include "string"
#include "vector"

struct PacketData
{
    communication::packets::MessageType type;
    communication::packets::CommandType command;
    std::vector<std::string> args;
};