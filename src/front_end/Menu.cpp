#include "Menu.h"
#include "ICommunicator.h"
#include <iostream>
#include <string>



void Menu::Start(const std::string addres, const std::string port, ICommunicatorCreator * factory)
{
    ICommunicator * client = factory->BuildClient(addres, port);
    client->Start();
    std::string input;
    while(input != "exit")
    {
        std::cin >> input;
    }
}