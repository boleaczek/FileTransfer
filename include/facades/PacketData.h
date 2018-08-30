#ifndef PACKET_DATA_H
#define PACKET_DATA_H

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