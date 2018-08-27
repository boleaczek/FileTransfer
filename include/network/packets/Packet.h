#ifndef PACKET_H
#define PACKET_H

#include <strstream>

enum MessageType 
{
    file,
    remove_file,
    move,
    list
};

struct Packet
{
    enum MessageType 
    {
        file,
        remove_file,
        move,
        list
    };

    virtual std::stringstream Serialize();
    static Packet Deserialize(std::string stream);
    template<class T>
    std::stringstream LoadIntoStream(std::stringstream&, T, int);
};

#endif;