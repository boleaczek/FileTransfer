#ifndef DATA_PACEKER_H
#define DATA_PACEKER_H

#include<unordered_map>
#include<functional>
#include "IDataPacker.h"

class DataPacker : public IDataPacker
{
public:
//     DataPacker();
//     virtual PackData Unpack(const char *) override;
//     virtual char * Pack(const PackData) override;
// private:
//     template <class T>
//     InnerPacket * Unpack(const char *);
//     template <class T>
//     char * Pack(InnerPacket *);

//     std::unordered_map<MessageType, std::function<InnerPacket*(const char *)>> unpack_templates;
//     std::unordered_map<MessageType, std::function<char*(InnerPacket *)>> pack_templates;
};

#endif