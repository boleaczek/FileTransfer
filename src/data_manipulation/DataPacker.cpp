// #include "DataPacker.h"
// #include <cstring>
// #include <functional>
// #include <errno.h>
// #include <string.h>
// #include <iostream>

// PackData DataPacker::Unpack(const char * bytes)
// {
//     PackData packet;
//     MessagePacket mp;
    
//     std::memcpy(&mp, bytes, sizeof(MessagePacket));
//     packet.type = mp.type;
//     packet.inner = this->unpack_templates[mp.type](mp.contents);
    
//     return packet;
// }

// char * DataPacker::Pack(const PackData packet)
// {
//     MessagePacket mp;
//     mp.type = packet.type;
//     mp.contents = this->pack_templates[packet.type](packet.inner);
//     char * bytes = new char[sizeof(MessagePacket)];
//     memcpy(bytes, &mp, sizeof(MessagePacket));
    
//     return bytes;
// }

// template<class T>
// InnerPacket * DataPacker::Unpack(const char * bytes)
// {
//     T * packet = new T;
//     memcpy(packet, bytes, sizeof(T));
//     InnerPacket * inner = packet;
//     return inner;
// }

// template<class T>
// char * DataPacker::Pack(InnerPacket * inner)
// {
//     T * packet = static_cast<T*>(inner);
//     char * bytes = new char[sizeof(T)];

//     memcpy(bytes, packet, sizeof(T));
//     return bytes;
// }

// DataPacker::DataPacker()
// {
//     this->unpack_templates = {
//         {MessageType::file, [=](const char * bytes){return this->Unpack<FilePacket>(bytes);}},
//         {MessageType::list, [=](const char * bytes){return this->Unpack<ListPacket>(bytes);}},
//         {MessageType::move, [=](const char * bytes){return this->Unpack<MovePacket>(bytes);}},
//         {MessageType::remove_file, [=](const char * bytes){return this->Unpack<RemovePacket>(bytes);}}
//     };
//     this->pack_templates = {
//         {MessageType::file, [=](InnerPacket * bytes){return this->Pack<FilePacket>(bytes);}},
//         {MessageType::list, [=](InnerPacket * bytes){return this->Pack<ListPacket>(bytes);}},
//         {MessageType::move, [=](InnerPacket * bytes){return this->Pack<MovePacket>(bytes);}},
//         {MessageType::remove_file, [=](InnerPacket * bytes){return this->Pack<RemovePacket>(bytes);}}
//     };
// }