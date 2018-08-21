#include "AbstractCommunicator.h"
#include "IServer.h"

class ServerCommunicator : public AbstractCommunicator, public IServer
{
public:
    virtual void AcceptConnection() override;
    virtual void CloseConnection() override;
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;
    virtual void Send(const char *, int) override;

    int connected_socket_file_descriptor;
};