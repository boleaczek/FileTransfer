#include "PacketsCreator.h"
#include "DataManager.h"
#include "DataPacker.h"

MessagePacket PacketsCreator::BuildPacket(const MessageType type, const std::string args)
{
    MessagePacket packet;
    packet.type = type;
    packet.contents = GetContents(type, args);
}

InnerPacket * PacketsCreator::GetContents(const MessageType type, const std::string args)
{
    switch(type)
    {
        case MessageType::file:
        break;
        case MessageType::list:
        break;
        case MessageType::move:
        break;
        case MessageType::remove_file:
        break;
        default:
        break;
    }
}

PacketsCreator::PacketsCreator()
{
    DataManager dm;
    DataPacker dp;
    this->data_manager = &dm;
    this->data_packer = &dp;
}