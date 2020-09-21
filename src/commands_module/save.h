//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_SAVE_H
#define UNTITLED_SAVE_H

#include "../dna_module/dna_data_base.h"
#include "../conrollers/ICommand.h"
#include "../myTools/writers/file_writer.h"
#include <iostream>
#include <cstdlib>

class Save : public ICommand {

public:

    ~Save(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_minNumOfParams = 2;
    static const int    s_indexOfFileName = 2;
    static const int    s_indexOfDnaSeq = 1;
    std::string         cutSign(const std::string& name);
    const string &      convertToName(const int& id);
    std::string         m_fileName;
};

inline std::string Save::execute(std::vector<std::string> params)
{

    if (params.size() < s_minNumOfParams)
        return "sorry, but you enter too little params";

    std::string name;
    if (params[s_indexOfDnaSeq][0] == s_idSign)
    {
        name = convertToName(atoi(cutSign(params[s_indexOfDnaSeq]).c_str()));

    }
    else
    {
        name = cutSign(params[s_indexOfDnaSeq]);
    }
    if (params.size() == 3)
    {
        m_fileName = params[s_indexOfFileName];
    }
    else
        m_fileName  = NameGeneration<Save>::create(name)+".rowdna";

    IWriter * writer = new FileWriter(m_fileName);
    DnaInfo * dnaSeq = DnaDataBase::findDna(name);

    if (dnaSeq == NULL)
    {
        return "sorry , this dna doesnt exists";
    }
    dnaSeq->getDna().output(writer);

    return "None";
}

inline std::string Save::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline const string & Save::convertToName(const int &id)
{
    return DnaDataBase::findNameById(id);
}
#endif //UNTITLED_SAVE_H
