#include "command_collection.h"
//
// Created by mby on 17/09/2020.
//

std::map<std::string ,SharedPointer<ICommand> > CommandCollection::m_commandList = initMap();

