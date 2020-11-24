#include "FileTransferClient.h"
#include "CommunicatorCreator.h"
#include "DataManager.h"
#include "PacketCreator.h"
#include "PacketExtractor.h"
#include "ICommunicator.h"

void FileTransferClient::Start(std::string ip, std::string port)
{
    communicator = communicator_creator->BuildClient(ip, port);
    communicator->Start();
}

void FileTransferClient::Stop()
{
    if(communicator != nullptr)
    {
        communicator->Stop();
    }
}

void FileTransferClient::SendPacket(PacketData data)
{
    if(data.type == MessageType::command)
    {   
        char * packet;
        auto len = helpers.GetCommandPacket(data.command, data.args, packet);
        helpers.SendCommand(communicator, packet, len);
        delete[] packet;
    }
    else if(data.type == MessageType::file)
    {
        auto packets = helpers.GetFilePackets(data.args[0]);
        helpers.SendFile(communicator, packets);
    }
}

PacketData FileTransferClient::Recieve()
{
    return helpers.Recieve(communicator);
}

FileTransferClient::FileTransferClient()
{
    communicator_creator = std::make_unique<CommunicatorCreator>();
}

FileTransferClient::~FileTransferClient()
{
    Stop();
}