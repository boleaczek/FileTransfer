#ifndef PACKETS_H
#define PACKETS_H

#include <string>

struct InnerPacket {};

enum MessageType 
{
    file,
    remove_file,
    move,
    list
};

struct MessagePacket
{
    MessageType type;
    InnerPacket * contents;
};

struct FilePacket : public InnerPacket
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
};

struct RemovePacket : public InnerPacket
{
    std::string file_name;
};

struct MovePacket : public InnerPacket
{
    std::string source;
    std::string destination; 
};

struct ListPacket : public InnerPacket
{
    std::string directory;
};

#endif