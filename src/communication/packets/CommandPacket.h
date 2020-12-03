#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Packet.h"

namespace communication { namespace packets {

enum class CommandType : std::uint32_t
{
    remove_file = 0,
    move = 1,
    list = 2,
    ping = 3,
    response = 4,
    end_connection = 5,
    get = 6
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

}}