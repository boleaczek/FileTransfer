#include "FileTransferClient.h"
#include "CommunicatorCreator.h"
#include "DataManager.h"
#include "PacketCreator.h"
#include "PacketExtractor.h"
#include "ICommunicator.h"

void FileTransferClient::Start(std::string ip, std::string port)
{
    this->communicator = this->communicator_creator->BuildClient(ip, port);
    communicator->Start();
}

void FileTransferClient::Stop()
{
    if(this->communicator != nullptr)
    {
        this->communicator->Stop();
    }

    delete this->communicator;
}

std::string FileTransferClient::SendPacket(PacketData data)
{
    if(data.type == MessageType::command)
    {
        char * packet;
        int len = this->helpers.GetCommandPacket(data.command, data.args, packet);
        this->helpers.SendCommand(this->communicator, packet, len);
        delete[] packet;
    }
    else if(data.type == MessageType::file)
    {
        std::vector<std::tuple<char*, int>> packets = this->helpers.GetFilePackets(data.args[0]);
        this->helpers.SendFile(this->communicator, packets);
    }

    return "DONE";
}

FileTransferClient::FileTransferClient()
{
    this->communicator_creator = new CommunicatorCreator();
}

FileTransferClient::~FileTransferClient()
{
    this->Stop();
    delete this->communicator_creator;
}