#include "Menu.h"
#include "FileTransferClient.h"
#include "CommandParser.h"
#include "PacketData.h"
#include "StringToEnumNumber.h"
#include <algorithm>
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
        auto pd = parser->Parse(input);
        client->SendPacket(pd);
        auto response = client->Recieve();
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
}

void Menu::PrintResponse(PacketData pd)
{
    std::cout << "Response type: " << StringToEnumNumber::CommandTypeToString(pd.command) << std::endl;
    std::cout << "Response args: " << std::endl;

    std::for_each(pd.args.cbegin(), pd.args.cend(), 
        [](const auto arg) {
            std::cout << arg << std::endl;
        });
    for(auto arg = 0; arg < pd.args.size(); arg++)
    {
        std::cout << pd.args[arg] << std::endl;
    }
}

void Menu::StartClient()
{
    std::string ip, port;
    std::cout << "Ip: ";
    std::getline(std::cin, ip);
    std::cout << "Port: ";
    std::getline(std::cin, port);
    client->Start(ip, port);
}

Menu::Menu()
{
    client = std::make_unique<FileTransferClient>();
    parser = std::make_unique<CommandParser>();
}