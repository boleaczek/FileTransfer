#include "CommunicatorCreator.h"
#include "Client.h"
#include "Server.h"

ICommunicator * CommunicatorCreator::BuildClient(const std::string destination_ip, const std::string port)
{
    return new Client(destination_ip, port);
}

IServer * CommunicatorCreator::BuildServer(const std::string addres, const std::string port)
{
    return new Server(addres, port);
}