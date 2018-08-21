#include "AbstractCommunicator.h"

class ServerCommunicator : public AbstractCommunicator
{
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    virtual int GetConnectionSocketFileDescriptor() override;
};