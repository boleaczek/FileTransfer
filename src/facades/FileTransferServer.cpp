#include "FileTransferHelpers.h"
#include "FileTransferServer.h"
#include "Server.h"

using MessageType = communication::packets::MessageType;

void FileTransferServer::Start()
{
    server->Start();
    
    while(true)
    {
        server->AcceptConnection();
        CommandType stop;
        while(stop != CommandType::end_connection)
        {
            auto pd = helpers.Recieve(server, max_packet_size);
            if(pd.type == MessageType::command)
            {
                command_handlers[pd.command](pd.args);
                stop = pd.command;
            }
            else
            {
                std::vector<std::string> args;
                command_handlers[CommandType::ping](args);
            }
        }
        
        server->CloseConnection();
    }
    server->Stop();
}

void FileTransferServer::HandleCommand(CommandType type, std::vector<std::string> args)
{
    char * bytes;
    auto len = helpers.GetCommandPacket(type, args, bytes);
    server->Send(bytes, len);
    delete[] bytes;
}

FileTransferServer::FileTransferServer(std::shared_ptr<IServer> server, int max_packet_size):
    server(server),
    max_packet_size(max_packet_size)
{
    command_handlers = 
    {
        {CommandType::ping, [=](std::vector<std::string> args)
            {
                HandleCommand(CommandType::ping, args);
            }
        },
        {CommandType::end_connection, [=](std::vector<std::string> args)
            {
                std::vector<std::string> response_args;
                response_args.push_back("Goodbye");
                HandleCommand(CommandType::response, response_args);
                server->CloseConnection();
            }
        },
        {CommandType::get, [=](std::vector<std::string> args)
            {
                auto file_packets = helpers.GetFilePackets(args[0]);
                helpers.SendFile(server, file_packets);
            }
        }
    };
}