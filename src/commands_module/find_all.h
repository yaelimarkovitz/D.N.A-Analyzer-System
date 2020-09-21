//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_FIND_ALL_H
#define UNTITLED_FIND_ALL_H

#include "../conrollers/ICommand.h"

class FindAll: public ICommand{
public:
    ~FindAll(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_numOfParams = 3;
    static const int    s_numofSeq1 = 1;
    static const int    s_numOfSeq2 = 2;

    std::string             cutSign(const std::string& name);
    std::string             convertToName(const std::string &seq);
    bool                    isSign(const std::string&);
    std::string             findExpresion(const std::string& seq1,const std::string& exp);
    std::string             findSeq(const std::string& seq1,const std::string& seq2);
    std::string             convertVecToStr(const std::vector<int>& vec);
};

inline std::string FindAll::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        return "sorry,but you enter too little params";

    std::string seq1 = convertToName(params[s_numofSeq1]);

    if (!isSign(params[s_numOfSeq2]))
        return findExpresion (seq1, params[s_numOfSeq2]);

    return findSeq (seq1, params[s_numOfSeq2]);
}

inline std::string FindAll::findExpresion(const std::string &seq1, const std::string &exp)
{
    return convertVecToStr(DnaDataBase::findDna(seq1)->getDna().findAll(exp));//todo the findall function not work good
}

inline std::string FindAll::findSeq(const std::string &seq1, const std::string &seq2)
{
    std::string name2 = convertToName(seq2);
    return convertVecToStr(DnaDataBase::findDna(seq1)->getDna().findAll(DnaDataBase::findDna(name2)->getDna()));
}

inline std::string FindAll::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string FindAll::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}

inline bool FindAll::isSign(const std::string & seq) {
    return seq[0]==s_idSign || seq[0] == s_nameSign;
}

inline std::string FindAll::convertVecToStr(const std::vector<int> &vec)
{
    std::string ret = "";
    for (int i = 0; i < vec.size(); ++i) {
        ret += NameGeneration<FindAll>::itoa(vec[i]);
        ret+=" ";
    }
    return ret;
}
#endif //UNTITLED_FIND_ALL_H
