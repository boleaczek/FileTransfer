#include "Client.h"

int Client::GetSocketFileDescriptor(const addrinfo * info)
{
    int socket_fd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    connect(socket_fd, info->ai_addr, info->ai_addrlen);
    
    return socket_fd;
}

void Client::Send(const char * bytes, int size)
{
    send(this->socket_file_descriptor, bytes, size, 0);
}

int Client::Recieve(char * & bytes, int expected_size)
{
    int size = recv(this->socket_file_descriptor, bytes, expected_size, 0);
    return size;
}

Client::Client(std::string destination_addres, std::string port) 
    : AbstractComunicator(destination_addres, port) {}