#include "Packet.h"

template<class T>
std::stringstream Packet::LoadIntoStream(std::stringstream & stream, T contents, int size)
{
    stream.read(contents, size);
}