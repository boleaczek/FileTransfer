#include "ComunicatorCreator.h"
#include "Client.h"
#include "Server.h"

IComunicator * ComunicatorCreator::BuildClient(const std::string destination_ip, const std::string port)
{
    return new Client(destination_ip, port);
}

IServer * ComunicatorCreator::BuildServer(const std::string addres, const std::string port)
{
    return new Server(addres, port);
}