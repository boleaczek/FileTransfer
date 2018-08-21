#include "ICommunicator.h"
#include <string>
#include <netdb.h>

class AbstractCommunicator: public ICommunicator
{
public:
    virtual void Start() override;
    virtual int Recieve(char * &) override;
    virtual void Stop() override;
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) = 0;
    virtual int GetSocketFileDescriptor(const addrinfo *) = 0;
    void CloseSocket(const int);
    addrinfo GetHints();
protected:
    std::string port;
    int socket_file_descriptor;
};