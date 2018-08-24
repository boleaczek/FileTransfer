#ifndef MENU_H
#define MENU_H

#include "ICommunicatorCreator.h"
#include "IDataPacker.h"
#include "IDataManager.h"

class Menu
{
public:
    void Start(const std::string, const std::string, ICommunicatorCreator *);
private:
    std::string ParseInput(const std::string);
    MessagePacket CreatePacket(const std::string);
    ListPacket CreateListPacket();
};

#endif
