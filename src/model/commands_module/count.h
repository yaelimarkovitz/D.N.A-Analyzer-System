//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_COUNT_H
#define UNTITLED_COUNT_H

#include "../controllers/ICommand.h"

class Count: public ICommand{
public:
    ~Count(){};
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
};

inline std::string Count::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        throw TooLittleParams();

    std::string seq1 = convertToName(params[s_numofSeq1]);

    if (!isSign(params[s_numOfSeq2]))
        return findExpresion (seq1, params[s_numOfSeq2]);

    return findSeq (seq1, params[s_numOfSeq2]);
}

inline std::string Count::findExpresion(const std::string &seq1, const std::string &exp)
{
    return NameGeneration<Count>::itoa(DnaDataBase::findDna(seq1)->getDna().count(exp));
}

inline std::string Count::findSeq(const std::string &seq1, const std::string &seq2)
{
    std::string name2 = convertToName(seq2);
    return NameGeneration<Count>::itoa(DnaDataBase::findDna(seq1)->getDna().count(DnaDataBase::findDna(name2)->getDna()));
}

inline std::string Count::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Count::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}

inline bool Count::isSign(const std::string & seq) {
    return seq[0]==s_idSign || seq[0] == s_nameSign;
}


#endif //UNTITLED_COUNT_H
