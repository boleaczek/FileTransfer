#include "Packet.h"
#include "FilePacket.h"
#include <sstream>

using namespace std;

int main()
{
    FilePacket fp;
    fp.bytes = "Hello";
    fp.bytes_sent = 5;
    fp.bytes_total = 5;
    
    fp.Serialize();

    return 0;
}
