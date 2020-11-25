#pragma once

#include <fstream>

#include "IDataManager.h"

class DataManager : public IDataManager
{
public:
    virtual int ReadData(const std::string, char * &) override;
    virtual void WriteData(const std::string, const char *, int size) override;
};