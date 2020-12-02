#pragma once

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
    using CommandType = communication::packets::CommandType;
    using Packet = communication::packets::Packet;
public:
    FileTransferHelpers();
    int GetCommandPacket(CommandType, std::vector<std::string>, char * &);
    std::vector<std::tuple<char*,int>> GetFilePackets(std::string);
    void SendFile(std::shared_ptr<ICommunicator>, std::vector<std::tuple<char*, int>>);
    void SendCommand(std::shared_ptr<ICommunicator>, char *, int);
    PacketData Recieve(std::shared_ptr<ICommunicator>, int=64);
private:
    void RecieveFilePackets(std::shared_ptr<ICommunicator>, std::shared_ptr<Packet>, int);

    std::unique_ptr<IDataManager> data_manager;
    std::unique_ptr<IPackeExtractor> packet_extractor;
    std::unique_ptr<IPacketCreator> packet_creator;
};