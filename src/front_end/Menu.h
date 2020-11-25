#pragma once

#include <memory>

#include "ICommandParser.h"
#include "IFileTransferClient.h"

class Menu
{
public:
    Menu();

    void Start();
private:
    void StartClient();
    void PrintResponse(const PacketData&);

    std::unique_ptr<ICommandParser> parser;
    std::unique_ptr<IFileTransferClient> client;
};