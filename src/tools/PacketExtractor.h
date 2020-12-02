#ifndef PACKET_EXTRACTOR_H
#define PACKET_EXTRACTOR_H

#include <memory>

#include "IPacketExtractor.h"

class PacketExtractor : public IPackeExtractor
{
public:
    PacketExtractor(int=64);
    virtual std::shared_ptr<communication::packets::Packet> ExtractPacket(char *) override;
private:
    int packet_size;
};

#endif