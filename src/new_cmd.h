//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_NEW_CMD_H
#define UNTITLED_NEW_CMD_H

#include "Icommand.h"
#include "dna_info.h"

class New :public Icommand{

public:
    const std::string& execute();
    void setParams(std::string str);

private:
    DnaInfo* seq;
};

inline const std::string& New::execute()
{
    std::cout<<"execute new command"<<std::endl;
}

inline void New::setParams(std::string str) {
    std::cout<<"set new params "<<str<<std::endl;

}

#endif //UNTITLED_NEW_CMD_H
