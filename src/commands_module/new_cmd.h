//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_NEW_CMD_H
#define UNTITLED_NEW_CMD_H

#include <sstream>
#include "../conrollers/ICommand.h"
#include "../dna_module/dna_info.h"
#include "../dna_module/dna_data_base.h"

class New :public ICommand{

public:

    ~New();
    /*virtual*/std::string execute(std::vector<std::string> params);

private:

    DnaInfo*            m_seq;
    static const int    s_numOfParams = 2;

    std::string  generateName();
    std::string itoa(int num);
};

inline New::~New()
{
    delete m_seq;
}

inline std::string New::execute(std::vector<std::string> params)
{
    if  (params.size() < s_numOfParams)
        throw std::runtime_error("not enogh params");

    if(m_seq!=NULL)
        delete m_seq;

    if(params.size()==3){

        m_seq = new DnaInfo(params[1],params[2].substr(1,params[2].size()-1));
    }
    else{
        std::string name = generateName();
        m_seq = new DnaInfo(params[1],name);
    }
    DnaDataBase::setNewDna(m_seq);
    return m_seq->getInfo();

}

inline std::string New::generateName()
{
    static size_t number = 0;
    number++;
    return ("seq"+itoa(number));
}

inline std::string New::itoa(int num)
{
    std::string ss = "";
    while(num)
    {
        int x = num % 10;
        num /= 10;
        char i = '0';
        i = i + x ;
        ss = i + ss;
    }
    return ss;
}


#endif //UNTITLED_NEW_CMD_H
