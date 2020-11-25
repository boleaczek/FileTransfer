#include <sstream>

#include "CommandPacket.h"

std::stringstream CommandPacket::Serialize()
{
    auto ss = Packet::Serialize();
    
    ss.write(reinterpret_cast<const char*>(&this->command),
        sizeof(int));
    
    auto vector_size = args.size();
    ss.write(reinterpret_cast<const char*>(&vector_size),
        sizeof(int));
    
    for(int i = 0; i < this->args.size(); i++)
    {
        int length = args[i].length() + 1;
        ss.write(reinterpret_cast<const char*>(&length)
            , sizeof(length));
        ss.write(args[i].c_str(), length);
    }

    return ss;
}

Packet * CommandPacket::Deserialize(std::stringstream & stream)
{
    auto packet = new CommandPacket;
    
    packet->command = CommandType(Packet::LoadIntFromStream(stream));
    
    auto size = Packet::LoadIntFromStream(stream);
    
    char * char_arg;
    for(int i = 0; i < size; i++)
    {
        auto arg_length = Packet::LoadIntFromStream(stream);
        
        std::string arg;
        char_arg = new char[arg_length];
        stream.read(char_arg, arg_length);
        arg.assign(char_arg);
        packet->args.push_back(arg);

        delete[] char_arg;
    }

    return packet;
}

CommandPacket::CommandPacket(CommandType command, std::vector<std::string> args) :
    Packet(MessageType::command),
    args(args),
    command(command)
{}