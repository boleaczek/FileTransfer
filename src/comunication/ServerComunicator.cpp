#include "ServerComunicator.h"
#include <unistd.h>
#include <errno.h>
#include <iostream>

int ServerComunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo)
{
    return getaddrinfo("127.0.0.1", "3490", &hints, &servinfo);
}

int ServerComunicator::GetSocketFileDescriptor(const addrinfo * servinfo)
{
    int socket_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if(socket_fd == -1)
    {
        return -1;
    }

    int optval;
    optval = 1;

    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1
        || bind(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        return -1;
    }

    return socket_fd;
}

void ServerComunicator::AcceptConnection()
{
    sockaddr_storage * connection_addres;
    socklen_t size_of_connection_addres = sizeof(connection_addres);
    listen(this->socket_file_descriptor, 1);
    this->recieving_socket_file_descriptor = accept(this->socket_file_descriptor, 
        (sockaddr *) connection_addres, 
        &size_of_connection_addres);
}

void ServerComunicator::Send(const char * bytes, int size)
{
    send(this->recieving_socket_file_descriptor, bytes, size, 0);
}

void ServerComunicator::CloseConnection()
{
    close(this->recieving_socket_file_descriptor);
}