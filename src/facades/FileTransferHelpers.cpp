#include "DataManager.h"
#include "FileTransferHelpers.h"
#include "PacketCreator.h"
#include "PacketExtractor.h"
#include "algorithm"

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
    char * bytes;
    handle->Recieve(bytes, max_packet_size);
    Packet * packet = packet_extractor->ExtractPacket(bytes);
    PacketData result;
    result.type = packet->type;

    if(packet->type == MessageType::command)
    {
        CommandPacket * command_packet = static_cast<CommandPacket *>(packet);
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

void FileTransferHelpers::RecieveFilePackets(std::shared_ptr<ICommunicator> handle, Packet * initial, int max_packet_size)
{
    
    FilePacket * initial_fp = static_cast<FilePacket *>(initial);
    int how_much = initial_fp->bytes_total;

    int cursor = 0;
    char * file = new char[how_much];
    
    std::copy(initial_fp->bytes, initial_fp->bytes + (initial_fp->bytes_sent), file);
    cursor += initial_fp->bytes_sent;
    while(cursor < how_much)
    {
        char * bytes;
        int len = handle->Recieve(bytes, max_packet_size);
        
        Packet * p = packet_extractor->ExtractPacket(bytes);
        FilePacket * fp = static_cast<FilePacket *>(p);
        
        std::copy(fp->bytes, fp->bytes + (fp->bytes_sent), file + cursor);
        cursor += fp->bytes_sent;

        delete[] bytes;
        delete p;
    }
    
    data_manager->WriteData(initial_fp->file_name, file, how_much);
    delete initial_fp;
}

FileTransferHelpers::FileTransferHelpers()
{
    data_manager = new DataManager();
    packet_creator = new PacketCreator();
    packet_extractor = new PacketExtractor();
}

FileTransferHelpers::~FileTransferHelpers()
{
    delete data_manager;
    delete packet_creator;
    delete packet_extractor;
}