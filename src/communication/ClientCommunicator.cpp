#include "ClientCommunicator.h"

int ClientCommunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo) 
{
    return getaddrinfo(this->destination_addres.c_str(), this->port.c_str(), &hints, &servinfo);
}

int ClientCommunicator::GetSocketFileDescriptor(const int addres_family, const int socket_type, const int protocol)
{
    return socket(addres_family, socket_type, protocol);
}