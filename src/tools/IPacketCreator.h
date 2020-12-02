#pragma once

#include <tuple>
#include <vector>

#include "CommandPacket.h"
#include "Packet.h"

class IPacketCreator
{
public:
    virtual int CreateCommandPacket(communication::packets::CommandType, std::vector<std::string> args, char * &) = 0;
    virtual std::vector<std::tuple<char*,int>> CreateFilePackets(std::string) = 0;
};