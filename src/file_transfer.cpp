#include <string>
#include <cstring>
#include <vector>
#include <strstream>
#include <algorithm>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <string>
#include <tuple>
#include "PacketCreator.h"
#include "Packet.h"
#include "CommandPacket.h"
#include "DataManager.h"
#include "PacketExtractor.h"
#include "Menu.h"
#include "Server.h"
#include "Client.h"
#include "CommandParser.h"
#include "FileTransferServer.h"
using namespace std;

int main()
{
    string s_or_c;
    getline(cin, s_or_c);
    if(s_or_c == "1")
    {
        FileTransferServer server("127.0.0.1", "3000");
        server.Start();
    }
    else
    {
        Menu m;
        m.Start();
    } 
}
