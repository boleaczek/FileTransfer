#include "PacketExtractor.h"
#include <strstream>
#include <iostream>
#include <errno.h>
#include <string.h>

Packet * PacketExtractor::ExtractPacket(char * bytes)
{
    std::stringstream stream;
    stream.write(bytes, this->packet_size);
    Packet * p = Packet::Deserialize(stream);
    stream.str(std::string());
    stream.clear();
    return p;
}

PacketExtractor::PacketExtractor(int packet_size)
{
    this->packet_size = packet_size;
}