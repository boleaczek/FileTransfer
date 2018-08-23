#ifndef COMMUNICATOR_CREATOR_H
#define COMMUNICATOR_CREATOR_H

#include "IComunicatorCreator.h"

class ComunicatorCreator: public IComunicatorCreator
{
public:
    virtual IComunicator * BuildClient(const std::string, const std::string) override;
    virtual IServer * BuildServer(const std::string, const std::string) override;
};

#endif