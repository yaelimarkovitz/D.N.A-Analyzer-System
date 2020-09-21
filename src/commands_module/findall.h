//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_FindALL_H
#define UNTITLED_FindALL_H
class FindAll:public ICommand{
public:
    ~FindAllAll(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_numOfParams = 3;
    static const int    s_numofSeq1 = 1;
    static const int    s_numOfSeq2 = 2;

    std::string             cutSign(const std::string& name);
    std::string             convertToName(const std::string &seq);
    bool                    isSign(const std::string&);
    std::string             FindAllExpresion(const std::string& seq1,const std::string& exp);
    std::string             FindAllSeq(const std::string& seq1,const std::string& seq2);
};

inline std::string FindAll::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        return "sorry,but you enter too little params";

    std::string seq1 = convertToName(params[s_numofSeq1]);

    if (!isSign(params[s_numOfSeq2]))
        return FindAllExpresion (seq1, params[s_numOfSeq2]);

    return FindAllSeq (seq1, params[s_numOfSeq2]);
}

inline std::string FindAll::FindAllExpresion(const std::string &seq1, const std::string &exp)
{
    return NameGeneration<FindAll>::itoa(DnaDataBase::FindAllDna(seq1)->getDna().FindAll(exp));
}

inline std::string FindAll::FindAllSeq(const std::string &seq1, const std::string &seq2)
{
    std::string name2 = convertToName(seq2);
    return NameGeneration<FindAll>::itoa(DnaDataBase::FindAllDna(seq1)->getDna().FindAll(DnaDataBase::FindAllDna(name2)->getDna()));
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
        return DnaDataBase::FindAllNameById(id);
    }
    return cutSign(seq);
}

inline bool FindAll::isSign(const std::string & seq) {
    return seq[0]==s_idSign || seq[0] == s_nameSign;
}
#endif //UNTITLED_FindAllALL_H
