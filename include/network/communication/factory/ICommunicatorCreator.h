#ifndef I_Communicator_CREATOR_H
#define I_Communicator_CREATOR_H

#include "ICommunicator.h"
#include "IServer.h" 
#include <string>
#include <memory>

class ICommunicatorCreator
{
public:
    virtual std::shared_ptr<ICommunicator> BuildClient(const std::string, const std::string) = 0;
    virtual std::shared_ptr<IServer> BuildServer(const std::string, const std::string) = 0;
};

#endif