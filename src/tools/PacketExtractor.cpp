#include "PacketExtractor.h"
#include <strstream>

Packet * PacketExtractor::ExtractPacket(char * bytes)
{
    std::stringstream stream;
    stream.write(bytes, this->packet_size);
    Packet * p = Packet::Deserialize(stream);
    return p;
}

PacketExtractor::PacketExtractor(int packet_size)
{
    this->packet_size = packet_size;
}