#include <string>

class ISender
{
public:
    virtual void Send(char *, int, std::string) = 0;
};