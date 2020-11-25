#include <iostream>

#include "CommandPacket.h"
#include "FilePacket.h"
#include "Packet.h"

Packet::Packet(MessageType type) :
    type(type)
{}

Packet::Packet()
{}

std::stringstream Packet::Serialize()
{
    std::stringstream stream;
    stream.write(reinterpret_cast<const char*>(&this->type)
    , sizeof(int));
    return stream;
}

Packet * Packet::Deserialize(std::stringstream & stream)
{
    Packet * packet;
    auto type = MessageType(LoadIntFromStream(stream));
    packet = deserialization_methods[type](stream);
    stream.clear();
    stream.str(std::string());
    packet->type = type;
    return packet;
}

int Packet::CharPtrToInt(char * bytes, bool little_endian)
{
    
    auto result = 0;
    auto start = sizeof(result);
    auto end = 0;
    auto step = -1;

    if(!little_endian)
    {
        start = 0;
        end = sizeof(result);
        step = 1;
    }

    for (auto n = start; n >= end; n += step)
    {
        result = (result << 8) + (unsigned char)bytes[n];
    }

    return result;
}

int Packet::LoadIntFromStream(std::stringstream & stream)
{
    auto bytes = new char[sizeof(int)];
    stream.read(bytes, sizeof(int));
    auto result = CharPtrToInt(bytes, true);
    delete[] bytes;
    return result;
}

std::unordered_map<MessageType
        , std::function<Packet *(std::stringstream &)>> Packet::deserialization_methods =
        {
            {MessageType::file, FilePacket::Deserialize},
            {MessageType::command, CommandPacket::Deserialize}
        };