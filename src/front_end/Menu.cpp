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
    while(input != "exit")
    {   
        //std::cin.ignore();
        std::getline(std::cin, input);
        PacketData pd = this->parser->Parse(input);
        this->client->SendPacket(pd);
        PacketData response = this->client->Recieve();
        if(response.type == MessageType::command)
        {
            PrintResponse(response);
        }
        else
        {
            std::cout << "Recieved new file." << std::endl;
        }
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