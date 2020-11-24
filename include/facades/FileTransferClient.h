#ifndef FILE_TRANSFER_FACADE_H
#define FILE_TRANSFER_FACADE_H

#include <memory>
#include <vector>
#include <tuple>
#include "Packet.h"
#include "CommandPacket.h"
#include "FileTransferHelpers.h"
#include "IFileTransferClient.h"
#include "ICommunicatorCreator.h"
#include "IDataManager.h"
#include "IPacketCreator.h"
#include "IPacketExtractor.h"

class FileTransferClient : public IFileTransferClient
{
public:
    FileTransferClient();
    ~FileTransferClient();
    virtual void Start(std::string, std::string) override;
    virtual void Stop() override;
    virtual void SendPacket(PacketData) override;
    virtual PacketData Recieve() override;
private:
    FileTransferHelpers helpers;
    std::shared_ptr<ICommunicator> communicator;
    std::unique_ptr<ICommunicatorCreator> communicator_creator;
};

#endif