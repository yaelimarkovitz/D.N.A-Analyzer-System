//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_CMDFACTORY_H
#define UNTITLED_CMDFACTORY_H

#include <string>
#include <vector>
#include <map>
#include "new_cmd.h"
class CmdFactory {

public:
    static Icommand* createCommand(const std::string& str);

private:
    static const size_t NUM_OF_COMMANDS = 3 ;
    static std::vector<Icommand*> s_commandList;
    static std::map<std::string, size_t> s_mapNameToNum;
};

inline Icommand* CmdFactory::createCommand(const std::string &str) {
    size_t index = str.find(" ");
    std::string cmdStr = str.substr(0,index);
    size_t indexInList = s_mapNameToNum.find(cmdStr)->second;

    /*check if this is the first use of this command*/
    if (s_commandList[indexInList]==NULL)
    {
        s_commandList[indexInList] = new New();
    }

    s_commandList[indexInList]->setParams(str.substr(index+1,str.size()-index+1));
    return s_commandList[indexInList];
}
#endif //UNTITLED_CMDFACTORY_H
