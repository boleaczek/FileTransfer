#include "Client.h"
#include "CommunicatorCreator.h"
#include "Server.h"

std::shared_ptr<ICommunicator> CommunicatorCreator::BuildClient(const std::string destination_ip, const std::string port)
{
    return std::make_shared<Client>(destination_ip, port);
}

std::shared_ptr<IServer> CommunicatorCreator::BuildServer(const std::string addres, const std::string port)
{
    return std::make_shared<Server>(addres, port);
}