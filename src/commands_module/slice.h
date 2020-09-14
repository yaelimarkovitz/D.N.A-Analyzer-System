//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_SLICE_H
#define UNTITLED_SLICE_H

#include "../conrollers/ICommand.h"
#include "../dna_module/dna_data_base.h"

class Slice :public ICommand{
public:
    ~Slice(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_minNumOfParams = 4;
    static const int    s_indexOfName = 1;
    static const int    s_indexOfStart = 2;
    static const int    s_indexOfNewName = 4;

    std::string     cutAt(const std::string& name);
};

inline std::string Slice::execute(std::vector<std::string> params)
{
    if (params.size() < s_minNumOfParams)
        return "sorry,but you enter too little params";

    int startIndex = 0;//todo change this to real ones to check what happens with load
    int endIndex = 2;
    DnaSequence seq (DnaDataBase::findByName((params[s_indexOfName]))->getDna().slice(startIndex,endIndex));
    std::string name;
    if (params.size() == s_minNumOfParams)
    {
        name = NameGeneration<Slice>::create(params[s_indexOfName]);
    }
    else
        name = cutAt(params[s_indexOfNewName]);
    DnaInfo * new_seq = new DnaInfo(seq,name);
    DnaDataBase::setNewDna(new_seq);

    return new_seq->getInfo();
}


inline std::string Slice::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}


#endif //UNTITLED_SLICE_H
