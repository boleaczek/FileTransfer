#include "AbstractCommunicator.h"

class ServerCommunicator : public AbstractCommunicator
{
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    virtual void Send(const char *, int) override;

    int connected_socket_file_descriptor;
};