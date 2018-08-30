#include "FileTransferServer.h"
#include "Server.h"
#include "FileTransferHelpers.h"

void FileTransferServer::Start()
{
    this->server->Start();
    while(true)
    {
        this->server->AcceptConnection();

        char * bytes;
        PacketData pd = this->helpers.Recieve(this->server, max_packet_size);
        
        if(pd.type == MessageType::command)
        {
            this->command_handlers[pd.command](pd.args);
        }
        
        this->server->CloseConnection();
    }
    this->server->Stop();
}

void FileTransferServer::HandleCommand(CommandType type, std::vector<std::string> args)
{
    char * bytes;
    int len = this->helpers.GetCommandPacket(type, args, bytes);
    this->server->Send(bytes, len);
    delete[] bytes;
}

FileTransferServer::FileTransferServer(std::string ip, std::string port, int max_packet_size)
{
    this->server = new Server(ip, port);
    this->max_packet_size = max_packet_size;

    this->command_handlers = 
    {
        {CommandType::ping, [=](std::vector<std::string> args)
            {
                HandleCommand(CommandType::ping, args);
            }
        }
    };
}

FileTransferServer::~FileTransferServer()
{
    delete this->server;
}
