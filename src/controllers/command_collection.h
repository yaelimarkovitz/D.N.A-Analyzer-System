//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_COMMAND_COLLECTION_H
#define UNTITLED_COMMAND_COLLECTION_H

#include <map>
#include "ICommand.h"
#include "../model/commands_module/commands.h"
#include "../myTools/not_found_command.h"
#include "../myTools/SharedPointer.h"

class CommandCollection {

public:
    typedef std::map<std::string ,SharedPointer<ICommand>>  CommandsMap;

    static ICommand*        getCmd(const std::string& name);
    static  CommandsMap     m_commandList;
    static  CommandsMap     initMap();
};

//inline CommandCollection::~CommandCollection()
//{
//    for (std::map<std::string,ICommand*>::iterator it = m_commandList.begin(); it != m_commandList.end();it ++)
//    {
//        delete it->second;
//    }
//}

inline ICommand* CommandCollection::getCmd(const std::string &name)
{
    if(m_commandList.find(name)==m_commandList.end())
    {
        throw NotFoundCommand();
    }
    return (m_commandList[name]).getPtr();

}

inline CommandCollection::CommandsMap  CommandCollection::initMap()
{
    CommandsMap i;
    i["new"]=  SharedPointer<New>(new New);
    i["load"] = SharedPointer<Load>(new Load);
    i["save"] = SharedPointer<Save>(new Save);
    i["slice"] = SharedPointer<Slice>(new Slice);
    i["len"] = SharedPointer<Len>(new Len);
    i["find"] = SharedPointer<Find>( new Find);
    i["findall"] = SharedPointer<FindAll>(new FindAll);
    i["count"] = SharedPointer<Count>(new Count);
    i["rename"] = SharedPointer<Rename>(new Rename);
    i["pair"] = SharedPointer<Pair>(new Pair);
    i["show"] = SharedPointer<Show>(new Show);
    i["list"] = SharedPointer<List>(new List);
    i["concat"] = SharedPointer<Concat>(new Concat);
    i["replace"] = SharedPointer<Replace>(new Replace);
    return i;
}
#endif //UNTITLED_COMMAND_COLLECTION_H
