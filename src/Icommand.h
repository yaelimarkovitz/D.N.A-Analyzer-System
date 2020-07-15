//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMAND_H
#define UNTITLED_ICOMMAND_H

#include <string>

class Icommand{
public:
    virtual const std::string& execute()=0;
    virtual void setParams(std::string str)=0;
};

#endif //UNTITLED_ICOMMAND_H