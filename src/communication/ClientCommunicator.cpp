#include "ClientCommunicator.h"

int ClientCommunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo) 
{
    return getaddrinfo(this->destination_addres.c_str(), this->port.c_str(), &hints, &servinfo);
}

int ClientCommunicator::GetSocketFileDescriptor(const addrinfo * info)
{
    int socket_fd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    if(socket_fd == -1)
    {
        return -1;
    }
    
    return connect(socket_fd, info->ai_addr, info->ai_addrlen);
}

void ClientCommunicator::Send(const char * bytes, int size)
{
    send(this->socket_file_descriptor, bytes, size, 0);
}