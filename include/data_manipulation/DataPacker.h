#include "IDataPacker.h"

class DataPacker : public IDataPacker
{
public: 
    MessagePacket Unpack(const char * bytes);
    char * Pack(const MessagePacket packet);
    DeletePacket UnpackDelete(const char * bytes);
    ListPacket UnpackList(const char * bytes);
    MovePacket UnpackMove(const char * bytes);
    FilePacket UnpackFile(const char * bytes);
};