#ifndef FILE_TRANSFER_SERVER_H
#define FILE_TRANSFER_SERVER_H

#include <string>
#include "IDataManager.h"
#include "IServer.h"
#include "IPacketExtractor.h"
#include "IPacketCreator.h"

class FileTransferServer
{
public:
    FileTransferServer(std::string, std::string);
    ~FileTransferServer();
    void Start();
private:
    IServer * communicator;
    IDataManager * data_manager;
    IPackeExtractor * packet_extractor;
    IPacketCreator * packet_creator;
};

#endif