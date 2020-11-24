#pragma once

#include <string>

#include "PacketData.h"

class IFileTransferClient
{
public:
    virtual void Start(std::string, std::string) = 0;
    virtual void Stop() = 0;
    virtual void SendPacket(PacketData) = 0;
    virtual PacketData Recieve() = 0;
};