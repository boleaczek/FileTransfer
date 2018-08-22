#include "DataPacker.h"
#include <cstring>

MessagePacket DataPacker::Unpack(const char * bytes)
{
    MessagePacket packet;
    std::memcpy(&packet, &bytes, sizeof(packet));
    return packet;
}

char * DataPacker::Pack(const MessagePacket packet)
{
    char * bytes;
    bytes = new char[sizeof(packet)];
    memcpy(bytes, &packet, sizeof(packet));
    return bytes;
}

template <class T>
T DataPacker::UnpackInner(const char * bytes)
{
    T packet;
    memcpy(&packet, bytes, sizeof(packet));
    return packet;
}