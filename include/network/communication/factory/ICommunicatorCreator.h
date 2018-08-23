#ifndef I_Communicator_CREATOR_H
#define I_Communicator_CREATOR_H

#include "ICommunicator.h"
#include "IServer.h" 
#include <string>

class ICommunicatorCreator
{
public:
    virtual ICommunicator * BuildClient(const std::string, const std::string) = 0;
    virtual IServer * BuildServer(const std::string, const std::string) = 0;
};

#endif