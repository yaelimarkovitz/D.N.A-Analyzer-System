//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_NEW_CMD_H
#define UNTITLED_NEW_CMD_H

#include <sstream>
#include <string>
#include "../Icommand.h"
#include "../dna_info.h"
#include "../dna_data_base.h"

class New :public ICommand{

public:
    ~New();
    std::string execute(std::vector<std::string> params);

private:
    DnaInfo* m_seq;
    std::string  generateName();
};

inline New::~New() {
    delete m_seq;
}

inline std::string New::execute(std::vector<std::string> params)
{
    size_t numOfParams = params.size();
    if(numOfParams>3 || numOfParams<2){
        return "no valid input";
    }
    if(m_seq!=NULL){
        delete m_seq;
    }
    if(params.size()==3){
        m_seq = new DnaInfo(params[1],params[2].substr(1,params[2].size()-1));
    }
    else{
        std::string name = generateName();
        m_seq = new DnaInfo(params[1],name);
    }
//    DnaDataBase::setNewDna(m_seq);
    return m_seq->getInfo();

}

inline std::string New::generateName() {
    int flag = 0;
    int num = 1;
    std::ostringstream ss ;
    while (flag == 0){
        ss << num;
        std::cout<<"seq"+ss.str()<<std::endl;
        if(!DnaDataBase::findByName("seq"+ ss.str())){
            break;
        }
        num++;
        std::ostringstream ss;
    }
    ss << num;
    return ("seq"+ss.str());
}


#endif //UNTITLED_NEW_CMD_H
