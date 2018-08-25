#ifndef I_DATA_PACKER_H
#define I_DATA_PACKER_H

#include "Packets.h"

struct PackData
{
    MessageType type;
    InnerPacket * inner;
};

class IDataPacker
{
public:
    virtual PackData Unpack(const char * bytes) = 0;
    virtual char * Pack(const PackData packet) = 0;
};

#endif