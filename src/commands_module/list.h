//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include "../controllers/ICommand.h"

class List :public ICommand{
public:
    ~List(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int  s_nunOfParams = 1;
    void              addSign(std::string &ret, const int& status);
};

inline std::string List::execute(std::vector<std::string> params)
{
    if (params.size() < s_nunOfParams)
        throw TooLittleParams();

    std::vector<DnaInfo*> list = DnaDataBase::getAllDna();
    std::string ret = "";
    for (int i = 0; i < list.size(); ++i)
    {
        addSign(ret,list[i]->getStatus());
        ret += list[i]->getInfo();
        ret += '\n';
    }

    return ret;
}

inline void List::addSign(std::string &ret, const int &status)
{
    switch (status){
        case E_NEW : ret+= "- ";
            break;
        case E_MODIFIED : ret+= "* ";
            break;
        case E_UP_TO_DATE: ret+= "^ ";
            break;
    }
}
#endif //UNTITLED_LIST_H
