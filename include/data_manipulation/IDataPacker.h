#ifndef I_DATA_PACKER_H
#define I_DATA_PACKER_H

#include "Packets.h"

class IDataPacker
{
public:
    virtual MessagePacket Unpack(const char * bytes) = 0;
    virtual char * Pack(const MessagePacket packet) = 0;
};

#endif