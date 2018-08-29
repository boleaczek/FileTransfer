#include <string>
#include <cstring>
#include <vector>
#include <strstream>
#include <algorithm>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <tuple>
#include "PacketCreator.h"
#include "Packet.h"
#include "CommandPacket.h"
#include "DataManager.h"
#include "PacketExtractor.h"

using namespace std;

int main()
{
    // char * file;
    // dm.ReadData("test.txt", file);
    // cout << file << endl;
    PacketCreator pc(new DataManager);
    vector<string> args;
    args.push_back("hello");
    char * bytes;
    int len = pc.CreateCommandPacket(CommandType::list, args, bytes);
    // Packet * p1 = new CommandPacket(CommandType::list, args);
    // stringstream ss = p1->Serialize();
    // string temp = ss.str();
    // bytes = new char[temp.length() + 1];
    // std::copy(temp.c_str(), temp.c_str() + temp.length() + 1, bytes);

    PacketExtractor pe(550);
    Packet * p = pe.ExtractPacket(bytes);
    cout << p->type << endl;
    cout << static_cast<CommandPacket*>(p)->args[0] << endl;    
}
