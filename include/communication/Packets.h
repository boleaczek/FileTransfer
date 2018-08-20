#include <string>

struct InnerPacket {};

enum MessageType 
{
    file,
    delete_command,
    move_command,
    list_command
};

struct MessagePacket
{
    MessageType type;
    InnerPacket * contents;
};

struct FilePacket : public InnerPacket
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
};

struct DeletePacket : public InnerPacket
{
    std::string file_name;
};

struct MovePacket : public InnerPacket
{
    std::string source;
    std::string destination; 
};

struct ListPacket : public InnerPacket
{
    std::string directory;
};