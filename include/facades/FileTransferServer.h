#ifndef FILE_TRANSFER_SERVER_H
#define FILE_TRANSFER_SERVER_H

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "FileTransferHelpers.h"
#include "IServer.h"

class FileTransferServer
{
public:
    FileTransferServer(std::string, std::string, int=64);
    void Start();
private:
    void HandleCommand(CommandType, std::vector<std::string>);

    FileTransferHelpers helpers;
    std::shared_ptr<IServer> server;
    int max_packet_size;
    std::unordered_map<CommandType, 
        std::function<void (std::vector<std::string>)>> command_handlers;
};

#endif