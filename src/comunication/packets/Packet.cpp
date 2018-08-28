#include "Packet.h"

Packet Packet::Deserialize(std::stringstream stream)
{

}

std::stringstream Packet::Serialize()
{

}

int Packet::CharPtrToInt(char * bytes, bool little_endian)
{
    
    int result = 0;
    int start = sizeof(result);
    int end = 0;
    int step = -1;

    if(!little_endian)
    {
        start = 0;
        end = sizeof(result);
        step = 1;
    }

    for (int n = start; n >= end; n += step)
    {
        result = (result << 8) + bytes[n];
    }

    return result;
}

int Packet::LoadIntFromStream(std::stringstream & stream)
{
    char * bytes = new char[sizeof(int)];
    stream.read(bytes, sizeof(int));
    int result = CharPtrToInt(bytes, true);
    delete[] bytes;
    return result;
}