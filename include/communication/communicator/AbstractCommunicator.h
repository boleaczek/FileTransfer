#include "ICommunicator.h"
#include <string>
#include <netdb.h>

class AbstractCommunicator: public ICommunicator
{
public:
    virtual void Start() override;
private:
    addrinfo GetHints();
    virtual int GetInfo(const addrinfo &, addrinfo * &) = 0;
    virtual int GoOnline(const addrinfo *) = 0;

    std::string port;
    int socket_file_descriptor;
};