#include "AbstractCommunicator.h"
#include <string>

class ClientCommunicator : public AbstractCommunicator
{
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(int, int, int) override;
    virtual int GetConnectionSocketFileDescriptor() override;

    std::string destination_addres;
};