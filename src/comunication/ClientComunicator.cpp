#include "ClientComunicator.h"

int ClientComunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo) 
{
    return getaddrinfo(this->destination_addres.c_str(), this->port.c_str(), &hints, &servinfo);
}

int ClientComunicator::GetSocketFileDescriptor(const addrinfo * info)
{
    int socket_fd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    if(socket_fd == -1)
    {
        return -1;
    }
    
    return connect(socket_fd, info->ai_addr, info->ai_addrlen);
}

void ClientComunicator::Send(const char * bytes, int size)
{
    send(this->socket_file_descriptor, bytes, size, 0);
}

ClientComunicator::ClientComunicator(std::string destination_addres)
{
    this->destination_addres = destination_addres;
}