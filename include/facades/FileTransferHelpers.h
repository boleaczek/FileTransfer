#ifndef FILE_TRANSFER_HELPERS_H
#define FILE_TRANSFER_HELPERS_H

#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "CommandPacket.h"
#include "ICommunicator.h"
#include "IDataManager.h"
#include "IPacketCreator.h"
#include "IPacketExtractor.h"
#include "PacketData.h"

class FileTransferHelpers
{
public:
    FileTransferHelpers();
    ~FileTransferHelpers();
    int GetCommandPacket(CommandType, std::vector<std::string>, char * &);
    std::vector<std::tuple<char*,int>> GetFilePackets(std::string);
    void SendFile(std::shared_ptr<ICommunicator>, std::vector<std::tuple<char*, int>>);
    void SendCommand(std::shared_ptr<ICommunicator>, char *, int);
    PacketData Recieve(std::shared_ptr<ICommunicator>, int=64);
private:
    void RecieveFilePackets(std::shared_ptr<ICommunicator>, Packet *, int);

    IDataManager * data_manager;
    IPackeExtractor * packet_extractor;
    IPacketCreator * packet_creator;
};

#endif