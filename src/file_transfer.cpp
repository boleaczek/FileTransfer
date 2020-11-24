#include <string>
#include "CommunicatorCreator.h"
#include "FileTransferServer.h"
#include "Menu.h"
#include <iostream>

int main(int argc, char * argv[])
{
    std::string mode = argv[1];

    auto creator = std::make_unique<CommunicatorCreator>();
    if(mode == "server")
    {
        std::string addres, port;
        addres.assign(argv[2]);
        port.assign(argv[3]);
        std::cout << "Running server on: " << addres << ":" << port << std::endl;
        FileTransferServer server(creator->BuildServer(addres, port));
        server.Start();
    }
    else if(mode == "client")
    {
        Menu m;
        m.Start();
    } 
}
