#ifndef ABSTRACT_COMMUNICATOR_H
#define ABSTRACT_COMMUNICATOR_H

#include "IComunicator.h"
#include <string>
#include <netdb.h>

class AbstractComunicator: public IComunicator
{
public:
    virtual void Start() override;
    virtual int Recieve(char * &) override;
    virtual void Stop() override;
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) = 0;
    virtual int GetSocketFileDescriptor(const addrinfo *) = 0;
    addrinfo GetHints();
protected:
    std::string port;
    int socket_file_descriptor;
};

#endif