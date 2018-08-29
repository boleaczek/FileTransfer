#include "PacketCreator.h"
#include "DataManager.h"
#include <cstring>
#include <iostream>
#include <strstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <errno.h>

int PacketCreator::CreateCommandPacket(CommandType type, std::vector<std::string> args, char * & packet)
{
    Packet * p;
    p = this->command_creator_functions[type](args);

    std::stringstream stream = p->Serialize();

    delete p;

    return GetBytesFromStream(stream, packet);
}

std::vector<std::tuple<char*,int>> PacketCreator::CreateFilePackets(std::string filename)
{
    std::vector<std::tuple<char*,int>> vec;
    char * bytes, * chunk;
    int length = this->data_manager->ReadData(filename, bytes);
    int bytes_left = length, cursor = 0;

    int to_write = GetChunkSize(this->max_chunk_size, bytes_left);

    while(bytes_left > 0)
    {
        char * chunk = GetChunk(bytes, cursor, to_write);

        Packet * packet = new FilePacket(chunk, to_write, length);
        char * packet_bytes;
        std::stringstream stream = packet->Serialize();
        int bytes_length = GetBytesFromStream(stream, bytes);

        vec.push_back(std::tuple<char*, int>(packet_bytes, bytes_length));

        delete packet;
        delete[] chunk;

        bytes_left -= to_write;
        cursor += to_write;
        to_write = GetChunkSize(this->max_chunk_size, bytes_left);
    }

    delete[] bytes;

    return vec;
}

int PacketCreator::GetChunkSize(int max_size, int left)
{
    return max_size > left ? left : max_size;
}

int PacketCreator::GetBytesFromStream(std::stringstream & stream, char * & bytes)
{
    std::string temp = stream.str();

    int padding = (this->max_chunk_size + this->max_meta_size) - (temp.length() + 1);
    bytes = new char[(temp.length() + 1) + padding];
    std::copy(temp.c_str(), temp.c_str() + temp.length() + 1, bytes);

    return temp.length();
}

char * PacketCreator::GetChunk(char * data, int start, int how_much)
{
    char * chunk = new char[how_much];
    std::copy(data + start, data + start + how_much, chunk);
    return chunk;
}

void PacketCreator::ValidArgs(int recieved, int expected)
{
    if(recieved != expected)
    {
        //throw exception
    }
}

PacketCreator::PacketCreator(IDataManager * dm, int max_chunk_size, int max_meta_size)
{
    this->data_manager = dm;
    this->max_chunk_size = max_chunk_size;
    this->max_meta_size = max_meta_size;
    this->command_creator_functions = 
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