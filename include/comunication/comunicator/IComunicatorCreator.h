#ifndef I_Comunicator_CREATOR_H
#define I_Comunicator_CREATOR_H

#include "IComunicator.h"
#include "IServer.h" 
#include <string>

class IComunicatorCreator
{
public:
    virtual IComunicator * BuildClient(std::string) = 0;
    virtual IServer * BuildServer() = 0;
};

#endif