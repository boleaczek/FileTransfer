#pragma once

#include "CommandPacket.h"
#include "FilePacket.h"
#include "Packet.h"

class IPackeExtractor
{
public:
    virtual std::shared_ptr<communication::packets::Packet> ExtractPacket(char *) = 0;
};