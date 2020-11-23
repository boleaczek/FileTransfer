#pragma once

#include "AbstractCommunicator.h"
#include "IServer.h"
#include <string>
#include <memory>

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
    std::unique_ptr<ICommunicator> communicator;
};