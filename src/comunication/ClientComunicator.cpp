#include "ClientComunicator.h"

int ClientComunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo) 
{
    return getaddrinfo(this->destination_addres.c_str(), "3490", &hints, &servinfo);
}

int ClientComunicator::GetSocketFileDescriptor(const addrinfo * info)
{
    this->recieving_socket_file_descriptor = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    connect(this->recieving_socket_file_descriptor, info->ai_addr, info->ai_addrlen);
    
    return this->recieving_socket_file_descriptor;
}

void ClientComunicator::Send(const char * bytes, int size)
{
    send(this->socket_file_descriptor, bytes, size, 0);
}

ClientComunicator::ClientComunicator(std::string destination_addres)
{
    this->destination_addres = destination_addres;
}