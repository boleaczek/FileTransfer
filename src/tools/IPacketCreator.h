#ifndef I_PACKET_CREATOR_H
#define I_PACKET_CREATOR_H

#include "Packet.h"
#include "CommandPacket.h"
#include <vector>
#include <tuple>

class IPacketCreator
{
public:
    virtual int CreateCommandPacket(CommandType, std::vector<std::string> args, char * &) = 0;
    virtual std::vector<std::tuple<char*,int>> CreateFilePackets(std::string) = 0;
};

#endif