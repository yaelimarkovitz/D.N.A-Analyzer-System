//
// Created by mby on 12/10/2020.
//

#ifndef UNTITLED_DEL_H
#define UNTITLED_DEL_H

#include "../controllers/ICommand.h"

class Del : public ICommand
{
public:

    ~Del(){};
    std::string execute(std::vector<std::string> params);

private:

    static const int s_numOfParams = 2;
    static const int s_indexOfSeq = 1;

    std::string     cutSign(const std::string& name);
    std::string     convertToName(const std::string &seq);
};

inline std::string Del::execute(std::vector<std::string> params)
{
    if (params.size() < s_numOfParams)
        throw TooLittleParams();

    DnaInfo* currSeq = DnaDataBase::findDna(convertToName(params[s_indexOfSeq]));

    return "confirm + Do you want to delete"+ currSeq->getInfo() + "\n Please confirm by y/Y or cancel by n/N";


}

inline std::string Del::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Del::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}


#endif //UNTITLED_DEL_H
