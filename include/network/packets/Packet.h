#pragma once

#include <functional>
#include <sstream>
#include <unordered_map>

enum MessageType 
{
    file,
    command
};

struct Packet
{
    Packet();
    Packet(MessageType type);
    virtual std::stringstream Serialize();
    static Packet * Deserialize(std::stringstream &);
    static int CharPtrToInt(char *, bool);
    static int LoadIntFromStream(std::stringstream &);

    MessageType type;
private:
    static std::unordered_map<MessageType
        , std::function<Packet *(std::stringstream &)>> deserialization_methods;
};