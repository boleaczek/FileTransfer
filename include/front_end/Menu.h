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
    void PrintResponse(const PacketData&);

    std::unique_ptr<ICommandParser> parser;
    std::unique_ptr<IFileTransferClient> client;
};