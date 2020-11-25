#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Packet.h"

enum class CommandType
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
    static std::shared_ptr<Packet> Deserialize(std::stringstream &);
};