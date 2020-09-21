//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_COMMAND_COLLECTION_H
#define UNTITLED_COMMAND_COLLECTION_H

#include <map>
#include "ICommand.h"
#include "../commands_module/commands.h"

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
        return NULL;
    }
    return m_commandList[name];

}

inline std::map<std::string,ICommand*>  CommandCollection::initMap()
{
    std::map<std::string,ICommand*> i;
    i["new"] = new New;
    i["new"] = new New;
    i["load"] = new Load;
    i["save"] = new Save;
    i["slice"] = new Slice;
    i["len"] = new Len;
    i["find"] = new FindAll;
    return i;
}
#endif //UNTITLED_COMMAND_COLLECTION_H
