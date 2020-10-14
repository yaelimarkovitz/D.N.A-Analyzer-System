//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMAND_H
#define UNTITLED_ICOMMAND_H

#include <string>
#include <vector>
#include "../model/commands_module/name_genaration.h"
#include "../model/dna_module/dna_data_base.h"
#include "../myTools/too_little_params_exception.h"


struct ICommand{

    virtual ~ICommand(){};
    virtual std::string execute(std::vector<std::string> params)=0;
    static const char   s_nameSign = '@';
    static const char   s_idSign = '#';
//    static std::Sring   s_defultNameSign = '@@';

};

#endif //UNTITLED_ICOMMAND_H