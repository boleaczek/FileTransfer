#ifndef COMMAND_PACKET_H
#define COMMAND_PACKET_H

#include "Packet.h"
#include <string>
#include <vector>

struct CommandPacket : public Packet
{
    MessageType type;
    std::vector<std::string> args;
    
    virtual std::stringstream Serialize() override;
    static CommandPacket Deserialize(std::stringstream &);
};

#endif