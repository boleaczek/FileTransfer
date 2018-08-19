#include "DataPacker.h"
#include <cstring>

MessagePacket DataPacker::Unpack(const char * bytes)
{
    MessagePacket packet;
    std::memcpy(&packet, bytes, sizeof(packet));
    return packet;
}

char * DataPacker::Pack(const MessagePacket packet)
{
    char * bytes;
    bytes = new char[sizeof(packet)];
    memcpy(bytes, &packet, sizeof(packet));
    return bytes;
}

DeletePacket DataPacker::UnpackDelete(const char * bytes)
{

}

ListPacket DataPacker::UnpackList(const char * bytes)
{

}

MovePacket DataPacker::UnpackMove(const char * bytes)
{

}

FilePacket DataPacker::UnpackFile(const char * bytes)
{

}
