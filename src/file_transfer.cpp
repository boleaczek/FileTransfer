#include "DataManager.h"
#include "DataPacker.h"
#include <iostream>

int main()
{
    MessagePacket packet;
    ListPacket lp;
    lp.directory = "ABCD";
    packet.contents = &lp;
    packet.type = MessageType::list_command;
    
    DataPacker packer;
    char * packetBytes = packer.Pack(packet);
    MessagePacket unpackedPacket = packer.Unpack(packetBytes);

    std::cout << "Type after packing: " << unpackedPacket.type << std::endl;

    ListPacket * lp2;
    InnerPacket * ip = unpackedPacket.contents;
    lp2 = static_cast<ListPacket*>(ip);

    std::cout << "Message after packing: " << lp2 -> directory << std::endl;

    return 0;
}


