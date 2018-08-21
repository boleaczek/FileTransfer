#include "AbstractCommunicator.h"
#include <unistd.h>
#include <string.h>

void AbstractCommunicator::Start()
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

int AbstractCommunicator::Recieve(char * & bytes)
{
    bytes = new char[500];
    int size = recv(this->socket_file_descriptor, bytes, 499, 0);

    return size;
}

void AbstractCommunicator::Stop()
{
    close(this->socket_file_descriptor);
}

addrinfo AbstractCommunicator::GetHints()
{
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    return hints;
}