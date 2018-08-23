#ifndef ISERVER_H
#define ISERVER_H

#include "IComunicator.h"

class IServer : public IComunicator
{
public:
    virtual void AcceptConnection() = 0;
    virtual void CloseConnection() = 0;
    IComunicator * communicator;
};

#endif