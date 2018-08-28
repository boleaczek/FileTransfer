#include "FilePacket.h"
#include "Packet.h"
#include <sstream>

std::stringstream FilePacket::Serialize()
{
    std::stringstream stream = Packet::Serialize();
    stream.write(reinterpret_cast<const char*>(&type), sizeof(MessageType::file));
    stream.write(reinterpret_cast<const char*>(&this->bytes_sent), sizeof(this->bytes_sent));
    stream.write(reinterpret_cast<const char*>(&this->bytes_total), sizeof(this->bytes_total));
    stream.write(this->bytes, this->bytes_sent);
    
    return stream;
}

Packet * FilePacket::Deserialize(std::stringstream & stream)
{
    FilePacket * packet = new FilePacket;
    packet->type = MessageType(LoadIntFromStream(stream));
    packet->bytes_sent = LoadIntFromStream(stream);
    packet->bytes_total = LoadIntFromStream(stream);
    
    packet->bytes = new char[packet->bytes_sent];
    stream.read(packet->bytes, packet->bytes_sent);

    stream.clear();
    return packet;
}

FilePacket::~FilePacket()
{
    if(this->bytes != nullptr)
    {
        delete[] this->bytes;
    }
}

FilePacket::FilePacket()
{
    this->type = MessageType::file;
}