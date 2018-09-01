#include "Packet.h"
#include "FilePacket.h"
#include "CommandPacket.h"

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
    MessageType type = MessageType(LoadIntFromStream(stream));
    packet = deserialization_methods[type](stream);
    packet->type = type;
    return packet;
}

int Packet::CharPtrToInt(char * bytes, bool little_endian)
{
    
    int result = 0;
    int start = sizeof(result);
    int end = 0;
    int step = -1;

    if(!little_endian)
    {
        start = 0;
        end = sizeof(result);
        step = 1;
    }

    for (int n = start; n >= end; n += step)
    {
        result = (result << 8) + (unsigned char)bytes[n];
    }

    return result;
}

int Packet::LoadIntFromStream(std::stringstream & stream)
{
    char * bytes = new char[sizeof(int)];
    stream.read(bytes, sizeof(int));
    int result = CharPtrToInt(bytes, true);
    delete[] bytes;
    return result;
}

std::unordered_map<MessageType
        , std::function<Packet *(std::stringstream &)>> Packet::deserialization_methods =
        {
            {MessageType::file, FilePacket::Deserialize},
            {MessageType::command, CommandPacket::Deserialize}
        };