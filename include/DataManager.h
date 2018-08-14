#include "IDataManager.h"
#include <fstream>

class DataReader : public IDataReader
{
public:
    int ReadData(const std::string, char * &);
    void WriteData(const std::string, const char *, int size);
};