#pragma once

#include <string>

#include "AbstractCommunicator.h"

class Client : public AbstractCommunicator
{
public:
    Client(const std::string, const std::string);
    virtual void Send(const char *, int) override;
    virtual int Recieve(char * &, int) override;
private:
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    std::string destination_addres;
};