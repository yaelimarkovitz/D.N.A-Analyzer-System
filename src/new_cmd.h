//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_NEW_CMD_H
#define UNTITLED_NEW_CMD_H

#include "Icommand.h"
#include "dna_info.h"

class New :public Icommand{

public:
    std::string execute(std::vector<std::string> params);

private:
    DnaInfo* seq;
};

inline std::string New::execute(std::vector<std::string> params)
{
    std::cout<<"the params: "<<params[1]<<" "<<params[2]<<std::endl;
    return "new execute";
}


#endif //UNTITLED_NEW_CMD_H
