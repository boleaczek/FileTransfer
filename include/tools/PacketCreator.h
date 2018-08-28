#ifndef PACKET_CREATOR_H
#define PACKET_CREATOR_H

#include "IPacketCreator.h"
#include "Packet.h"
#include <unordered_map>
#include <functional>

class PacketCreator : public IPacketCreator
{
public:
    PacketCreator();
    virtual int CreateCommandPacket(CommandType, std::vector<std::string> args, char * &) override;
    virtual std::vector<std::tuple<char*,int>> CreateFilePackets(std::string) override;
private:
    void ValidArgs(int, int);
    char * CopyStrToCharPtr(std::string);

    std::unordered_map<CommandType, 
        std::function<Packet *(std::vector<std::string>)>> command_creator_fucntions;
};

#endif