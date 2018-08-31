#include "Menu.h"
#include "FileTransferClient.h"
#include "CommandParser.h"
#include "PacketData.h"
#include "StringToEnumNumber.h"
#include <iostream>
#include <string>
#include <string.h>
#include <errno.h>


void Menu::Start()
{
    StartClient();
    std::cout << "Connected to server" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    while(input != "exit")
    {   
        PacketData pd = this->parser->Parse(input);
        PacketData response = this->client->SendPacket(pd);
        PrintResponse(response);
        std::getline(std::cin, input);
    }
    client->Stop();
    delete client;
}

void Menu::PrintResponse(PacketData pd)
{
    std::cout << "Response type: " << StringToEnumNumber::CommandTypeToString(pd.command) << std::endl;
    std::cout << "Response args: " << std::endl;
    for(int i = 0 ; i < pd.args.size(); i++)
    {
        std::cout << pd.args[i] << std::endl;
    }
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