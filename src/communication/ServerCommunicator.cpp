#include "ServerCommunicator.h"
#include <unistd.h>

int ServerCommunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo)
{
    return getaddrinfo(NULL, this->port.c_str(), &hints, &servinfo);
}

int ServerCommunicator::GetSocketFileDescriptor(const addrinfo * servinfo)
{
    int socket_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if(socket_fd == -1)
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

    return socket_fd;
}

void ServerCommunicator::AcceptConnection()
{
    sockaddr * connection_addres;
    socklen_t size_of_connection_addres = sizeof(connection_addres);
    this->connected_socket_file_descriptor = accept(this->socket_file_descriptor, 
        connection_addres, 
        &size_of_connection_addres);
}

void ServerCommunicator::Send(const char * bytes, int size)
{
    send(this->connected_socket_file_descriptor, bytes, size, 0);
}

void ServerCommunicator::CloseConnection()
{
    close(this->connected_socket_file_descriptor);
}