#include "ICommunicator.h"
#include <string>

class ICommunicatorFactory
{
public:
    virtual ICommunicator * BuildClient(std::string) = 0;
    virtual ICommunicator * BuildServer() = 0;
};