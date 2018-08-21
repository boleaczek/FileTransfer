#ifndef SERVER_COMMUNICATOR_H
#define SERVER_COMMUNICATOR_H

#include "AbstractComunicator.h"
#include "IServer.h"

class ServerComunicator : public IServer, public AbstractComunicator
{
public:
    virtual void AcceptConnection() override;
    virtual void CloseConnection() override;
    virtual void Start() override;
    virtual int Recieve(char * &) override;
    virtual void Stop() override;
    virtual void Send(const char *, int) override;
private:
    virtual int GetInfo(const addrinfo &, addrinfo * &) override;
    virtual int GetSocketFileDescriptor(const addrinfo *) override;

    int connected_socket_file_descriptor;
};

#endif