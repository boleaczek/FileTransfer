#ifndef Comunicator_CREATOR_H
#define Comunicator_CREATOR_H

#include "IComunicatorCreator.h"

class ComunicatorCreator: public IComunicatorCreator
{
public:
    virtual IComunicator * BuildClient(std::string) override;
    virtual IServer * BuildServer() override;
};

#endif