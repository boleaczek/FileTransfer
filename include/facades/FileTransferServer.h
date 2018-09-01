#ifndef FILE_TRANSFER_SERVER_H
#define FILE_TRANSFER_SERVER_H

#include "FileTransferHelpers.h"
#include "IServer.h"
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>

class FileTransferServer
{
public:
    FileTransferServer(std::string, std::string, int=64);
    ~FileTransferServer();
    void Start();
private:
    void HandleCommand(CommandType, std::vector<std::string>);

    FileTransferHelpers helpers;
    IServer * server;
    int max_packet_size;
    std::unordered_map<CommandType, 
        std::function<void (std::vector<std::string>)>> command_handlers;
};

#endif