#include "FilePacket.h"
#include "Packet.h"
#include <sstream>

std::stringstream FilePacket::Serialize()
{
    std::stringstream stream;
    stream.read(reinterpret_cast<char*>(MessageType::file), sizeof(MessageType::file));
    stream.read(reinterpret_cast<char*>(this->bytes_sent), sizeof(this->bytes_sent));
    stream.read(reinterpret_cast<char*>(this->bytes_total), sizeof(this->bytes_total));
    stream.read(reinterpret_cast<char*>(this->bytes), this->bytes_sent);
    
    return stream;
}