#include "FileTransferServer.h"
#include "Server.h"
#include "FileTransferHelpers.h"

void FileTransferServer::Start()
{
    this->server->Start();
    
    while(true)
    {
        this->server->AcceptConnection();
        CommandType stop;
        while(stop != CommandType::end_connection)
        {
            char * bytes;
            PacketData pd = this->helpers.Recieve(this->server, this->max_packet_size);
            
            if(pd.type == MessageType::command)
            {
                this->command_handlers[pd.command](pd.args);
                stop = pd.command;
            }
            else
            {
                std::vector<std::string> args;
                this->command_handlers[CommandType::ping](args);
            }
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
        },
        {CommandType::end_connection, [=](std::vector<std::string>)
            {
                std::vector<std::string> response_args;
                response_args.push_back("Goodbye");
                HandleCommand(CommandType::response, response_args);
                this->server->CloseConnection();
            }
        }
    };
}

FileTransferServer::~FileTransferServer()
{
    delete this->server;
}
