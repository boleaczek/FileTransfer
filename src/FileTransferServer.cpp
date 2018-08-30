#include "FileTransferServer.h"
#include "Server.h"
#include "DataManager.h"
#include "PacketExtractor.h"
#include "PacketCreator.h"

FileTransferServer::FileTransferServer(std::string ip, std::string port)
{
    this->communicator = new Server(ip, port); 
    this->data_manager = new DataManager();
    this->packet_creator = new PacketCreator();
    this->packet_extractor = new PacketExtractor();
}
