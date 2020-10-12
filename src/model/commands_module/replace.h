//
// Created by mby on 11/10/2020.
//

#ifndef UNTITLED_REPLACE_H
#define UNTITLED_REPLACE_H

#include "../controllers/ICommand.h"
#include "../dna_module/dna_data_base.h"

class Replace :public ICommand{
public:
    ~Replace() override{};
    /*virtual*/std::string execute(std::vector<std::string> params) override;

private:
    static const int    s_minNumOfParams = 4;
    static const int    s_indexOfSeq = 1;

    std::string     cutSign(const std::string& name);
    std::string     convertToName(const std::string &seq);
    std::string     provideNewSeq(const std::vector<std::string> &params);
    std::string     changeCurrSeq(const std::vector<std::string> &params);
    std::string     getName(const std::vector<std::string>& params);
    bool            isProvideNewSeq(const std::vector<std::string> &params);

    SharedPointer<DnaSequence> concatAllSeqs(const std::vector<std::string> &params, int size);
};

inline  std::string Replace::execute(std::vector<std::string> params) 
{
    if (params.size()< s_minNumOfParams)
        throw TooLittleParams();

    if(isProvideNewSeq(params))
    {
        return provideNewSeq(params);
    }
    return changeCurrSeq(params);
}

inline std::string Replace::changeCurrSeq(const std::vector<std::string> &params)
{
    DnaInfo* currSeq = DnaDataBase::findDna(convertToName(params[s_indexOfSeq]));
    DnaSequence seq = currSeq->getDna();

    for (int i = s_indexOfSeq+1; i < params.size(); i+=2)
    {
        seq.replace(atoi(params[i].c_str()),params[i+1][0]);
    }
    currSeq->updateDna(seq);
    return currSeq->getInfo();
}

inline std::string Replace::provideNewSeq(const std::vector<std::string> &params)
{
    DnaInfo* currSeq = DnaDataBase::findDna(convertToName(params[s_indexOfSeq]));
    DnaSequence seq = currSeq->getDna();

    for (int i = s_indexOfSeq+1; i < params.size()-2; i+=2)
    {
        seq.replace(atoi(params[i].c_str()),params[i+1][0]);
    }

    std::string newName = getName(params);
    DnaDataBase::setNewDna(new DnaInfo(seq,newName));
    return DnaDataBase::findDna(newName)->getInfo();
}

inline bool Replace::isProvideNewSeq(const std::vector<std::string> &params) {
    int size = params.size();
    return params[size-2] == ":";
}

inline std::string Replace::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}

inline std::string Replace::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Replace::getName(const std::vector<std::string>& params) {

    if (params.back() == "@@" )
    {
        return NameGeneration<Replace>::create(convertToName(params[s_indexOfSeq])+"_r");
    }
    return cutSign(params.back());

}
#endif //UNTITLED_REPLACE_H
