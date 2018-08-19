#include "DataManager.h"
#include "DataPacker.h"
#include <iostream>

int main()
{
    MessagePacket packet;
    char * contents;
    contents = new char[5]{'h','e','l','l','o'};
    packet.contents = contents;
    packet.type = MessageType::file;

    std::cout << "Type before packing: " << packet.type << std::endl;
    std::cout << "Message after packing: " << packet.contents << std::endl;

    DataPacker packer;

    char * packetBytes = packer.Pack(packet);

    MessagePacket unpackedPacket = packer.Unpack(packetBytes);

    std::cout << "Type after packing: " << unpackedPacket.type << std::endl;
    std::cout << "Message after packing: " << unpackedPacket.contents << std::endl;
 
    return 0;
}


