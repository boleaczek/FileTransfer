#ifndef DATA_PACEKER_H
#define DATA_PACEKER_H

#include "IDataPacker.h"

class DataPacker : public IDataPacker
{
public: 
    virtual MessagePacket Unpack(const char *) override;
    virtual char * Pack(const MessagePacket) override;
private:
    template <class T>
    T UnpackInner(const char *);
};

#endif