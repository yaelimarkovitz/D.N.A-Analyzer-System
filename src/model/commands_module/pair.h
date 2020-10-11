//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_PAIR_H
#define UNTITLED_PAIR_H
#include "../controllers/ICommand.h"

class Pair :public ICommand{
public:
    ~Pair(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_nunOfParams = 4;
    static const int    s_indexOfSeq = 1;
    static const int    s_indexOfNewName = 3;

    std::string     convertToName(const std::string &seq);
    std::string     cutSign(const std::string& name);
};

inline std::string Pair::execute(std::vector<std::string> params)
{
    if (params.size() < s_nunOfParams)
        throw TooLittleParams();

    std::string name = convertToName(params[s_indexOfSeq]);
    DnaSequence pairSeq = DnaDataBase::findDna(name)->getDna().pair();
    DnaInfo * newSeq;
    if (params[s_indexOfNewName]=="@@")
    {
        newSeq = new DnaInfo(pairSeq,NameGeneration<Pair>::create(name+"_p"));
    }
    else
    {
        newSeq = new DnaInfo(pairSeq,cutSign(params[s_indexOfNewName]));
    }
    DnaDataBase::setNewDna(newSeq);
    return newSeq->getInfo();
}

inline std::string Pair::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Pair::convertToName(const string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}
#endif //UNTITLED_PAIR_H
