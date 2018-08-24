#ifndef PACKETS_CREATOR_H
#define PACKETS_CREATOR_H

#include "Packets.h"
#include "IDataManager.h"
#include "IDataPacker.h"

class PacketsCreator
{
public:
    MessagePacket BuildPacket(const MessageType, const std::string);
    PacketsCreator();
private: 
    InnerPacket * GetContents(const MessageType, const std::string);

    IDataPacker * data_packer;
    IDataManager * data_manager;
    char * buffer;
};

#endif