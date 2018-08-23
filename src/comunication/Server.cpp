#include "Server.h"
#include <unistd.h>
#include <errno.h>
#include <iostream>

int Server::GetSocketFileDescriptor(const addrinfo * servinfo)
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

void Server::AcceptConnection()
{
    sockaddr_storage * connection_addres;
    socklen_t size_of_connection_addres = sizeof(connection_addres);
    listen(this->socket_file_descriptor, 1);
    this->connected_socket_file_descriptor = accept(this->socket_file_descriptor, 
        (sockaddr *) connection_addres, 
        &size_of_connection_addres);
}

void Server::Send(const char * bytes, int size)
{
    send(this->connected_socket_file_descriptor, bytes, size, 0);
}

void Server::CloseConnection()
{
    close(this->connected_socket_file_descriptor);
}

int Server::Recieve(char * & bytes, int expected_size)
{
    int size = recv(this->connected_socket_file_descriptor, bytes, expected_size, 0);
    return size;
}

void Server::Start()
{
    AbstractCommunicator::Start();
}

void Server::Stop()
{
    AbstractCommunicator::Stop();
}

Server::Server(const std::string addres, const std::string port)
    : AbstractCommunicator(addres, port) {}