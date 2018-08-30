#ifndef I_FILE_TRANSFER_CLIENT_H
#define I_FILE_TRANSFER_CLIENT_H

#include "PacketData.h"
#include <string>

class IFileTransferClient
{
public:
    virtual void Start(std::string, std::string) = 0;
    virtual void Stop() = 0;
    virtual std::string SendPacket(PacketData) = 0;
};

#endif