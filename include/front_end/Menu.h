#pragma once

#include <memory>

#include "IFileTransferClient.h"
#include "ICommandParser.h"

class Menu
{
public:
    void Start();
    Menu();
private:
    void StartClient();
    PacketData ParseInput(const std::string);
    void PrintResponse(PacketData);

    std::unique_ptr<ICommandParser> parser;
    std::unique_ptr<IFileTransferClient> client;
};