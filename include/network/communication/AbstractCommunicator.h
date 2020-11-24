#ifndef ABSTRACT_COMMUNICATOR_H
#define ABSTRACT_COMMUNICATOR_H

#include <string>
#include <netdb.h>

#include "ICommunicator.h"

class AbstractCommunicator: public ICommunicator
{
public:
    AbstractCommunicator(const std::string, const std::string);
    virtual void Start() override;
    virtual void Stop() override;
private:
    int GetInfo(const addrinfo &, addrinfo * &);
    virtual int GetSocketFileDescriptor(const addrinfo *) = 0;
    addrinfo GetHints();
protected:
    std::string port;
    std::string addres;
    int socket_file_descriptor;
};

#endif