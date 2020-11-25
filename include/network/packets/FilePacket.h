#pragma once

#include "Packet.h"

struct FilePacket : public Packet
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
    std::string file_name;

    virtual std::stringstream Serialize() override;
    static Packet * Deserialize(std::stringstream&);
    ~FilePacket();
    FilePacket(char *, int, int, std::string);
    FilePacket(){}
};