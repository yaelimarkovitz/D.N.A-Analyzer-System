//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_SLICE_H
#define UNTITLED_SLICE_H
#include <cstdlib>

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
    std::string     getName(const std::vector<std::string>&,const std::string&);
    std::string     convertToName(const string &seq);
    std::string     provideNewSeq(std::vector<std::string> params, const DnaSequence &sliceSeq, const std::string &name);
    std::string     changeCurrSeq(const DnaSequence &sliceSeq, DnaInfo *currSeq);
    bool            isProvideNewSeq(int size);
};

inline std::string Slice::execute(std::vector<std::string> params)
{
    if (params.size() < s_minNumOfParams)
        return "sorry,but you enter too little params";

    int startIndex = atoi( params[s_indexOfStart].c_str() );
    int endIndex = atoi( params[s_indexOfStart+1].c_str() );

    std::string name = convertToName( params[s_indexOfName]);

    DnaInfo* currSeq = DnaDataBase::findDna(name);
    DnaSequence sliceSeq = currSeq->getDna().slice(startIndex,endIndex);

    if (isProvideNewSeq(params.size()))
        return provideNewSeq(params, sliceSeq, name);

    return changeCurrSeq(sliceSeq, currSeq);

}

inline std::string
Slice::provideNewSeq(std::vector<std::string> params, const DnaSequence &sliceSeq, const std::string &name)
{

    DnaInfo * newSeq = new DnaInfo(sliceSeq,getName(params,name));
    DnaDataBase::setNewDna(newSeq);
    return newSeq->getInfo();
}

inline std::string Slice::changeCurrSeq(const DnaSequence &sliceSeq, DnaInfo *currSeq)
{
    currSeq->updateDna(sliceSeq);
    currSeq->setStatus(E_MODIFIED);
    return currSeq->getInfo();
}

inline std::string Slice::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Slice::getName(const std::vector<std::string>& params,const std::string& name) {

    if (params[s_indexOfNewName] == "@@" )
    {
        return NameGeneration<Slice>::create(name+"_s");
    }
    return cutSign(params[s_indexOfNewName]);

}

inline bool Slice::isProvideNewSeq(int size) {
    return size > s_minNumOfParams;
}

inline std::string Slice::convertToName(const string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}
#endif //UNTITLED_SLICE_H
