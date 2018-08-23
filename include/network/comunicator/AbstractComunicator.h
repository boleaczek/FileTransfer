#ifndef ABSTRACT_COMUNICATOR_H
#define ABSTRACT_COMUNICATOR_H

#include "IComunicator.h"
#include <string>
#include <netdb.h>

class AbstractComunicator: public IComunicator
{
public:
    AbstractComunicator(const std::string, const std::string);
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