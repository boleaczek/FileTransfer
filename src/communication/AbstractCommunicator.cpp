#include "AbstractCommunicator.h"
#include <string.h>

void AbstractCommunicator::Start()
{
    addrinfo *servinfo, hints = GetHints();

    if(GetInfo(hints, servinfo) != 0)
    {
        //throw exception
    }

    this->socket_file_descriptor = GoOnline(servinfo);
    
    freeaddrinfo(servinfo);
}

addrinfo GetHints()
{
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    return hints;
}