//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_CMDFACTORY_H
#define UNTITLED_CMDFACTORY_H

#include <string>
#include <vector>
#include <map>
#include "./commands/new_cmd.h"
class CmdFactory {

public:
    static ICommand* createCommand(const std::string& str);

private:
    static const size_t NUM_OF_COMMANDS = 3 ;
    static std::vector<ICommand*> s_commandList;
    static std::map<std::string, size_t> s_mapNameToNum;
};

inline ICommand* CmdFactory::createCommand(const std::string &str) {

    size_t indexInList = s_mapNameToNum.find(str)->second;

    /*check if this is the first use of this command*/
    if (s_commandList[indexInList]==NULL)
    {
        s_commandList[indexInList] = new New();
    }

    return s_commandList[indexInList];
}
#endif //UNTITLED_CMDFACTORY_H
