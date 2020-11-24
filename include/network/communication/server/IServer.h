#pragma once

#include "ICommunicator.h"

class IServer : public ICommunicator
{
public:
    virtual void AcceptConnection() = 0;
    virtual void CloseConnection() = 0;
};