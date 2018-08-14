#include "ISender.h"

struct FilePacket
{
    int bytes_total;
    int bytes_sent;
    char * bytes;
};

class Sender : public ISender
{
public:
    void Send(char *, int, std::string);
};