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

    // FilePacket fp;
    // DataManager dm;
    // fp.bytes_total = dm.ReadData("test.png", fp.bytes);
    // fp.bytes_sent = fp.bytes_total;
    // Packet * p = &fp;
    // p->type = MessageType::file;
    // stringstream ss = p->Serialize();
    // Packet * p1 = Packet::Deserialize(ss);
    // FilePacket * fp2 = static_cast<FilePacket *>(p1);
    // dm.WriteData("test1.png", fp2->bytes, fp2->bytes_total);
}
