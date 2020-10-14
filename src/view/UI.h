//
// Created by mby on 17/09/2020.
//

#ifndef UNTITLED_UI_H
#define UNTITLED_UI_H

#include <vector>
#include "../myTools/callback.h"

struct UI{
    typedef std::string (*callBack)(const std::string&,std::vector<std::string>);
    virtual ~UI(){};
    virtual void run (callBack c) = 0;
};
#endif //UNTITLED_UI_H
