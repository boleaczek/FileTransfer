#include "AbstractComunicator.h"
#include <unistd.h>
#include <string.h>

void AbstractComunicator::Start()
{
    addrinfo *servinfo, hints = GetHints();

    if(GetInfo(hints, servinfo) != 0)
    {
        //throw exception
    }

    for(addrinfo * p = servinfo; p != NULL; p = p->ai_next)
    {
        this->socket_file_descriptor = GetSocketFileDescriptor(p);
        if(this->socket_file_descriptor == -1)
        {
            continue;
        }
        break;
    }
    
    freeaddrinfo(servinfo);
}

int AbstractComunicator::Recieve(char * & bytes)
{
    bytes = new char[16];
    int size = recv(this->recieving_socket_file_descriptor, &bytes, 15, 0);
    return size;
}

void AbstractComunicator::Stop()
{
    close(this->socket_file_descriptor);
}

addrinfo AbstractComunicator::GetHints()
{
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    return hints;
}