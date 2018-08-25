#ifndef PACKETS_H
#define PACKETS_H

#include <string>

struct InnerPacket 
{
    virtual ~InnerPacket(){};
};

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
    char * contents;
};

struct FilePacket : public InnerPacket
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
};

struct RemovePacket : public InnerPacket
{
    char * file_name;
};

struct MovePacket : public InnerPacket
{
    char * source;
    char * destination; 
};

struct ListPacket : public InnerPacket
{
    char * directory;
};

#endif