//
// Created by mby on 14/07/2020.
//

#include "cmd_factory.h"
std::map<std::string, size_t> CmdFactory::s_mapNameToNum = {{"new",0},{"save",1},{"load",2}} ;
std::vector<ICommand*> CmdFactory::s_commandList (NUM_OF_COMMANDS,NULL);