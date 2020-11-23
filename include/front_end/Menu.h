#pragma once

#include "IFileTransferClient.h"
#include "ICommandParser.h"

class Menu
{
public:
    void Start();
    Menu();
    ~Menu();
private:
    void StartClient();
    PacketData ParseInput(const std::string);
    void PrintResponse(PacketData);

    ICommandParser * parser;
    IFileTransferClient * client;
};