//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_DUP_H
#define UNTITLED_DUP_H

#include "../conrollers/ICommand.h"

class Dup : public ICommand {
public:

    ~Dup(){};
    /*virtual*/std::string execute(std::vector<std::string> params){ return "hi";}

private:

};


#endif //UNTITLED_DUP_H
