#ifndef FILE_PACKET_H
#define FILE_PACKET_H

#include "Packet.h"

struct FilePacket : public Packet
{
    int bytes_total;
    int bytes_sent;
    char * bytes;

    virtual std::stringstream Serialize() override;
    static Packet * Deserialize(std::stringstream&);
    ~FilePacket();
    FilePacket(char *, int, int);
    FilePacket(){}
};

#endif