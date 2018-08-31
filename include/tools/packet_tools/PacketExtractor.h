#ifndef PACKET_EXTRACTOR_H
#define PACKET_EXTRACTOR_H

#include "IPacketExtractor.h"

class PacketExtractor : public IPackeExtractor
{
public:
    PacketExtractor(int=32);
    virtual Packet * ExtractPacket(char *) override;
private:
    int packet_size;
};

#endif