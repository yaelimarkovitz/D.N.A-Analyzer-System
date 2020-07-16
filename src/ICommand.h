//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMAND_H
#define UNTITLED_ICOMMAND_H

#include <string>
#include <vector>

class ICommand{
public:
    virtual ~ICommand(){};
    virtual std::string execute(std::vector<std::string> params)=0;
};

#endif //UNTITLED_ICOMMAND_H