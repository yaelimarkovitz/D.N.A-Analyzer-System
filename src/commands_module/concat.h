//
// Created by mby on 23/09/2020.
//

#ifndef UNTITLED_CONCAT_H
#define UNTITLED_CONCAT_H

#include "../controllers/ICommand.h"

class Concat :public ICommand{
public:
    ~Concat(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int  s_minNunOfParams = 3;
    static const int  s_index0fFirstSeq = 1;

    std::string     cutSign(const std::string& name);
    std::string     convertToName(const std::string &seq);
    std::string     provideNewSeq(const std::vector<std::string> &params);
    std::string     changeCurrSeq(const std::vector<std::string> &params);
    std::string     getName(const std::vector<std::string>& params);
    bool            isProvideNewSeq(const std::vector<std::string> &params);

    SharedPointer<DnaSequence> concatAllSeqs(const std::vector<std::string> &params, int size);
};

inline std::string Concat::execute(std::vector <std::string> params)
{
    if (params.size() < s_minNunOfParams)
        throw TooLittleParams();

    if (isProvideNewSeq(params))
        return provideNewSeq(params);

    return changeCurrSeq(params);
}

inline std::string Concat::provideNewSeq(const std::vector<std::string> &params)
{

    SharedPointer<DnaSequence> conSeq = concatAllSeqs(params,params.size()-3);

    DnaInfo* newSeq = new DnaInfo(**conSeq,getName(params)) ;
    DnaDataBase::setNewDna(newSeq);

    return newSeq->getInfo();
}

inline std::string Concat::changeCurrSeq(const std::vector<std::string> &params)
{
    SharedPointer<DnaSequence> conSeq = concatAllSeqs(params,params.size()-1);

    DnaInfo * changeSeq = DnaDataBase::findDna(convertToName(params[s_index0fFirstSeq]));
    DnaDataBase::updateDna(convertToName(params[s_index0fFirstSeq]),**conSeq );

    return changeSeq->getInfo();
}

inline std::string Concat::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Concat::getName(const std::vector<std::string>& params)
{

    if (params.back() == "@@" ) //todo change hard code
    {
        if(params.size()-3 == 2)
        {
            std::string name;
            for (int i = s_index0fFirstSeq; i < params.size()-2; ++i)
            {
                name += convertToName(params[i]);
                name += "_";
            }
            return name;
        }
        return NameGeneration<Concat>::create("conseq_");
    }
    return cutSign(params.back());

}

inline bool Concat::isProvideNewSeq(const std::vector<std::string> &params) {
    int size = params.size();
    return params[size-2] == ":"; //todo change hard code
}

inline std::string Concat::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}

inline SharedPointer<DnaSequence> Concat::concatAllSeqs(const std::vector<std::string> &params, int size)
{
    DnaSequence tmp = DnaDataBase::findDna(convertToName(params[s_index0fFirstSeq]))->getDna();
    SharedPointer<DnaSequence> newSeq (new DnaSequence(tmp));

    for (int i = s_index0fFirstSeq; i < size; ++i)
    {
        tmp = DnaDataBase::findDna(convertToName(params[i+1]))->getDna();
        *(*newSeq) += tmp;
    }
    return newSeq;
}
#endif //UNTITLED_CONCAT_H
