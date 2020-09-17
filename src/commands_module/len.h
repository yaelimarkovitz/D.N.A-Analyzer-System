//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_LEN_H
#define UNTITLED_LEN_H

#include <cstdlib>
#include <cstdio>

#include "../conrollers/ICommand.h"


class Len : public ICommand{
public :
    ~Len(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_indexOfParmas = 2;
    std::string         cutSign(const std::string& name);
};

inline std::string Len::execute(std::vector<std::string> params)
{

    if (params.size() < s_indexOfParmas)
        return "sorry, but you enter too little params";


    if (params[1][0] != s_idSign)
        return "sorry, but you have to enter dna id with #,please try again";

    size_t id = atoi(cutSign(params[1]).c_str());
    DnaInfo* seqToAnalyze = DnaDataBase::findDna(id);

    if (seqToAnalyze ==NULL)
        return "sorry, but this dna sequence doesn't exists please enter another dna";

    return NameGeneration<Len>::itoa (seqToAnalyze->getDna().length());
}

inline std::string Len::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}
#endif //UNTITLED_LEN_H
