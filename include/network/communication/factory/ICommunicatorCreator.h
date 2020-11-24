#pragma once

#include "ICommunicator.h"
#include "IServer.h"

#include <memory>
#include <string>

class ICommunicatorCreator
{
public:
    virtual std::shared_ptr<ICommunicator> BuildClient(const std::string, const std::string) = 0;
    virtual std::shared_ptr<IServer> BuildServer(const std::string, const std::string) = 0;
};