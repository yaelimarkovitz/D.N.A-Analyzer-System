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
    CommandCollection();
    ~CommandCollection();
    ICommand* getCmd(const std::string& name);

private:
    std::map<std::string,ICommand*> m_commandList;
};

inline CommandCollection::CommandCollection()
{
    m_commandList["new"] = new New;
    m_commandList["load"] = new Load;
    m_commandList["save"] = new Save;
}

inline CommandCollection::~CommandCollection()
{
    for (std::map<std::string,ICommand*>::iterator it = m_commandList.begin(); it != m_commandList.end();it ++)
    {
        delete it->second;
    }
}

inline ICommand* CommandCollection::getCmd(const std::string &name)
{
    if(m_commandList.find(name)==m_commandList.end())
    {
        return NULL;
    }

    return m_commandList[name];
}


#endif //UNTITLED_COMMAND_COLLECTION_H
