#ifndef CLIENT_COMMUNICATOR_H
#define CLIENT_COMMUNICATOR_H

#include "AbstractComunicator.h"
#include <string>

class ClientComunicator : public AbstractComunicator
{
public:
    ClientComunicator(std::string);
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    virtual void Send(const char *, int) override;
    std::string destination_addres;
};

#endif