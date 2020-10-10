//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_SAVE_H
#define UNTITLED_SAVE_H

#include "../dna_module/dna_data_base.h"
#include "../controllers/ICommand.h"
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
    std::string         convertToName(const string &seq);
    std::string         m_fileName;
};

inline std::string Save::execute(std::vector<std::string> params)
{
    if (params.size() < s_minNumOfParams)
        throw TooLittleParams();

    std::string name = convertToName(params[s_indexOfDnaSeq]);

    if (params.size() == 3)
    {
        m_fileName = params[s_indexOfFileName];
    }
    else
    {
        m_fileName  = NameGeneration<Save>::create(name)+".rowdna";
    }

    IWriter * writer = new FileWriter(m_fileName);
    DnaInfo * dnaSeq = DnaDataBase::findDna(name);

    dnaSeq->getDna().output(writer);
    dnaSeq->setStatus(E_UP_TO_DATE);

    return "None";
}

inline std::string Save::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline  std::string  Save::convertToName(const string &seq)
{
    if (seq[0]==s_idSign)
    {
        int id = atoi(cutSign(seq).c_str());
        return DnaDataBase::findNameById(id);
    }
    return cutSign(seq);
}
#endif //UNTITLED_SAVE_H
