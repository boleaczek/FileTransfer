#include "AbstractCommunicator.h"
#include <unistd.h>
#include <string.h>

AbstractCommunicator::AbstractCommunicator(const std::string addres, const std::string port)
{
    addres = addres;
    port = port;
}

void AbstractCommunicator::Start()
{
    addrinfo *servinfo, hints = GetHints();

    if(GetInfo(hints, servinfo) != 0)
    {
        //throw exception
    }

    for(addrinfo * p = servinfo; p != NULL; p = p->ai_next)
    {
        socket_file_descriptor = GetSocketFileDescriptor(p);
        if(socket_file_descriptor == -1)
        {
            continue;
        }
        break;
    }
    
    freeaddrinfo(servinfo);
}

int AbstractCommunicator::GetInfo(const addrinfo & hints, addrinfo * & servinfo) 
{
    return getaddrinfo(addres.c_str(), port.c_str(), &hints, &servinfo);
}

void AbstractCommunicator::Stop()
{
    close(socket_file_descriptor);
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