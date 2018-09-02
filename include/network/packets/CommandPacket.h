#ifndef COMMAND_PACKET_H
#define COMMAND_PACKET_H

#include "Packet.h"
#include <string>
#include <vector>

enum CommandType
{
    remove_file,
    move,
    list,
    ping,
    response,
    end_connection,
    get
};

struct CommandPacket : public Packet
{
    std::vector<std::string> args;
    CommandType command;

    CommandPacket(){};
    CommandPacket(CommandType, std::vector<std::string>);
    virtual std::stringstream Serialize() override;
    static Packet * Deserialize(std::stringstream &);
};

#endif