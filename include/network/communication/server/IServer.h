#ifndef ISERVER_H
#define ISERVER_H

#include "ICommunicator.h"

class IServer : public ICommunicator
{
public:
    virtual void AcceptConnection() = 0;
    virtual void CloseConnection() = 0;
};

#endif