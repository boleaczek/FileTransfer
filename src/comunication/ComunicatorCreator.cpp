#include "ComunicatorCreator.h"
#include "ClientComunicator.h"
#include "ServerComunicator.h"

IComunicator * ComunicatorCreator::BuildClient(std::string destination_ip)
{
    ClientComunicator Comunicator(destination_ip);
    return static_cast<IComunicator *>(&Comunicator);
}

IServer * ComunicatorCreator::BuildServer()
{
    ServerComunicator Comunicator;
    return static_cast<IServer *>(&Comunicator);
}