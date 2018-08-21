#include "ServerCommunicator.h"

int ServerCommunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo)
{
    return getaddrinfo(NULL, this->port.c_str(), &hints, &servinfo);
}

int ServerCommunicator::GetSocketFileDescriptor(const addrinfo * servinfo)
{
    this->socket_file_descriptor = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if(this->socket_file_descriptor == -1)
    {
        return -1;
    }

    int * optval;
    *optval = 1;
    
    if(setsockopt(this->socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR, optval, sizeof(optval)) == -1
        || bind(this->socket_file_descriptor, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        return -1;
    }
}

void ServerCommunicator::Send(const char * bytes, int size)
{
    send(this->connected_socket_file_descriptor, bytes, size, 0);
}