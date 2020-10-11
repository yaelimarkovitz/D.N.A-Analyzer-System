//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_NEW_CMD_H
#define UNTITLED_NEW_CMD_H

#include <sstream>
#include "../controllers/ICommand.h"
#include "../dna_module/dna_info.h"
#include "../dna_module/dna_data_base.h"

class New :public ICommand{

public:

    ~New();
    /*virtual*/std::string execute(std::vector<std::string> params);

private:

    static const int    s_minNumOfParams = 2;
    static const int    s_indexOfName = 2;
    std::string         cutAt(const std::string& name);
};

inline New::~New()
{

}

inline std::string New::execute(std::vector<std::string> params)
{
    if  (params.size() < s_minNumOfParams)
        throw TooLittleParams();

    DnaInfo* seq;

    if(params.size()==s_minNumOfParams)
    {
        std::string name = NameGeneration<New>::create("seq");
        seq = new DnaInfo(params[1],name);
    }
    else
        seq = new DnaInfo(params[1],cutAt(params[s_indexOfName]));

    DnaDataBase::setNewDna(seq);
    return seq->getInfo();

}

inline std::string New::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}
#endif //UNTITLED_NEW_CMD_H
