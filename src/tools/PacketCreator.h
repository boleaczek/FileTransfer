#ifndef PACKET_CREATOR_H
#define PACKET_CREATOR_H

#include "IPacketCreator.h"
#include "Packet.h"
#include "FilePacket.h"
#include "IDataManager.h"
#include "DataManager.h"
#include <unordered_map>
#include <functional>

class PacketCreator : public IPacketCreator
{
    using CommandType = communication::packets::CommandType;
    using Packet = communication::packets::Packet;
public:
    PacketCreator(int=32, int=32);
    virtual int CreateCommandPacket(CommandType, std::vector<std::string> args, char * &) override;
    virtual std::vector<std::tuple<char*,int>> CreateFilePackets(std::string) override;
private:
    void ValidArgs(int, int);
    int GetChunkSize(int, int);
    int GetBytesFromStream(std::stringstream &, char * &);
    char * GetChunk(char *, int, int);
    int GetPaddingLength(int);

    std::unordered_map<CommandType, 
        std::function<Packet *(std::vector<std::string>)>> command_creator_functions;
    IDataManager * data_manager;
    int max_chunk_size;
    int max_meta_size;
};

#endif