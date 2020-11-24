#include <string.h>
#include <errno.h>
#include <iostream>

#include "Client.h"

int Client::GetSocketFileDescriptor(const addrinfo * info)
{
    auto socket_fd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    connect(socket_fd, info->ai_addr, info->ai_addrlen);
    
    return socket_fd;
}

void Client::Send(const char * bytes, int size)
{
    send(socket_file_descriptor, bytes, size, 0);
}

int Client::Recieve(char * & bytes, int expected_size)
{
    bytes = new char[expected_size];
    int size = recv(socket_file_descriptor, bytes, expected_size, 0);
    return size;
}

Client::Client(std::string destination_addres, std::string port) 
    : AbstractCommunicator(destination_addres, port) {}