#ifndef PACKET_CREATOR_H
#define PACKET_CREATOR_H

#include "IPacketCreator.h"
#include "IDataPacker.h"
#include<unordered_map>
#include<functional>

class PacketCreator : public IPacketCreator
{
public:
    PacketCreator(IDataPacker *);
    virtual char * CreateCommandPacket(MessageType, std::vector<std::string> args) override;
    virtual std::vector<char*> GetFilePackets(std::string) override;
private:
    void ValidArgs(int, int);
    char * CopyStrToCharPtr(std::string);

    IDataPacker * data_packer;
    std::unordered_map<MessageType, 
        std::function<InnerPacket *(std::vector<std::string>)>> command_creator_function;
};

#endif