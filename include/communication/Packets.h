#include <string>

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
    char * contents;
};

struct FilePacket
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
};

struct DeletePacket 
{
    std::string file_name;
};

struct MovePacket
{
    std::string source;
    std::string destination; 
};

struct ListPacket
{
    std::string directory;
};