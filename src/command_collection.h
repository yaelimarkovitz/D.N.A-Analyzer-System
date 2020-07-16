//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_COMMAND_COLLECTION_H
#define UNTITLED_COMMAND_COLLECTION_H

#include <map>
#include "Icommand.h"
#include "commands.h"
#include "cmd_factory.h"
class CommandCollection {
public:
    CommandCollection();
    ~CommandCollection();
    Icommand* getCmd(const std::string& name);

private:
    std::map<std::string,Icommand*> m_commandList;
};
inline CommandCollection::CommandCollection() {
    m_commandList["new"] = new New;
}
inline CommandCollection::~CommandCollection() {
    for (std::map<std::string,Icommand*>::iterator it = m_commandList.begin(); it != m_commandList.end();it ++) {
        delete it->second;
    }
}
inline Icommand* CommandCollection::getCmd(const std::string &name){
    if(m_commandList.find(name)==m_commandList.end()){
        return NULL;
    }
    return m_commandList[name];
}


#endif //UNTITLED_COMMAND_COLLECTION_H
