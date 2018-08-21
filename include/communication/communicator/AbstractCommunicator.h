#include "ICommunicator.h"
#include <string>
#include <netdb.h>

class AbstractCommunicator: public ICommunicator
{
public:
    virtual void Start() override;
    virtual void Connect() override;
    virtual void Send(const char *, int) override;
    virtual int Recieve(char * &) override;
    virtual void CloseConnection() override;
    virtual void Stop() override;
private:
    addrinfo GetHints();
    virtual int GetInfo(const addrinfo &, addrinfo * &) = 0;
    virtual int GetSocketFileDescriptor(const addrinfo *) = 0;
    virtual int GetConnectionSocketFileDescriptor() = 0;
    void CloseSocket(const int);

    std::string port;
    int socket_file_descriptor;
    int connection_socket_file_descriptor = -1;
};