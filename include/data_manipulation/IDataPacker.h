#include "Packets.h"

class IDataPacker
{
public:
    virtual MessagePacket Unpack(const char * bytes) = 0;
    virtual char * Pack(const MessagePacket packet) = 0;
    virtual DeletePacket UnpackDelete(const char * bytes) = 0;
    virtual ListPacket UnpackList(const char * bytes) = 0;
    virtual MovePacket UnpackMove(const char * bytes) = 0;
    virtual FilePacket UnpackFile(const char * bytes) = 0;
};