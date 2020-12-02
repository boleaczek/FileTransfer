#pragma once

#include <memory>

#include "Packet.h"

namespace communication { namespace packets {

struct FilePacket : public Packet
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
    std::string file_name;

    virtual std::stringstream Serialize() override;
    static std::shared_ptr<Packet> Deserialize(std::stringstream&);
    ~FilePacket();
    FilePacket(char *, int, int, std::string);
    FilePacket(){}
};

}}