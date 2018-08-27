#ifndef PACKET_H
#define PACKET_H

#include <sstream>

enum MessageType 
{
    file,
    remove_file,
    move,
    list
};

struct Packet
{
    virtual std::stringstream Serialize();
    static Packet Deserialize(std::stringstream stream);
};

#endif