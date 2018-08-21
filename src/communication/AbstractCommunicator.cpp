#include "AbstractCommunicator.h"
#include <unistd.h>
#include <string.h>

void AbstractCommunicator::Start()
{
    addrinfo *servinfo, hints = GetHints();

    if(GetInfo(hints, servinfo) != 0)
    {
        //throw exception
    }

    for(addrinfo * p = servinfo; p != NULL; p = p->ai_next)
    {
        this->socket_file_descriptor = GetSocketFileDescriptor(p->ai_family, p->ai_socktype, p->ai_protocol);
    }
    
    freeaddrinfo(servinfo);
}

void AbstractCommunicator::Connect()
{
    this->connection_socket_file_descriptor = GetConnectionSocketFileDescriptor();
}

void AbstractCommunicator::Send(const char * bytes, int size)
{
    if(this->connection_socket_file_descriptor == -1)
    {
        //throw exception
    }

    send(this->connection_socket_file_descriptor, bytes, size, 0);
}

int AbstractCommunicator::Recieve(char * & bytes)
{
    bytes = new char[500];
    int size = recv(this->socket_file_descriptor, bytes, 499, 0);

    return size;
}

void AbstractCommunicator::CloseConnection()
{
    CloseSocket(this->connection_socket_file_descriptor);
}

void AbstractCommunicator::Stop()
{
    CloseSocket(this->socket_file_descriptor);
}

void AbstractCommunicator::CloseSocket(int fd)
{
    close(fd);
}

addrinfo AbstractCommunicator::GetHints()
{
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    return hints;
}