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
    static const int    s_indexOfNewName = 5;

    std::string     cutSign(const std::string& name);
    std::string     getName(std::vector<std::string>);
    std::string     provideNewSeq(std::vector<std::string> params,int s_ind,int e_ind);
    std::string     changeCurrSeq(std::vector<std::string> params,int s_ind,int e_ind);
    bool            isProvideNewSeq(int size);
};

inline std::string Slice::execute(std::vector<std::string> params)
{
    if (params.size() < s_minNumOfParams)
        return "sorry,but you enter too little params";

    int startIndex = atoi(params[s_indexOfStart].c_str());
    int endIndex = atoi(params[s_indexOfStart+1].c_str());

    if (isProvideNewSeq(params.size()))
        return provideNewSeq(params,startIndex,endIndex);
    return changeCurrSeq(params,startIndex,endIndex);

}
inline std::string Slice::provideNewSeq(std::vector<std::string> params, int s_ind, int e_ind)
{
    DnaInfo * newSeq;
    if (params[s_indexOfName][0] == s_nameSign)
    {
        newSeq = new DnaInfo( DnaDataBase::findDna(cutSign(params[s_indexOfName]))->getDna().slice(s_ind,e_ind)
                ,getName(params));//todo check if null returned
    }
    else
    {
        newSeq = new DnaInfo( DnaDataBase::findDna(atoi(cutSign(params[s_indexOfName]).c_str()))->getDna().slice(s_ind,e_ind),
                              getName(params));//todo generate name also if provided id
    }


    DnaDataBase::setNewDna(newSeq);
    return newSeq->getInfo();
}

inline std::string Slice::changeCurrSeq(std::vector<std::string> params, int s_ind, int e_ind) {
    return "hi";
}
inline std::string Slice::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Slice::getName(std::vector<std::string> params) {

    if (params[s_indexOfNewName] == "@@" )
    {
        return NameGeneration<Slice>::create(cutSign(params[s_indexOfName])+"_s");
    }
    return cutSign(params[s_indexOfNewName]);

}

inline bool Slice::isProvideNewSeq(int size) {
    return size > s_minNumOfParams;
}
#endif //UNTITLED_SLICE_H
