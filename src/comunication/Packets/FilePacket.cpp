#include "FilePacket.h"

std::stringstream FilePacket::Serialize()
{
    std::stringstream sstream;
    
    sstream = LoadIntoStream(sstream, MessageType::file, sizeof(MessageType::file));

    sstream = LoadIntoStream(sstream, this->bytes_sent, sizeof(this->bytes_sent));
    sstream = LoadIntoStream(sstream, this->bytes_total, sizeof(this->bytes_total));
    sstream = LoadIntoStream(sstream, this->bytes, this->bytes_sent);
    
    return sstream;
}