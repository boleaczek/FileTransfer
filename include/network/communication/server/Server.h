#ifndef SERVER_H
#define SERVER_H

#include "AbstractCommunicator.h"
#include "IServer.h"
#include <string>

class Server : public IServer, public AbstractCommunicator
{
public:
    Server(const std::string, const std::string);
    virtual void AcceptConnection() override;
    virtual void CloseConnection() override;
    virtual void Send(const char *, int) override;
    virtual int Recieve(char * &, int) override;
    virtual void Start() override;
    virtual void Stop() override;
private:
    virtual int GetSocketFileDescriptor(const addrinfo *) override;

    int connected_socket_file_descriptor;
    ICommunicator * communicator;
};

#endif