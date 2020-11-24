#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "FileTransferHelpers.h"
#include "IServer.h"

class FileTransferServer
{
public:
    FileTransferServer(std::shared_ptr<IServer>, int=64);
    void Start();
private:
    void HandleCommand(CommandType, std::vector<std::string>);

    std::shared_ptr<IServer> server;
    FileTransferHelpers helpers;
    int max_packet_size;
    std::unordered_map<CommandType, 
        std::function<void (std::vector<std::string>)>> command_handlers;
};