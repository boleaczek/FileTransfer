#ifndef CLIENT_H
#define CLIENT_H

#include "AbstractComunicator.h"
#include <string>

class Client : public AbstractComunicator
{
public:
    Client(const std::string, const std::string);
    virtual void Send(const char *, int) override;
    virtual int Recieve(char * &, int) override;
private:
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    std::string destination_addres;
};

#endif