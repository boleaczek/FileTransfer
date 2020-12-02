#include <errno.h>
#include <iostream>
#include <string.h>
#include <strstream>

#include "PacketExtractor.h"

using Packet = communication::packets::Packet;

std::shared_ptr<Packet> PacketExtractor::ExtractPacket(char * bytes)
{
    std::stringstream stream;
    stream.write(bytes, this->packet_size);
    std::shared_ptr<Packet> p = Packet::Deserialize(stream);
    stream.str(std::string());
    stream.clear();
    return p;
}

PacketExtractor::PacketExtractor(int packet_size)
{
    this->packet_size = packet_size;
}