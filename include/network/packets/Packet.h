#ifndef PACKET_H
#define PACKET_H

#include <sstream>
#include <unordered_map>
#include <functional>

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
    static int CharPtrToInt(char *, bool);
    
    static int LoadIntFromStream(std::stringstream &);
};

#endif