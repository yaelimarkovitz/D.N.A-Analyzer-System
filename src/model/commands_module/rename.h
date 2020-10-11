//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_RENAME_H
#define UNTITLED_RENAME_H

#include "../controllers/ICommand.h"
class Rename : public ICommand{
public:
    ~Rename(){};
    /*virtual*/std::string execute(std::vector<std::string> params);
private:
    static const int    s_numOfParams = 3;
    static const int    s_indexOfName = 1;
    static const int    s_indexOfNewName = 2;

    std::string             cutSign(const std::string& name);
    std::string             convertToName(const std::string &seq);
};

inline std::string Rename::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        throw TooLittleParams();

    std::string name = convertToName(params[s_indexOfName]);
    DnaDataBase::updateName(name,cutSign(params[s_indexOfNewName]));

    return "None";
}

inline std::string Rename::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Rename::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}
#endif //UNTITLED_RENAME_H

