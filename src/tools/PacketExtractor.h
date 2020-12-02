#pragma once

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