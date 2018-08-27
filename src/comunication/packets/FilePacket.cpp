#include "FilePacket.h"
#include "Packet.h"
#include <sstream>

std::stringstream FilePacket::Serialize()
{
    std::stringstream stream;
    int type = MessageType::file;
    stream.write(reinterpret_cast<const char*>(&type), sizeof(MessageType::file));
    stream.write(reinterpret_cast<const char*>(&this->bytes_sent), sizeof(this->bytes_sent));
    stream.write(reinterpret_cast<const char*>(&this->bytes_total), sizeof(this->bytes_total));
    stream.write(this->bytes, this->bytes_sent);
    
    return stream;
}

FilePacket FilePacket::Deserialize(std::stringstream & stream)
{
    FilePacket packet;

    char * bytes = new char[sizeof(packet.bytes_sent)];
    stream.read(bytes, sizeof(packet.bytes_sent));
    packet.bytes_sent = CharPtrToInt(bytes, true); 
    delete[] bytes;

    bytes = new char[sizeof(packet.bytes_total)];
    stream.read(bytes, sizeof(packet.bytes_total));
    packet.bytes_total = CharPtrToInt(bytes, true);
    delete[] bytes;
    
    packet.bytes = new char[packet.bytes_sent];
    stream.read(packet.bytes, packet.bytes_sent);

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