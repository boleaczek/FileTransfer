#include "PacketCreator.h"
#include <cstring>
#include <iostream>
#include <strstream>
#include <string>
#include <algorithm>

int PacketCreator::CreateCommandPacket(CommandType type, std::vector<std::string> args, char * & packet)
{
    Packet * p;
    p = this->command_creator_fucntions[type](args);

    std::stringstream stream = p->Serialize();
    std::string temp = stream.str();

    packet = new char[temp.length() + 1];
    std::copy(temp.c_str(), temp.c_str() + temp.length() + 1, packet);

    delete p;

    return temp.length();
}

std::vector<std::tuple<char*,int>> PacketCreator::CreateFilePackets(std::string)
{

}

void PacketCreator::ValidArgs(int recieved, int expected)
{
    if(recieved != expected)
    {
        //throw exception
    }
}

char * PacketCreator::CopyStrToCharPtr(std::string str)
{
    char * res = new char[str.length() + 1];
    std::strcpy(res, str.c_str());
    return res;
}

PacketCreator::PacketCreator()
{
    this->command_creator_fucntions = 
        {
            {CommandType::list , 
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::list, args);
                }
            },
            {CommandType::move, 
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 2);
                    return new CommandPacket(CommandType::move, args);
                }
            },
            {CommandType::remove_file,
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::remove_file, args);
                }}
        };
}