#ifndef FILE_TRANSFER_FACADE_H
#define FILE_TRANSFER_FACADE_H

#include <memory>
#include <tuple>
#include <vector>

#include "CommandPacket.h"
#include "FileTransferHelpers.h"
#include "ICommunicatorCreator.h"
#include "IDataManager.h"
#include "IFileTransferClient.h"
#include "IPacketCreator.h"
#include "IPacketExtractor.h"
#include "Packet.h"

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