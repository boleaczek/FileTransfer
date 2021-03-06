#pragma once

#include <memory>

#include "ICommunicatorCreator.h"

class CommunicatorCreator: public ICommunicatorCreator
{
public:
    virtual std::shared_ptr<ICommunicator> BuildClient(const std::string, const std::string) override;
    virtual std::shared_ptr<IServer> BuildServer(const std::string, const std::string) override;
};