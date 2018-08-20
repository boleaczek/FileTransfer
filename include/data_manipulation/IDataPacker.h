#include "Packets.h"

class IDataPacker
{
public:
    virtual MessagePacket Unpack(const char * bytes) = 0;
    virtual char * Pack(const MessagePacket packet) = 0;
};