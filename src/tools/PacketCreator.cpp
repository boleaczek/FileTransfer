#include "PacketCreator.h"
#include "IDataPacker.h"
#include "DataPacker.h"
#include <cstring>
#include <iostream>

char * PacketCreator::CreateCommandPacket(MessageType type, std::vector<std::string> args)
{
    PackData pd;
    pd.type = type;
    pd.inner = this->command_creator_function[type](args);
    std::cout << pd.inner << std::endl;
    DataPacker dp;
    char * packed = this->data_packer->Pack(pd);


    //delete pd.inner;    
    return packed;
}

std::vector<char *> PacketCreator::GetFilePackets(std::string file_name)
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

PacketCreator::PacketCreator(IDataPacker * data_packer)
{
    this->data_packer = data_packer;
    this->command_creator_function = 
        {
            {MessageType::list , 
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 1);
                    ListPacket * lp = new ListPacket;
                    lp->directory = this->CopyStrToCharPtr(args[0]);
                    return lp;
                }
            },
            {MessageType::move, 
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 2);
                    MovePacket * mp = new MovePacket;
                    mp->source = this->CopyStrToCharPtr(args[0]);
                    mp->destination = this->CopyStrToCharPtr(args[1]);
                    return mp;
                }
            },
            {MessageType::remove_file,
                [=](std::vector<std::string> args)
                {
                    this->ValidArgs(args.size(), 1);
                    RemovePacket * rp = new RemovePacket;
                    rp->file_name = this->CopyStrToCharPtr(args[0]);
                    return rp;
                }}
        };
}