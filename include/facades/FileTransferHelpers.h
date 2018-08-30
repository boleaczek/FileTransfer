#ifndef FILE_TRANSFER_HELPERS_H
#define FILE_TRANSFER_HELPERS_H

#include <vector>
#include <string>
#include <tuple>
#include "CommandPacket.h"
#include "PacketData.h"
#include "IDataManager.h"
#include "IPacketCreator.h"
#include "IPacketExtractor.h"
#include "ICommunicator.h"

class FileTransferHelpers
{
public:
    FileTransferHelpers();
    ~FileTransferHelpers();
    int GetCommandPacket(CommandType, std::vector<std::string>, char * &);
    std::vector<std::tuple<char*,int>> GetFilePackets(std::string);
    void SendFile(ICommunicator *, std::vector<std::tuple<char*, int>>);
    void SendCommand(ICommunicator *, char *, int);
    PacketData Recieve(ICommunicator *, int=550);
private:
    void RecieveFilePackets(ICommunicator *, Packet *, int);
    

    IDataManager * data_manager;
    IPackeExtractor * packet_extractor;
    IPacketCreator * packet_creator;
};

#endif