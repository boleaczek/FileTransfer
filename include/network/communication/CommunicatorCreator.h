#ifndef COMMUNICATOR_CREATOR_H
#define COMMUNICATOR_CREATOR_H

#include "ICommunicatorCreator.h"

class CommunicatorCreator: public ICommunicatorCreator
{
public:
    virtual ICommunicator * BuildClient(const std::string, const std::string) override;
    virtual IServer * BuildServer(const std::string, const std::string) override;
};

#endif