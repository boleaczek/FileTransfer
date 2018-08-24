#include "Menu.h"
#include "ICommunicator.h"
#include <iostream>
#include <string>
#include "CommunicatorCreator.h"
#include "CommandParser.h"


void Menu::Start()
{
    ICommunicator * client = GetCommunicator();
    client->Start();
    std::string input;
    while(input != "exit")
    {
        std::cin >> input;
    }

    delete client;
}

ICommunicator * Menu::GetCommunicator()
{
    std::string addres;
    std::string port;
    std::cout << "Host IP: ";
    std::cin >> addres;
    std::cout << "Port: ";
    std::cin >> port;
    return this->factory->BuildClient(addres, port);
}

ParsingResult Menu::ParseInput(const std::string input)
{
    return this->parser->Parse(input);
}

Menu::Menu()
{
    CommandParser p;
    CommunicatorCreator cc;
    this->factory = &cc;
    this->parser = &p;
}
