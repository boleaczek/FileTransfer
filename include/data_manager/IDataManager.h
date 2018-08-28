#ifndef I_DATA_MANAGER_H
#define I_DATA_MANAGER_H

#include <string>

class IDataManager
{
public:
    virtual int ReadData(const std::string, char * &) = 0;
    virtual void WriteData(const std::string, const char *, int) = 0; 
};

#endif