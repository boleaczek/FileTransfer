#include <string>
#include "FileTransferServer.h"
#include "Menu.h"
#include <iostream>

int main(int argc, char * argv[])
{
    std::string mode = argv[1];
    if(mode == "server")
    {
        std::string addres, port;
        addres.assign(argv[2]);
        port.assign(argv[3]);
        std::cout << "Running server on: " << addres << ":" << port << std::endl;
        FileTransferServer server(addres, port);
        server.Start();
    }
    else if(mode == "client")
    {
        Menu m;
        m.Start();
    } 
}
