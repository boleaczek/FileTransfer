#pragma once

#include <functional>
#include <memory>
#include <sstream>
#include <unordered_map>

enum class MessageType
{
    file,
    command
};

struct Packet
{
    Packet();
    Packet(MessageType type);
    virtual std::stringstream Serialize();
    static std::shared_ptr<Packet> Deserialize(std::stringstream &);
    static int CharPtrToInt(char *, bool);
    static int LoadIntFromStream(std::stringstream &);

    MessageType type;
private:
    static std::unordered_map<MessageType
        , std::function<std::shared_ptr<Packet> (std::stringstream &)>> deserialization_methods;
};