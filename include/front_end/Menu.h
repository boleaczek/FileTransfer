#ifndef MENU_H
#define MENU_H

#include "ICommunicatorCreator.h"
#include "ICommandParser.h"
#include "IDataPacker.h"
#include "IDataManager.h"

class Menu
{
public:
    void Start();
    Menu();
private:
    ParsingResult ParseInput(const std::string);
    ICommunicator * GetCommunicator();

    ICommunicatorCreator * factory;
    ICommandParser * parser;
};

#endif
