#include <algorithm>
#include <cstring>
#include <strstream>
#include <string>

#include "DataManager.h"
#include "PacketCreator.h"

int PacketCreator::CreateCommandPacket(CommandType type, std::vector<std::string> args, char * & packet)
{
    Packet * p;
    p = command_creator_functions[type](args);
    std::stringstream stream = p->Serialize();
    
    delete p;
    int len = GetBytesFromStream(stream, packet);

    stream.str(std::string());
    stream.clear();
    return len;
}

std::vector<std::tuple<char*,int>> PacketCreator::CreateFilePackets(std::string filename)
{
    using FilePacket = communication::packets::FilePacket;

    std::vector<std::tuple<char*,int>> vec;
    char * bytes, * chunk;
    
    int length = data_manager->ReadData(filename, bytes);
    int bytes_left = length, cursor = 0;
    int to_write = GetChunkSize(max_chunk_size, bytes_left);

    while(bytes_left > 0)
    {
        
        char * chunk = GetChunk(bytes, cursor, to_write);
        Packet * packet = new FilePacket(chunk, to_write, length, filename);
        char * packet_bytes;
        std::stringstream stream = packet->Serialize();
        
        int bytes_length = GetBytesFromStream(stream, packet_bytes);
        vec.push_back(std::tuple<char*, int>(packet_bytes, bytes_length));

        stream.str(std::string());        
        stream.clear();
        delete packet;
        delete[] chunk;

        bytes_left -= to_write;
        cursor += to_write;
        to_write = GetChunkSize(max_chunk_size, bytes_left);
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

    int padding = (max_chunk_size + max_meta_size) - (temp.length() + 1);
    int total_size = temp.length() + padding + 1;
    bytes = new char[total_size];
    std::copy(temp.c_str(), temp.c_str() + temp.length() + 1, bytes);

    return total_size;
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

PacketCreator::PacketCreator(int max_chunk_size, int max_meta_size) :
    data_manager(std::make_unique<DataManager>()),
    max_chunk_size(max_chunk_size),
    max_meta_size(max_meta_size)
{
    using CommandPacket = communication::packets::CommandPacket;

    command_creator_functions = 
        {
            {CommandType::list , 
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::list, args);
                }
            },
            {CommandType::move, 
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 2);
                    return new CommandPacket(CommandType::move, args);
                }
            },
            {CommandType::remove_file,
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::remove_file, args);
                }
            },
            {CommandType::ping,
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 0);
                    return new CommandPacket(CommandType::ping, args);
                }
            },
            {CommandType::response,
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::response, args);
                }
            },
            {CommandType::end_connection,
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 0);
                    return new CommandPacket(CommandType::end_connection, args);
                }
            },
            {CommandType::get,
                [=](std::vector<std::string> args)
                {
                    ValidArgs(args.size(), 1);
                    return new CommandPacket(CommandType::get, args);
                }
            }
        };

}