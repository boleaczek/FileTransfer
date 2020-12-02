#include <memory>

#include "DataManager.h"
#include "FileTransferHelpers.h"
#include "PacketCreator.h"
#include "PacketExtractor.h"
#include "algorithm"

using CommandType = communication::packets::CommandType;
using Packet = communication::packets::Packet;

int FileTransferHelpers::GetCommandPacket(CommandType type, std::vector<std::string> args, char * & packet)
{
    return packet_creator->CreateCommandPacket(type, args, packet);
}

std::vector<std::tuple<char*,int>> FileTransferHelpers::GetFilePackets(std::string file_name)
{
    return packet_creator->CreateFilePackets(file_name);
}

void FileTransferHelpers::SendFile(std::shared_ptr<ICommunicator> handle, std::vector<std::tuple<char*, int>> packets)
{
    for(int i = 0; i < packets.size(); i++)
    {
        handle->Send(std::get<0>(packets[i]), std::get<1>(packets[i]));
        delete std::get<0>(packets[i]);
    }
}

void FileTransferHelpers::SendCommand(std::shared_ptr<ICommunicator> handle, char * bytes, int length)
{
    handle->Send(bytes, length);
}

PacketData FileTransferHelpers::Recieve(std::shared_ptr<ICommunicator> handle, int max_packet_size)
{
    using MessageType = communication::packets::MessageType;
    using CommandPacket = communication::packets::CommandPacket;

    char * bytes;
    handle->Recieve(bytes, max_packet_size);
    auto packet = packet_extractor->ExtractPacket(bytes);
    PacketData result;
    result.type = packet->type;

    if(packet->type == MessageType::command)
    {
        auto command_packet = std::dynamic_pointer_cast<CommandPacket>(packet);
        result.args = command_packet->args;
        result.command = command_packet->command;
        return result;
    }
    else if(packet->type == MessageType::file)
    {
        result.type = MessageType::file;
        RecieveFilePackets(handle, packet, max_packet_size);
        return result;
    }
}

void FileTransferHelpers::RecieveFilePackets(std::shared_ptr<ICommunicator> handle, std::shared_ptr<Packet> initial, int max_packet_size)
{
    using FilePacket = communication::packets::FilePacket;

    auto initial_fp = std::dynamic_pointer_cast<FilePacket>(initial);
    int how_much = initial_fp->bytes_total;

    int cursor = 0;
    char * file = new char[how_much];
    
    std::copy(initial_fp->bytes, initial_fp->bytes + (initial_fp->bytes_sent), file);
    cursor += initial_fp->bytes_sent;
    while(cursor < how_much)
    {
        char * bytes;
        int len = handle->Recieve(bytes, max_packet_size);
        
        auto p = packet_extractor->ExtractPacket(bytes);
        auto fp = std::dynamic_pointer_cast<FilePacket>(p);
        
        std::copy(fp->bytes, fp->bytes + (fp->bytes_sent), file + cursor);
        cursor += fp->bytes_sent;

        delete[] bytes;
    }
    
    data_manager->WriteData(initial_fp->file_name, file, how_much);
}

FileTransferHelpers::FileTransferHelpers() :
    data_manager(std::make_unique<DataManager>()),
    packet_creator(std::make_unique<PacketCreator>()),
    packet_extractor(std::make_unique<PacketExtractor>())
{}