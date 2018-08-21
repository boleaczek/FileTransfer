#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "IDataManager.h"
#include <fstream>

class DataReader : public IDataReader
{
public:
    virtual int ReadData(const std::string, char * &) override;
    virtual void WriteData(const std::string, const char *, int size) override;
};

#endif