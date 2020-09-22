//
// Created by mby on 22/09/2020.
//

#ifndef UNTITLED_SHOW_H
#define UNTITLED_SHOW_H

#include "../conrollers/ICommand.h"

class Show : public ICommand{
public:
    ~Show(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int  s_nunOfParams = 2;

    std::string     convertToName(const std::string &seq);
    std::string     cutSign(const std::string& name);
};

inline std::string Show::execute(std::vector<std::string> params)//todo add param of num of characters
{
    if (params.size() < s_nunOfParams)
        throw TooLittleParams();

    std::string name = convertToName(params[1]);
    return DnaDataBase::findDna(name)->getInfoWithStatus();
}

inline std::string Show::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Show::convertToName(const std::string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}
#endif //UNTITLED_SHOW_H
