#include "Menu.h"
#include "FileTransferClient.h"
#include "CommandParser.h"
#include <iostream>
#include <string>
#include <string.h>
#include <errno.h>


void Menu::Start()
{
    StartClient();

    std::string input;
    std::getline(std::cin, input);
    while(input != "exit")
    {
        PacketData pd = this->parser->Parse(input);
        this->client->SendPacket(pd);
        std::getline(std::cin, input);
    }
    client->Stop();
    delete client;
}

void Menu::StartClient()
{
    std::string ip, port;
    std::cout << "Ip: ";
    std::getline(std::cin, ip);
    std::cout << "Port: ";
    std::getline(std::cin, port);
    this->client->Start(ip, port);
}

Menu::Menu()
{
    this->client = new FileTransferClient;
    this->parser = new CommandParser;
}

Menu::~Menu()
{
    delete this->client;
    delete this->parser;
}