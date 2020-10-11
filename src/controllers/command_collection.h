//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_COMMAND_COLLECTION_H
#define UNTITLED_COMMAND_COLLECTION_H

#include <map>
#include "ICommand.h"
#include "../model/commands_module/commands.h"
#include "../myTools/not_found_command.h"

class CommandCollection {

public:

    static ICommand* getCmd(const std::string& name);
    static std::map<std::string,ICommand*> m_commandList;
    static std::map<std::string,ICommand*> initMap();
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
    return m_commandList[name];

}

inline std::map<std::string,ICommand*>  CommandCollection::initMap()
{
    std::map<std::string,ICommand*> i;
    i["new"] = new New;
    i["load"] = new Load;
    i["save"] = new Save;
    i["slice"] = new Slice;
    i["len"] = new Len;
    i["find"] = new Find;
    i["findall"] = new FindAll;
    i["count"] = new Count;
    i["rename"] = new Rename;
    i["pair"] = new Pair;
    i["show"] = new Show;
    i["list"] = new List;
    i["concat"] = new Concat;
    return i;
}
#endif //UNTITLED_COMMAND_COLLECTION_H
