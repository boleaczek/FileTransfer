#include "MessageTypeToString.h"
#include "CommandParser.h"
#include "Packets.h"
#include "DataPacker.h"
#include "IDataPacker.h"
#include <iostream>
#include <functional>

using namespace std;

void test1();
void test2();

int main()
{
    test1();
    test2();
    return 0;
}

void test1()
{
    cout << "LIST" << endl;
    DataPacker dp;
    PackData dtp;
    InnerPacket * ip;
    ListPacket lp;
    lp.directory = "ABCD";
    ip = &lp;
    dtp.type = MessageType::list;
    dtp.inner = ip;

    char * bytes = dp.Pack(dtp);
    
    PackData dtp2;
    dtp2 = dp.Unpack(bytes);
    cout << dtp2.type << endl;
    cout << dynamic_cast<ListPacket*>(dtp2.inner)->directory << endl;
}

void test2()
{
    std::cout << "MOVE" << endl;
    DataPacker dp;
    PackData dtp;
    InnerPacket * ip;
    MovePacket lp;
    lp.destination = "ABCD";
    lp.source = "DCBA";
    ip = &lp;
    dtp.type = MessageType::move;
    dtp.inner = ip;

    char * bytes = dp.Pack(dtp);
    
    PackData dtp2;
    dtp2 = dp.Unpack(bytes);
    cout << dtp2.type << endl;
    cout << dynamic_cast<MovePacket*>(dtp2.inner)->destination << endl;
    cout << dynamic_cast<MovePacket*>(dtp2.inner)->source << endl;
}