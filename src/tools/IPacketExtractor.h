#ifndef I_PACKET_EXTRACTOR_H
#define I_PACKET_EXTRACTOR_H

#include "Packet.h"
#include "CommandPacket.h"
#include "FilePacket.h"

class IPackeExtractor
{
public:
    virtual std::shared_ptr<Packet> ExtractPacket(char *) = 0;
};

#endif