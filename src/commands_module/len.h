//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_LEN_H
#define UNTITLED_LEN_H

#include "../conrollers/ICommand.h"


class Len : public ICommand{
public :
    ~Len(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_indexOfParmas = 2;

};

inline std::string Len::execute(std::vector<std::string> params)
{
    if (params.size() < s_indexOfParmas)
        return "sorry, but you enter too little params";


    if (params[1][0] != s_idSign)
        return "sorry, but you have to enter dna id with #,please try again";

    size_t id = atoi(params[1].c_str());//todo send message if there is mistake

    return NameGeneration<Len>::itoa (DnaDataBase::findDna(id)->getDna().length());
}

#endif //UNTITLED_LEN_H
