//
// Created by mby on 15/09/2020.
//

#ifndef UNTITLED_FIND_H
#define UNTITLED_FIND_H

#include "../controllers/ICommand.h"

class Find: public ICommand{
public:
    ~Find(){};
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

inline std::string Find::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        throw TooLittleParams();

    std::string seq1 = convertToName(params[s_numofSeq1]);

    if (!isSign(params[s_numOfSeq2]))
        return findExpresion (seq1, params[s_numOfSeq2]);

    return findSeq (seq1, params[s_numOfSeq2]);
}

inline std::string Find::findExpresion(const std::string &seq1, const std::string &exp)
{
    return NameGeneration<Find>::itoa(DnaDataBase::findDna(seq1)->getDna().find(exp));
}

inline std::string Find::findSeq(const std::string &seq1, const std::string &seq2)
{
    std::string name2 = convertToName(seq2);
    return NameGeneration<Find>::itoa(DnaDataBase::findDna(seq1)->getDna().find(DnaDataBase::findDna(name2)->getDna()));
}

inline std::string Find::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Find::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}

inline bool Find::isSign(const std::string & seq) {
    return seq[0]==s_idSign || seq[0] == s_nameSign;
}
#endif //UNTITLED_FIND_H
