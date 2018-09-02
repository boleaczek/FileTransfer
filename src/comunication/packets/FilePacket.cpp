#include "FilePacket.h"
#include "Packet.h"
#include <sstream>
#include <iostream>

std::stringstream FilePacket::Serialize()
{
    std::stringstream stream = Packet::Serialize();
    
    int file_name_length = this->file_name.length() + 1;
    
    stream.write(reinterpret_cast<const char*>(&file_name_length), sizeof(file_name_length));
    stream.write(this->file_name.c_str(), file_name_length);
    stream.write(reinterpret_cast<const char*>(&this->bytes_sent), sizeof(this->bytes_sent));
    stream.write(reinterpret_cast<const char*>(&this->bytes_total), sizeof(this->bytes_total));
    stream.write(this->bytes, this->bytes_sent);
    
    return stream;
}

Packet * FilePacket::Deserialize(std::stringstream & stream)
{
    FilePacket * packet = new FilePacket;
    
    int file_name_length = LoadIntFromStream(stream);
    
    char * file_name_bytes = new char[file_name_length];
   
    stream.read(file_name_bytes, file_name_length);
    packet->file_name.assign(file_name_bytes);
    
    std::cout << packet->file_name << std::endl;

    packet->bytes_sent = LoadIntFromStream(stream);
    packet->bytes_total = LoadIntFromStream(stream);
    packet->bytes = new char[packet->bytes_sent];
    stream.read(packet->bytes, packet->bytes_sent);
    
    delete[] file_name_bytes;

    return packet;
}

FilePacket::~FilePacket()
{
    if(this->bytes != nullptr)
    {
        delete[] this->bytes;
    }
}

FilePacket::FilePacket(char * bytes, int bytes_sent, int bytes_total, std::string file_name)
{
    this->file_name = file_name;
    this->type = MessageType::file;
    this->bytes = bytes;
    this->bytes_total = bytes_total;
    this->bytes_sent = bytes_sent;
}