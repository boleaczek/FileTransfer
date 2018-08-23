#ifndef I_Comunicator_CREATOR_H
#define I_Comunicator_CREATOR_H

#include "IComunicator.h"
#include "IServer.h" 
#include <string>

class IComunicatorCreator
{
public:
    virtual IComunicator * BuildClient(const std::string, const std::string) = 0;
    virtual IServer * BuildServer(const std::string, const std::string) = 0;
};

#endif