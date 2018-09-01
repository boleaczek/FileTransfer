#include "DataManager.h"
#include <cstring>

int DataManager::ReadData(const std::string fileName, char * & bytes)
{
    std::ifstream file (fileName, std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = file.tellg();

    file.seekg(0, file.beg);
    bytes = new char[size];

    file.read(bytes, size);

    file.close();

    return (int)size;
}

void DataManager::WriteData(const std::string fileName, const char * bytes, int size)
{
    std::ofstream file (fileName, std::ofstream::binary);
    
    file.write(bytes, size);
    file.close();
}