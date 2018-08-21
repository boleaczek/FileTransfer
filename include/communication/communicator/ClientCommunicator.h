#include "AbstractCommunicator.h"
#include <string>

class ClientCommunicator : public AbstractCommunicator
{
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    virtual void Send(const char *, int) override;
    std::string destination_addres;
};