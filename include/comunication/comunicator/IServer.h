#ifndef ISERVER_H
#define ISERVER_H

#include "IComunicator.h"
#include "AbstractComunicator.h"

class IServer : public AbstractComunicator
{
public:
    virtual void AcceptConnection() = 0;
    virtual void CloseConnection() = 0;
};

#endif