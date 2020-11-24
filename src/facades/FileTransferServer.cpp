#include "FileTransferServer.h"
#include "Server.h"
#include "FileTransferHelpers.h"

void FileTransferServer::Start()
{
    server->Start();
    
    while(true)
    {
        server->AcceptConnection();
        CommandType stop;
        while(stop != CommandType::end_connection)
        {
            PacketData pd = helpers.Recieve(server, max_packet_size);
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
    int len = helpers.GetCommandPacket(type, args, bytes);
    server->Send(bytes, len);
    delete[] bytes;
}

FileTransferServer::FileTransferServer(std::string ip, std::string port, int max_packet_size)
{
    server = std::make_shared<Server>(ip, port);
    max_packet_size = max_packet_size;

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
                std::vector<std::tuple<char*, int>> file_packets = helpers.GetFilePackets(args[0]);
                helpers.SendFile(server, file_packets);
            }
        }
    };
}