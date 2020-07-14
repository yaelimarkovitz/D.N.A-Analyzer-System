//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_CMDFACTORY_H
#define UNTITLED_CMDFACTORY_H

#include <string>
#include "new_cmd.h"
typedef enum commands{
    NEW,
    LOAD,
    SAVE
}commands;
class CmdFactory {
public:
    static Icommand* createCommand(const std::string& str);
private:

    static Icommand** command_list;
    static commands cmd;
};

inline Icommand* CmdFactory::createCommand(const std::string &str) {
    return new New();
}
#endif //UNTITLED_CMDFACTORY_H
